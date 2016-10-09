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


-- Create the files for the variables unless it already exists
function Initialize()
    -- variables.var
    local doRefreshForVariables = GenerateVariablesFile()
    -- clocks.var
    local doRefreshForClocks = GenerateClocksFile()
    
    if doRefreshForVariables or doRefreshForClocks then SKIN:Bang('!Refresh') end
end

-- variables.var
function GenerateVariablesFile()
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#")..'variables.var',"r")
    if testIfExist~=nil then io.close(testIfExist) return false end
    local variables = io.open(SKIN:ReplaceVariables("#@#")..'variables.var','w+')

    -- Header
    variables:write("[Metadata]","\n")
    variables:write("Name=Variables","\n")
    variables:write("Author=Lucky Penny","\n")
    variables:write("Information=Variables for the whole skin","\n")
    variables:write("License=Creative Commons BY-NC-SA 3.0","\n")
    variables:write("Version=0.0.1","\n\n")

    -- Content
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
    variables:write("ScaleVolume=1","\n")
    variables:close()

    return true
end

-- clocks.var
function GenerateClocksFile()
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#")..'clocks.var',"r")
    if testIfExist~=nil then io.close(testIfExist) return false end
    local clocks = io.open(SKIN:ReplaceVariables("#@#")..'clocks.var','w+')

    -- Header
    clocks:write("[Metadata]","\n")
    clocks:write("Name=ClocksSettings","\n")
    clocks:write("Author=Lucky Penny","\n")
    clocks:write("Information=Variables for the clocks","\n")
    clocks:write("License=Creative Commons BY-NC-SA 3.0","\n")
    clocks:write("Version=0.0.1","\n\n")
    
    -- Content
    clocks:write("[Variables]","\n\n")
    clocks:write("; Clock1 variables","\n")
    clocks:write("Clock1_Label=PST","\n")
    clocks:write("Clock1_12or24=I","\n")
    clocks:write("Clock1_Timezone=-8","\n")
    clocks:write("Clock1_DST=1","\n\n")
    clocks:write("; Clock2 variables","\n")
    clocks:write("Clock2_Label=France","\n")
    clocks:write("Clock2_12or24=I","\n")
    clocks:write("Clock2_Timezone=1","\n")
    clocks:write("Clock2_DST=1","\n\n")
    clocks:write("; Clock3 variables","\n")
    clocks:write("Clock3_Label=CST","\n")
    clocks:write("Clock3_12or24=I","\n")
    clocks:write("Clock3_Timezone=-6","\n")
    clocks:write("Clock3_DST=1","\n\n")
    clocks:write("; Clock4 variables","\n")
    clocks:write("Clock4_Label=EST","\n")
    clocks:write("Clock4_12or24=I","\n")
    clocks:write("Clock4_Timezone=-5","\n")
    clocks:write("Clock4_DST=1","\n\n")
    clocks:write(";------------------------------------------------------------------------------","\n")
    clocks:write("; Used by the configurators","\n\n")
    clocks:write("Clock1_12Select=253,151,31,75","\n")
    clocks:write("Clock1_24Select=0,0,0,0","\n")
    clocks:write("Clock1_DSTOnSelect=100,250,100","\n")
    clocks:write("Clock1_DSTOffSelect=253,151,31,75","\n\n")
    clocks:write("Clock2_12Select=253,151,31,75","\n")
    clocks:write("Clock2_24Select=0,0,0,0","\n")
    clocks:write("Clock2_DSTOnSelect=100,250,100","\n")
    clocks:write("Clock2_DSTOffSelect=253,151,31,75","\n\n")
    clocks:write("Clock3_12Select=253,151,31,75","\n")
    clocks:write("Clock3_24Select=0,0,0,0","\n")
    clocks:write("Clock3_DSTOnSelect=100,250,100","\n")
    clocks:write("Clock3_DSTOffSelect=253,151,31,75","\n\n")
    clocks:write("Clock4_12Select=253,151,31,75","\n")
    clocks:write("Clock4_24Select=0,0,0,0","\n")
    clocks:write("Clock4_DSTOnSelect=100,250,100","\n")
    clocks:write("Clock4_DSTOffSelect=253,151,31,75","\n")

    clocks:close()

    return true
end