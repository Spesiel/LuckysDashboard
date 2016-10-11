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
    testIfExist=io.open(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc","r")
    if testIfExist~=nil then io.close(testIfExist) generated = ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc") end
    

    -- loop through the data for each disk
    for loop=1,variables.Variables.DisksTotal,1 do
        local currentDisk = ("Disk%s"):format(loop)
        -- the disk we are looking at already exists
        if generated[currentDisk] ~= nil then
        -- the disk we are looking at doesn't exist yet
        else
            local currentDisk = ("Disk%s"):format(loop)

            -- adding the base data to it
            variables.Variables[";"..currentDisk] = ("\n; %s"):format(currentDisk)
            variables.Variables[currentDisk.."Letter"] = "C"
            variables.Variables[currentDisk.."ShowTemperature"] = "1"
            variables.Variables[currentDisk.."SmartOnSelect"] = "100,250,100"
            variables.Variables[currentDisk.."SmartOffSelect"] = "#BackgroundColorDimMin#"
            variables.Variables[currentDisk.."SmartSensorId"] = "0xf0000100"
            variables.Variables[currentDisk.."SmartInstance"] = "0x0"
            variables.Variables[currentDisk.."SmartTemperatureId"] = "0x1000000"
            variables.Variables[currentDisk.."ShowActivity"] = "1"
            variables.Variables[currentDisk.."ActivitySensorId"] = "0xf0000101"
            variables.Variables[currentDisk.."ActivityInstance"] = "0x0"
            variables.Variables[currentDisk.."ActivityReadPercentId"] = "0x7000000"
            variables.Variables[currentDisk.."ActivityWritePercentId"] = "0x7000001"
            variables.Variables[currentDisk.."ActivityReadRateId"] = "0x8000000"
            variables.Variables[currentDisk.."ActivityWriteRateId"] = "0x8000001"
            variables.Variables[currentDisk.."ActivityOnSelect"] = "100,250,100"
            variables.Variables[currentDisk.."ActivityOffSelect"] = "#BackgroundColorDimMin#"

            local content = {}
            generated[currentDisk] = content
        end
    end

    -- Writes the values to files
    --WriteIni(variables,SKIN:ReplaceVariables("#@#").."disks.var")
    --WriteIni(generated,SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

    SKIN:Bang('!Updategroup Disks')
end
