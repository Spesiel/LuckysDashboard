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

    local gpus = ReadIni(SKIN:ReplaceVariables("#@#").."gpus.var")
    local refreshGpus = false
    if next(gpus)==nil then refreshGpus = true end
    local generated = ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
    local refreshGenerated = false
    if next(generated)==nil then refreshGenerated = true end

    local templateGpuMeters = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateGpuMeters.inc")
    local templateGpuVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\TemplateGpusDefault.inc")

    -- loop through the data for each gpu
    local variables = {}
    GenerateMetadata(variables,"GpusSettings","Lucky Penny","Variables for the gpus","0.0.1")
    table.insert(variables,"[Variables]")
    table.insert(variables,"GpusTotal="..gpus.Variables.GpusTotal)
    local content = {}
    for loop=1,gpus.Variables.GpusTotal,1 do
        local currentGpu = ("Gpu%s"):format(loop)

        if not gpus.Variables[currentGpu.."SensorId"] then refreshGpus     = true end
        if not generated[currentGpu.."Title"]        then refreshGenerated = true end
        
        for _,value in ipairs(templateGpuMeters) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentGpu)
            else
                str = value
            end
            table.insert(content,str)
        end

        for _,value in ipairs(templateGpuVars) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentGpu)
            else
                str = value
            end
            if str:find("GpusTotal")==nil then table.insert(variables,str) end
        end
    end

    if generated["Gpu"..(tonumber(gpus.Variables.GpusTotal)+1).."Title"] then
        refreshGenerated = true
    end

    -- Writes the values to files
    if refreshGpus or refreshGenerated then
        WriteFile(table.concat(variables,"\n"),SKIN:ReplaceVariables("#@#").."gpus.var")
        WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

        SKIN:Bang('!RefreshGroup Gpus')
    end
    SKIN:Bang("!UpdateMeter SkinSizing")
end
