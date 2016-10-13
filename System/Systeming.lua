------- Metadata --------------------------------------------------------------
-- Systeming
-- Author: Lucky Penny
-- Description: Generates the meters for the system widget.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")
    
    local cpuCount = SKIN:GetVariable("CpuCount")
    local hideAverageTextBar = SKIN:GetVariable("SystemCpuAverageTextBar")
    local showTemp = SKIN:GetVariable("SystemTemp")

    -- Loads the template
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateCpuMeters.inc")

    local averageTempFormula = {}

    -- loop through the data for each core
    local content = {}
    for loop=0,cpuCount-1,1 do
        for _,value in ipairs(template) do
            -- position the meters depending if average is shown or not
            if hideAverageTextBar=="0" then
                if (loop==0) and (value:find("Y=xr")) then
                    value = "Y=-3r"
                elseif (loop>0) and (value:find("Y=xr")) then
                    value = "Y=4R"
                end
            else
                if (loop==0) and (value:find("Y=xr")) then
                    value = "Y=-18r"
                elseif (loop>0) and (value:find("Y=xr")) then
                    value = "Y=4R"
                end
            end

            -- sets the bar width depending if the temperature is shown for cores
            if (showTemp=="0") and (value:find("W=155")) then
                value = "W=110"
            end

            local str = ""
            if value:find("|") then
                str = value:gsub("|",loop)
            else
                str = value
            end
            table.insert(content,str)
        end

        local atf = ("Cpu|TempCoreValue"):gsub("|",loop)
        table.insert(averageTempFormula,atf)
    end
    WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generatedCpuMeters.inc")

    SKIN:Bang("!SetOption CpuAllTempMeasure Formula ((".. table.concat(averageTempFormula,"+") ..")/".. cpuCount ..")")
end
