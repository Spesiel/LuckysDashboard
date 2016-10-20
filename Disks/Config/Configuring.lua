------- Metadata --------------------------------------------------------------
-- Configuring
-- Author: Lucky Penny
-- Description: Generates the meters necessary for disks configuration.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    GenerateFileConfig("disks","TemplateDisksDefault","TemplateDiskMeters","Disks","Disk","Letter")
end
