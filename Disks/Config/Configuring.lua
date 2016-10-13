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

    local disks = ReadIni(SKIN:ReplaceVariables("#@#").."disks.var")
    local refreshDisks = false
    if next(disks)==nil then refreshDisks = true end
    local generated = ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
    local refreshGenerated = false
    if next(generated)==nil then refreshGenerated = true end

    local templateDiskMeters = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateDiskMeters.inc")
    local templateDiskVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\TemplateDisksDefault.inc")

    -- loop through the data for each disk
    local variables = {}
    GenerateMetadata(variables,"DisksSettings","Lucky Penny","Variables for the disks","0.0.1")
    table.insert(variables,"[Variables]")
    table.insert(variables,"DisksTotal="..disks.Variables.DisksTotal)
    local content = {}
    for loop=1,disks.Variables.DisksTotal,1 do
        local currentDisk = ("Disk%s"):format(loop)

        if not disks.Variables[currentDisk.."Letter"] then refreshDisks     = true end
        if not generated[currentDisk.."Title"]        then refreshGenerated = true end
        
        for _,value in ipairs(templateDiskMeters) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentDisk)
            else
                str = value
            end
            table.insert(content,str)
        end

        for _,value in ipairs(templateDiskVars) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentDisk)
            else
                str = value
            end
            table.insert(variables,str)
        end
    end

    if generated["Disk"..(tonumber(disks.Variables.DisksTotal)+1).."Title"] then
        refreshGenerated = true
    end

    -- Sets the dialog size based on the number of disks
    local height = 0
    local disksTotal = SKIN:GetVariable("DisksTotal")

    -- Writes the values to files
    if refreshDisks or refreshGenerated then
        WriteFile(table.concat(variables,"\n"),SKIN:ReplaceVariables("#@#").."disks.var")
        WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

        SKIN:Bang('!RefreshGroup Disks')
    end

    height = 81+disksTotal*75+5
    SKIN:Bang("!SetOption SkinSizing H "..height*SKIN:GetVariable("ScaleDisks"))
    SKIN:Bang("!UpdateMeter SkinSizing")
end
