-- Create the file for the variables unless it already exists
function Initialize()
    -- generate the buttons for previewing and applying the theme
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#")..'Variables.inc',"r")
    if testIfExist~=nil then io.close(testIfExist) return end
    local variables = io.open(SKIN:ReplaceVariables("#@#")..'Variables.inc','w+')

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
