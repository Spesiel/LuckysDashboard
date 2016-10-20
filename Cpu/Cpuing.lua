------- Metadata --------------------------------------------------------------
-- Cpuing
-- Author: Lucky Penny
-- Description: Generates the meters for the cpu widget.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.3
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


-- Load all schemes from file
function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    GenerateFile("CpusTotal","TemplateCpuMeters","Cpu")
end
