------- Metadata --------------------------------------------------------------
-- Disking
-- Author: Lucky Penny
-- Description: Calculates on the fly the correct height for the widget.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


-- Load all schemes from file
function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")
    
    local disksTotal = SKIN:GetVariable("DisksTotal")

    -- Loads the template
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateDiskMeters.inc")

    -- loop through the data for each disk
    local content = {}
    for loop=1,disksTotal,1 do
        local currentDisk = ("Disk%s"):format(loop)
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
    WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

    -- Sets the widget size
    local height = 0

    height = disksTotal*30

    for currentDisk=1,disksTotal,1 do
        if (SKIN:GetVariable("Disk"..currentDisk.."HideTemperature")=="0") and (SKIN:GetVariable("Disk"..currentDisk.."HideActivity")=="1") then
            height = height + 10
        end
        if SKIN:GetVariable("Disk"..currentDisk.."HideActivity")=="0" then
            height = height + 16
        end
    end
    height = height + 5

    SKIN:Bang("!SetOption SkinSizing H "..height*SKIN:GetVariable("ScaleDisks"))
    SKIN:Bang("!UpdateMeter SkinSizing")
end
