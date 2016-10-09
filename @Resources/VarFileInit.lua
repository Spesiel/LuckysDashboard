------- Metadata --------------------------------------------------------------
-- Theming
-- Author: Lucky Penny
-- Description: Creates a variables.var file if it doesn't exist, with default
--              values for every variable.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Initialize(): As described
-------------------------------------------------------------------------------


-- Create the file for the variables unless it already exists
function Initialize()
    -- generate the buttons for previewing and applying the theme
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#")..'variables.var',"r")
    if testIfExist~=nil then io.close(testIfExist) return end
    local variables = io.open(SKIN:ReplaceVariables("#@#")..'variables.var','w+')

    variables:write("[Variables]","\n\n")
    variables:write(";------------------------------------------------------------------------------","\n")
    variables:write("; Colors from the color scheme","\n\n")
    variables:write("BackgroundColor=0,0,0,95","\n")
    variables:write("ForegroundColor=255,255,255","\n")
    variables:write("ForegroundColorDimLight=255,255,255,150","\n")
    variables:write("ForegroundColorDimMin=255,255,255,50","\n\n")
    variables:write(";------------------------------------------------------------------------------","\n")
    variables:write("; Scales","\n\n")
    variables:write("ScaleClock=1","\n")
    variables:write("ScaleDate=1","\n")
    variables:close()
    
    SKIN:Bang('!Refresh')
end
