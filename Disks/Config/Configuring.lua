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
    dofile(SKIN:ReplaceVariables("#@#").."ReadWriteIni.lua")

    local generated = {}
    local variables = {}
    local testIfExist=io.open(SKIN:ReplaceVariables("#@#").."disks.var","r")
    if testIfExist~=nil then io.close(testIfExist) variables = ReadIni(SKIN:ReplaceVariables("#@#").."disks.var") end
    local refreshGenerated = false
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."DiskTemplate.inc")
    

    -- loop through the data for each disk
    local content = {}
    for loop=1,variables.Variables.DisksTotal,1 do
        local currentDisk = ("Disk%s"):format(loop)

        if variables.Variables[currentDisk.."Letter"] ~= nil then
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
            variables.Variables[currentDisk.."ActivityReadRateId"] = "0x8000000"
            variables.Variables[currentDisk.."ActivityWriteRateId"] = "0x8000001"
            variables.Variables[currentDisk.."ActivityOnSelect"] = "100,250,100"
            variables.Variables[currentDisk.."ActivityOffSelect"] = "#BackgroundColorDimMin#"
        end

        for key,value in ipairs(template) do
            if string.find(value,"?") then
                local str = string.gsub(value,"?",currentDisk)
                table.insert(content,str)
            else
                table.insert(content,value)
            end
        end
        refreshGenerated = true
    end

    -- Writes the values to files
    if refreshGenerated then
        WriteIni(variables,SKIN:ReplaceVariables("#@#").."disks.var")
        WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
    end

    SKIN:Bang('!Updategroup Disks')
end

function table.contains(table, element)
  for _, value in pairs(table) do
    if value == element then
      return true
    end
  end
  return false
end
