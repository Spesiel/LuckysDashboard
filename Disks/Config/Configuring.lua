------- Metadata --------------------------------------------------------------
-- Configuring
-- Author: Lucky Penny
-- Description: Generates the meters necessary for disks configuration.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


-- Load all data from generated.inc and disks.var
function Initialize()
    -- Loads the Read and Write methods for ini files
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    local generated = {}
    local variables = {}
    local refreshGenerated = false
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#").."disks.var","r")
    if testIfExist then io.close(testIfExist) variables = ReadIni(SKIN:ReplaceVariables("#@#").."disks.var") end
    testIfExist=io.open(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc","r")
    if testIfExist then
        io.close(testIfExist) generated = ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
        else refreshGenerated = true end
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateDiskMeters.inc")
    

    -- loop through the data for each disk
    local content = {}
    for loop=1,variables.Variables.DisksTotal,1 do
        local currentDisk = ("Disk%s"):format(loop)

        if variables.Variables[currentDisk.."Letter"] then
            -- the disk we are looking at doesn't exist yet
        else
            -- adding the base data to it
            variables.Variables[currentDisk.."Letter"] = "C"
            variables.Variables[currentDisk.."HideTemperature"] = "0"
            variables.Variables[currentDisk.."SmartOnSelect"] = "100,250,100"
            variables.Variables[currentDisk.."SmartOffSelect"] = "#BackgroundColorDimMin#"
            variables.Variables[currentDisk.."SmartSensorId"] = "0xf0000100"
            variables.Variables[currentDisk.."SmartInstance"] = "0x0"
            variables.Variables[currentDisk.."SmartTemperatureId"] = "0x1000000"
            variables.Variables[currentDisk.."HideActivity"] = "0"
            variables.Variables[currentDisk.."ActivitySensorId"] = "0xf0000101"
            variables.Variables[currentDisk.."ActivityInstance"] = "0x0"
            variables.Variables[currentDisk.."ActivityReadPercentId"] = "0x7000000"
            variables.Variables[currentDisk.."ActivityWritePercentId"] = "0x7000001"
            variables.Variables[currentDisk.."ActivityOnSelect"] = "100,250,100"
            variables.Variables[currentDisk.."ActivityOffSelect"] = "#BackgroundColorDimMin#"
            refreshGenerated = true
        end

        if not generated[currentDisk.."Title"] then
            refreshGenerated = true
        end
        
        for _,value in ipairs(template) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentDisk)
            else
                str = value
            end
            table.insert(content,str)
        end
    end

    if generated["Disk"..(tonumber(variables.Variables.DisksTotal)+1).."Title"] then
        refreshGenerated = true
    end

    -- Sets the dialog size based on the number of disks
    local height = 0
    local disksTotal = SKIN:GetVariable("DisksTotal")

    -- Writes the values to files
    if refreshGenerated then
        WriteIni(variables,SKIN:ReplaceVariables("#@#").."disks.var")
        WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

        SKIN:Bang('!RefreshGroup Disks')
    end

    height = 81+disksTotal*75+5
    SKIN:Bang("!SetOption SkinSizing H "..height*SKIN:GetVariable("ScaleDisks"))
    SKIN:Bang("!UpdateMeter SkinSizing")
end
