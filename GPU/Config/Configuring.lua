------- Metadata --------------------------------------------------------------
-- Configuring
-- Author: Lucky Penny
-- Description: Generates the meters necessary for gpus configuration.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    GenerateFileConfig("gpus","TemplateGpusDefault","TemplateGpuMeters","Gpus","Gpu","SensorId")
end
