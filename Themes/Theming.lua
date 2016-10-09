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
    -- load ini file
	local file = assert(io.open(SKIN:ReplaceVariables("#CURRENTPATH#")..'ColorSchemes.txt','r'), 'Unable to open ColorSchemes.txt')
	local iniFile, section = {}
	local num = 0
	for line in file:lines() do
		num = num + 1
		if not line:match('^%s-;') then
			local key, command = line:match('^([^=]+)=(.+)')
			if line:match('^%s-%[.+') then
				section = line:match('^%s-%[([^%]]+)'):lower()
				if not iniFile[section] then iniFile[section] = {} end
			elseif key and command and section then
				iniFile[section][key:lower():match('^s*(%S*)%s*$')] = command:match('^s*(.-)%s*$')
			elseif #line > 0 and section and not key or command then
				print(num .. ': Invalid property or value.')
			end
		end
	end
	if not section then print('No sections found in ColorSchemes.txt') end
	file:close()
	
    -- generate the buttons for previewing and applying the theme
    local doRefresh = false
    local testIfExist=io.open(SKIN:ReplaceVariables("#CURRENTPATH#")..'generated.inc',"r")
    if testIfExist~=nil then io.close(testIfExist) doRefresh = false else doRefresh = true end
    local generated = io.open(SKIN:ReplaceVariables("#CURRENTPATH#")..'generated.inc','w+')

    -- loop through the different color schemes (themes) in the txt file
    local currentTheme = 0
    local currentLineLength = 0
    for title,pair in pairs(iniFile) do
        currentTheme = currentTheme + 1
        generated:write(string.gsub("[Theme_#TITLE#]","#TITLE#",title),"\n")
        generated:write("Meter=String","\n")
        generated:write("MeterStyle=TextStyle","\n")
        generated:write("Padding=10,10,10,10","\n")
        generated:write("FontSize=10","\n")

        currentLineLength = currentLineLength + 10*(string.len(pair.name))
        if currentTheme>1 and currentLineLength<760 then
            generated:write("X=10R","\n")
            generated:write("Y=r","\n")
        else
            currentLineLength = 30 + 10*(string.len(pair.name))
            generated:write("X=20","\n")
            generated:write("Y=10R","\n")
        end

        generated:write(string.gsub("SolidColor=#BGC#","#BGC#",pair.backgroundcolor),"\n")
        generated:write(string.gsub("FontColor=#FGC#","#FGC#",pair.foregroundcolor),"\n")
        generated:write(string.gsub("Text=#NAME#","#NAME#",pair.name),"\n")
        prev = "MouseOverAction=!CommandMeasure Theming \"Preview('#BGC#','#FGC#','#FGCDL#','#FGCDM#')\""
        prev = prev:gsub("#BGC#",pair.backgroundcolor)
        prev = prev:gsub("#FGC#",pair.foregroundcolor)
        prev = prev:gsub("#FGCDL#",pair.foregroundcolordimlight)
        prev = prev:gsub("#FGCDM#",pair.foregroundcolordimmin)
        generated:write(prev,"\n")
        apply = "LeftMouseUpAction=!CommandMeasure Theming \"Apply('#BGC#','#FGC#','#FGCDL#','#FGCDM#')\""
        apply = apply:gsub("#BGC#",pair.backgroundcolor)
        apply = apply:gsub("#FGC#",pair.foregroundcolor)
        apply = apply:gsub("#FGCDL#",pair.foregroundcolordimlight)
        apply = apply:gsub("#FGCDM#",pair.foregroundcolordimmin)
        generated:write(apply,"\n\n")
    end
    generated:close()

    if doRefresh then
        SKIN:Bang('!Refresh')
    end
    SKIN:Bang('!Updategroup Preview')
end
