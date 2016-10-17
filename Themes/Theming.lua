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
                Description,
                BackgroundColor,
                TextColor,
                MeterColor,
                BackdropColor)
    SKIN:Bang('!SetOption Preview_Description Text '..'"Description: '..Description..'"')
    SKIN:Bang('!SetOption Preview_Skin_Background SolidColor '..BackgroundColor)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundTL FontColor '..TextColor)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundBR FontColor '..TextColor)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundCC BarColor '..MeterColor)
    SKIN:Bang('!SetOption Preview_Skin_ForegroundCC SolidColor '..BackdropColor)
    SKIN:Bang('!UpdateMeterGroup Preview')
end

-- Applies the theme to every element
function Apply(
                BackgroundColor,
                TextColor,
                MeterColor,
                BackdropColor)
    SKIN:Bang('!WriteKeyValue Variables BackgroundColor '..BackgroundColor..' "#@#variables.var"')
    SKIN:Bang('!WriteKeyValue Variables TextColor '..TextColor..' "#@#variables.var"')
    SKIN:Bang('!WriteKeyValue Variables MeterColor '..MeterColor..' "#@#variables.var"')
    SKIN:Bang('!WriteKeyValue Variables BackdropColor '..BackdropColor..' "#@#variables.var"')
    SKIN:Bang('!RefreshApp')
end

-- Load all schemes from file
function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    local refreshGenerated = false
    local generated = ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
    if next(generated)==nil then refreshGenerated = true end

    -- load ini file
	local colorSchemes = ReadIni(SKIN:ReplaceVariables("#CURRENTPATH#")..'ColorSchemes.txt')

    -- Loads the template
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateButtonMeter.inc")
	
    -- loop through the different color schemes (themes) in the txt file
    local currentTheme = 0
    local currentLineLength = 0
    local content = {}
    for title,pair in pairs(colorSchemes) do
        currentTheme = currentTheme + 1
        if pair.Description == nil then pair.Description = "" end
        for _,value in ipairs(template) do
            local str = ""
            local st2 = ""
            -- Switch on the current line to change what needs to be changed
            if     value:find("Theme_")             then str = value:gsub("|",title)
                                                         if generated["Theme_"..title]==nil then refreshGenerated=true end
            elseif value:find("X=")                 then
                        currentLineLength = currentLineLength + 10*((pair.Name):len())
                        if currentTheme>1 and currentLineLength<760 then
                            str = value.."10R"
                            st2 = "Y=r"
                        else
                            currentLineLength = 30 + 10*((pair.Name):len())
                            str = value.."20"
                            st2 = "Y=10R"
                        end
            elseif value:find("SolidColor=")        then str = value..pair.BackgroundColor
            elseif value:find("FontColor=")         then str = value..pair.TextColor
            elseif value:find("Text=")              then str = value..pair.Name
            elseif value:find("MouseOverAction=")   then str = value..("\"('%s','%s','%s','%s','%s')\""):format(pair.Description,pair.BackgroundColor,pair.TextColor,pair.MeterColor,pair.BackdropColor)
            elseif value:find("LeftMouseUpAction=") then str = value..("\"('%s','%s','%s','%s')\""):format(pair.BackgroundColor,pair.TextColor,pair.MeterColor,pair.BackdropColor)
                                                         if (not refreshGenerated) and (generated["Theme_"..title]["LeftMouseUpAction"])~=str:sub(19) then refreshGenerated=true end
            else str = value end

            table.insert(content,str)
            if str:find("X=") then table.insert(content,st2) end
        end
        if not refreshGenerated then generated["Theme_"..title]=nil end
    end

    local generatedLeft = 0
    for k,v in pairs(generated) do
        generatedLeft = generatedLeft + 1
    end

    if (refreshGenerated) or (generatedLeft>0) then
        WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
        SKIN:Bang('!RefreshGroup Configuration')
    end

    SKIN:Bang('!Updategroup Preview')
end
