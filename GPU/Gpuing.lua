------- Metadata --------------------------------------------------------------
-- Gpuing
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
    
    local gpuTotal = SKIN:GetVariable("GpusTotal")

    -- Loads the template
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateGpuMeters.inc")

    -- loop through the data for each gpu
    local content = {}
    for loop=1,gpuTotal,1 do
        local currentGpu = ("Gpu%s"):format(loop)
        for _,value in ipairs(template) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentGpu)
            else
                str = value
            end
            table.insert(content,str)
        end
    end
    WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

    SKIN:Bang("!UpdateMeter SkinSizing")
end
