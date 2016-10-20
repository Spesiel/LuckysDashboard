------- Metadata --------------------------------------------------------------
-- Disking
-- Author: Lucky Penny
-- Description: Calculates on the fly the correct height for the widget.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.3
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


-- Load all schemes from file
function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    GenerateFile("DisksTotal","TemplateDiskMeters","Disk")
end
