------- Metadata --------------------------------------------------------------
-- Theming
-- Author: Lucky Penny
-- Description: Methods to simply the process of updating the preview of a
--              theme and applying it to the whole skin.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Preview(..) - Apply(..): As described.
-- Initialize(): Generates the meters based on to the list of available themes. 
-------------------------------------------------------------------------------


-- Allows for preview of the theme
function Preview(
                BackgroundColor,
                ForegroundColor,
                ForegroundColorDimLight,
                ForegroundColorDimMin)
    SKIN:Bang('!SetOption Preview_Skin_Background SolidColor '..BackgroundColor)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundTL FontColor '..ForegroundColor)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundBR FontColor '..ForegroundColor)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundCC BarColor '..ForegroundColorDimLight)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundCC SolidColor '..ForegroundColorDimMin)
    SKIN:Bang('!UpdateMeterGroup Preview')
end

-- Applies the theme to every element
function Apply(
                BackgroundColor,
                ForegroundColor,
                ForegroundColorDimLight,
                ForegroundColorDimMin)
    SKIN:Bang('!WriteKeyValue Variables BackgroundColor '..BackgroundColor..' "#@#variables.var"')
    SKIN:Bang('!WriteKeyValue Variables ForegroundColor '..ForegroundColor..' "#@#variables.var"')
    SKIN:Bang('!WriteKeyValue Variables ForegroundColorDimLight '..ForegroundColorDimLight..' "#@#variables.var"')
    SKIN:Bang('!WriteKeyValue Variables ForegroundColorDimMin '..ForegroundColorDimMin..' "#@#variables.var"')
    SKIN:Bang('!RefreshApp')
end

-- Load all schemes from file
function Initialize()
    -- Loads the Read and Write methods for ini files
    dofile(SKIN:ReplaceVariables("#@#").."File.lua")

    -- load ini file
	local file = assert(io.open(SKIN:ReplaceVariables("#CURRENTPATH#")..'ColorSchemes.txt','r'), 'Unable to open ColorSchemes.txt')
	local iniFile = ReadIni(SKIN:ReplaceVariables("#CURRENTPATH#")..'ColorSchemes.txt')
	
    -- generate the buttons for previewing and applying the theme
    local doRefresh = false

    -- loop through the different color schemes (themes) in the txt file
    local currentTheme = 0
    local currentLineLength = 0
    local generated = {}
    for title,pair in pairs(iniFile) do
        currentTheme = currentTheme + 1

        local addition = {}
        addition["Meter"]="String"
        addition["MeterStyle"]="TextStyle"
        addition["Padding"]="10,10,10,10"
        addition["FontSize"]=10

        currentLineLength = currentLineLength + 10*(string.len(pair.Name))
        if currentTheme>1 and currentLineLength<760 then
            addition["X"]="10R"
            addition["Y"]="r"
        else
            currentLineLength = 30 + 10*(string.len(pair.Name))
            addition["X"]="20"
            addition["Y"]="10R"
        end

        addition["SolidColor"]=pair.BackgroundColor
        addition["FontColor"]=pair.ForegroundColor
        addition["Text"]=pair.Name
        addition["MouseOverAction"]=("!CommandMeasure Theming \"Preview('%s','%s','%s','%s')\""):format(pair.BackgroundColor,pair.ForegroundColor,pair.ForegroundColorDimLight,pair.ForegroundColorDimMin)
        addition["LeftMouseUpAction"]=("!CommandMeasure Theming \"Apply('%s','%s','%s','%s')\""):format(pair.BackgroundColor,pair.ForegroundColor,pair.ForegroundColorDimLight,pair.ForegroundColorDimMin)

        generated[("Theme_%s"):format(title)] = addition
    end
    WriteIni(generated,SKIN:ReplaceVariables("#CURRENTPATH#").."generated.inc")

    if doRefresh then
        SKIN:Bang('!Refresh')
    end
    SKIN:Bang('!Updategroup Preview')
end
