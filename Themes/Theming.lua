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

    local refreshGenerated = false
    local testIfExist=io.open(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc","r")
    if testIfExist~=nil then
        io.close(testIfExist) generated = ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
        else refreshGenerated = true end

    -- load ini file
	local colorSchemes = ReadIni(SKIN:ReplaceVariables("#CURRENTPATH#")..'ColorSchemes.txt')

    -- Loads the template
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."ThemeButtonTemplate.inc")
	
    -- loop through the different color schemes (themes) in the txt file
    local currentTheme = 0
    local currentLineLength = 0
    local content = {}
    for title,pair in pairs(colorSchemes) do
        currentTheme = currentTheme + 1
        local valueY = ""
        for _,value in ipairs(template) do
            local str = ""
            -- Switch on the current line to change what needs to be changed
            if     string.find(value,"Theme_")             then str = string.gsub(value,"|",title)
            elseif string.find(value,"X=")                 then
                        currentLineLength = currentLineLength + 10*(string.len(pair.Name))
                        if currentTheme>1 and currentLineLength<760 then
                            str = value.."10R"
                            valueY="r"
                        else
                            currentLineLength = 30 + 10*(string.len(pair.Name))
                            str = value.."20"
                            valueY="10R"
                        end
            elseif string.find(value,"Y=")                 then str = value..valueY
            elseif string.find(value,"SolidColor=")        then str = value..pair.BackgroundColor
            elseif string.find(value,"FontColor=")         then str = value..pair.ForegroundColor
            elseif string.find(value,"Text=")              then str = value..pair.Name
            elseif string.find(value,"MouseOverAction=")   then str = value..("\"('%s','%s','%s','%s')\""):format(pair.BackgroundColor,pair.ForegroundColor,pair.ForegroundColorDimLight,pair.ForegroundColorDimMin)
            elseif string.find(value,"LeftMouseUpAction=") then str = value..("\"('%s','%s','%s','%s')\""):format(pair.BackgroundColor,pair.ForegroundColor,pair.ForegroundColorDimLight,pair.ForegroundColorDimMin)
            else str = value end

            table.insert(content,str)
        end
    end

    if refreshGenerated then
        WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
        SKIN:Bang('!RefreshGroup Configuration')
    end

    SKIN:Bang('!Updategroup Preview')
end
