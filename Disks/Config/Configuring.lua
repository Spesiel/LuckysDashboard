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
    for loop=1,SKIN:GetVariable("DisksTotal"),1 do
        -- the disk we are looking at already exists
        if generated[("Disk%s"):format(loop)] ~= nil then

        -- the disk we are looking at doesn't exist yet
        else
            -- adding the base data to it
            local addition = {}
            --addition[""]
            generated[("Disk%s"):format(loop)] = addition
        end
    end

    -- Writes the values to files
    WriteIni(variables,SKIN:ReplaceVariables("#@#").."disks.var")
    WriteIni(generated,SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

    SKIN:Bang('!Updategroup Disks')
end
