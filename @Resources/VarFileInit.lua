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
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#").."variables.var","r")
    if testIfExist~=nil then io.close(testIfExist) return false end
    local variables = io.open(SKIN:ReplaceVariables("#@#").."variables.var","w+")

    local variables = {}
    variables["Metadata"] = GenerateMetadata("Variables","Lucky Penny","Variables for the whole skin",0.0.1)

    local content = {}
    content[";1"]="\n;------------------------------------------------------------------------------"
    content[";2"]="; Colors from the color scheme\n"
    content["BackgroundColor"]="0,0,0,95"
    content["ForegroundColor"]="255,255,255"
    content["ForegroundColorDimLight"]="255,255,255,150"
    content["ForegroundColorDimMin"]="255,255,255,50"
    content[";3"]="\n;------------------------------------------------------------------------------"
    content[";4"]="; Scales\n"
    content["ScaleClock"]=1
    content["ScaleDate"]=1
    content["ScaleVolume"]=1
    content["ScaleDisks"]=1
    variables["Variables"] = content

    WriteIni(variables,SKIN:ReplaceVariables("#@#").."variables.var")

    return true
end

-- clocks.var
function GenerateClocksFile()
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#").."clocks.var","r")
    if testIfExist~=nil then io.close(testIfExist) return false end
    local clocks = io.open(SKIN:ReplaceVariables("#@#").."clocks.var","w+")

    local clocks = {}
    clocks["Metadata"] = GenerateMetadata("ClocksSettings","Lucky Penny","Variables for the clocks",0.0.1)

    local content = {}

    content[";1"]="\n;------------------------------------------------------------------------------"
    content[";2"]="; Clocks individual variables\n"
    content[";3"]="; Clock1 variables\n"
    content["Clock1_Label"]="PST"
    content["Clock1_12or24"]="I"
    content["Clock1_Timezone"]=-8
    content["Clock1_DST"]=1
    content[";4"]="; Clock2 variables\n"
    content["Clock2_Label"]="France"
    content["Clock2_12or24"]="I"
    content["Clock2_Timezone"]=1
    content["Clock2_DST"]=1
    content[";5"]="; Clock3 variables\n"
    content["Clock3_Label"]="CST"
    content["Clock3_12or24"]="I"
    content["Clock3_Timezone"]=-6
    content["Clock3_DST"]=1
    content[";6"]="; Clock4 variables\n"
    content["Clock4_Label"]="EST"
    content["Clock4_12or24"]="I"
    content["Clock4_Timezone"]=-5
    content["Clock4_DST"]=1
    content[";7"]="\n;------------------------------------------------------------------------------"
    content[";8"]="; DateAndClocks individual variables\n"
    content[";9"]="; DateAndClock1 variables\n"
    content["DateAndClock1_Position_Date"]=62
    content["DateAndClock1_Position_Time"]=187
    content[";11"]="; DateAndClock2 variables\n"
    content["DateAndClock2_Position_Date"]=62
    content["DateAndClock2_Position_Time"]=187
    content[";12"]="; DateAndClock3 variables\n"
    content["DateAndClock3_Position_Date"]=62
    content["DateAndClock3_Position_Time"]=187
    content[";13"]="; DateAndClock4 variables\n"
    content["DateAndClock4_Position_Date"]=62
    content["DateAndClock4_Position_Time"]=187
    content[";14"]="\n;------------------------------------------------------------------------------"
    content[";15"]="; Used by the configurators\n"
    content["Clock1_12Select"]="#ForegroundColorDimMin#"
    content["Clock1_24Select"]="#ColorClear#"
    content["Clock1_DSTOnSelect"]="#ForegroundColorDimMin#"
    content["Clock1_DSTOffSelect"]="#ForegroundColorDimMin#"
    content["DateAndClock1_DateLeft"]="#ForegroundColorDimMin#"
    content["DateAndClock1_DateRight"]="#ColorClear#"
    content["Clock2_12Select"]="#ForegroundColorDimMin#"
    content["Clock2_24Select"]="#ColorClear#"
    content["Clock2_DSTOnSelect"]="#ForegroundColorDimMin#"
    content["Clock2_DSTOffSelect"]="#ForegroundColorDimMin#"
    content["DateAndClock2_DateLeft"]="#ForegroundColorDimMin#"
    content["DateAndClock2_DateRight"]="#ColorClear#"
    content["Clock3_12Select"]="#ForegroundColorDimMin#"
    content["Clock3_24Select"]="#ColorClear#"
    content["Clock3_DSTOnSelect"]="#ForegroundColorDimMin#"
    content["Clock3_DSTOffSelect"]="#ForegroundColorDimMin#"
    content["DateAndClock3_DateLeft"]="#ForegroundColorDimMin#"
    content["DateAndClock3_DateRight"]="#ColorClear#"
    content["Clock4_12Select"]="#ForegroundColorDimMin#"
    content["Clock4_24Select"]="#ColorClear#"
    content["Clock4_DSTOnSelect"]="#ForegroundColorDimMin#"
    content["Clock4_DSTOffSelect"]="#ForegroundColorDimMin#"
    content["DateAndClock4_DateLeft"]="#ForegroundColorDimMin#"
    content["DateAndClock4_DateRight"]="#ColorClear#"

    variables["Variables"] = content

    WriteIni(variables,SKIN:ReplaceVariables("#@#").."clocks.var")

    return true
end

-- disks.var
function GenerateDisksFile()
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#")..'disks.var',"r")
    if testIfExist~=nil then io.close(testIfExist) return false end
    local disks = {}
    disks["Metadata"] = GenerateMetadata("DisksSettings","Lucky Penny","Variables for the disks",0.0.1)

    local variables = {}
    variables[";1"]="\n;------------------------------------------------------------------------------"
    variables[";2"]="; Disks common variables\n"
    variables["DisksTotal"]=1
    disks["Variables"] = variables

    WriteIni(disks,SKIN:ReplaceVariables("#@#").."disks.var")

    return true
end

-- Generate Metadata
function GenerateMetadata(name,author,information,version)
    local metadata = {}
    metadata["Name"]=name
    metadata["Author"]=author
    metadata["Information"]=information
    metadata["License"]="Creative Commons BY-NC-SA 3.0"
    metadata["Version"]=version
    return metadata
end
