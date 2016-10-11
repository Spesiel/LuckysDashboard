------- Metadata --------------------------------------------------------------
-- Theming
-- Author: Lucky Penny
-- Description: Creates all variables files with default values.
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
    -- disks.var
    local doRefreshForDisks = GenerateDisksFile()
    
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
    variables:write("ScaleDisks=1","\n")
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
    clocks:write(";------------------------------------------------------------------------------","\n")
    clocks:write("; Clocks individual variables","\n\n")
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
    clocks:write("; DateAndClocks individual variables","\n\n")
    clocks:write("; DateAndClock1 variables","\n")
    clocks:write("DateAndClock1_Position_Date=62","\n")
    clocks:write("DateAndClock1_Position_Time=187","\n\n")
    clocks:write("; DateAndClock2 variables","\n")
    clocks:write("DateAndClock2_Position_Date=62","\n")
    clocks:write("DateAndClock2_Position_Time=187","\n\n")
    clocks:write("; DateAndClock3 variables","\n")
    clocks:write("DateAndClock3_Position_Date=62","\n")
    clocks:write("DateAndClock3_Position_Time=187","\n\n")
    clocks:write("; DateAndClock4 variables","\n")
    clocks:write("DateAndClock4_Position_Date=62","\n")
    clocks:write("DateAndClock4_Position_Time=187","\n\n")
    clocks:write(";------------------------------------------------------------------------------","\n")
    clocks:write("; Used by the configurators","\n\n")
    clocks:write("Clock1_12Select=#ForegroundColorDimMin#","\n")
    clocks:write("Clock1_24Select=#ColorClear#","\n")
    clocks:write("Clock1_DSTOnSelect=#ForegroundColorDimMin#","\n")
    clocks:write("Clock1_DSTOffSelect=#ForegroundColorDimMin#","\n\n")
    clocks:write("DateAndClock1_DateLeft=#ForegroundColorDimMin#","\n")
    clocks:write("DateAndClock1_DateRight=#ColorClear#","\n\n")
    clocks:write("Clock2_12Select=#ForegroundColorDimMin#","\n")
    clocks:write("Clock2_24Select=#ColorClear#","\n")
    clocks:write("Clock2_DSTOnSelect=#ForegroundColorDimMin#","\n")
    clocks:write("Clock2_DSTOffSelect=#ForegroundColorDimMin#","\n\n")
    clocks:write("DateAndClock2_DateLeft=#ForegroundColorDimMin#","\n")
    clocks:write("DateAndClock2_DateRight=#ColorClear#","\n\n")
    clocks:write("Clock3_12Select=#ForegroundColorDimMin#","\n")
    clocks:write("Clock3_24Select=#ColorClear#","\n")
    clocks:write("Clock3_DSTOnSelect=#ForegroundColorDimMin#","\n")
    clocks:write("Clock3_DSTOffSelect=#ForegroundColorDimMin#","\n\n")
    clocks:write("DateAndClock3_DateLeft=#ForegroundColorDimMin#","\n")
    clocks:write("DateAndClock3_DateRight=#ColorClear#","\n\n")
    clocks:write("Clock4_12Select=#ForegroundColorDimMin#","\n")
    clocks:write("Clock4_24Select=#ColorClear#","\n")
    clocks:write("Clock4_DSTOnSelect=#ForegroundColorDimMin#","\n")
    clocks:write("Clock4_DSTOffSelect=#ForegroundColorDimMin#","\n")
    clocks:write("DateAndClock4_DateLeft=#ForegroundColorDimMin#","\n")
    clocks:write("DateAndClock4_DateRight=#ColorClear#","\n")

    clocks:close()

    return true
end

-- disks.var
function GenerateDisksFile()
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#")..'disks.var',"r")
    if testIfExist~=nil then io.close(testIfExist) return false end
    local disks = io.open(SKIN:ReplaceVariables("#@#")..'disks.var','w+')

    -- Header
    disks:write("[Metadata]","\n")
    disks:write("Name=DisksSettings","\n")
    disks:write("Author=Lucky Penny","\n")
    disks:write("Information=Variables for the disks","\n")
    disks:write("License=Creative Commons BY-NC-SA 3.0","\n")
    disks:write("Version=0.0.1","\n\n")

    -- Content
    disks:write("[Variables]","\n\n")
    disks:write(";------------------------------------------------------------------------------","\n")
    disks:write("; Disks common variables","\n\n")
    disks:write("DisksTotal=1","\n")
    disks:close()

    return true
end