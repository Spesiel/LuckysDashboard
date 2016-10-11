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
    local height = 0
    local disksTotal = SKIN:GetVariable("DisksTotal")

    height = disksTotal*36

    for currentDisk=1,disksTotal,1 do
        if SKIN:GetVariable("Disk"..currentDisk.."HideTemperature")=="0" then
            height = height + 10
        end
        if SKIN:GetVariable("Disk"..currentDisk.."HideActivity")=="0" then
            height = height + 20*2
        end
    end

    SKIN:Bang("!SetOption SkinSizing H "..height*SKIN:GetVariable("ScaleDisks"))
    SKIN:Bang("!UpdateMeter SkinSizing")
end
