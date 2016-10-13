------- Metadata --------------------------------------------------------------
-- VarFileInit
-- Author: Lucky Penny
-- Description: Creates all variables files with default values.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- Initialize(): As described
-------------------------------------------------------------------------------


-- Create the files for the variables unless it already exists
function Initialize()
    -- variables.var
    local doRefreshForVariables = GenerateVariablesFile()
    -- clocks.var
    local doRefreshForClocks = GenerateClocksFile()
    -- disks.var
    local doRefreshForDisks = GenerateDisksFile()
    -- network.var
    local doRefreshForNetwork = GenerateNetworkFile()
    -- system.var
    local doRefreshForSystem = GenerateSystemFile()
    
    if doRefreshForVariables or doRefreshForClocks or doRefreshForDisks or doRefreshForNetwork or doRefreshForSystem then
        SKIN:Bang('!Refresh') end
end

-- variables.var
function GenerateVariablesFile()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    if next(ReadIni(SKIN:ReplaceVariables("#@#").."variables.var")) then return false end
    local variables = {}

    local templateVariableVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\TemplateVariablesDefault.inc")
    variables = GenerateMetadata(variables,"Variables","Lucky Penny","Variables for the whole skin","0.0.1")
    table.insert(variables,"[Variables]")

    for _,value in ipairs(templateVariableVars) do
        table.insert(variables,value)
    end

    WriteFile(table.concat(variables,"\n"),SKIN:ReplaceVariables("#@#").."variables.var")

    return true
end

-- clocks.var
function GenerateClocksFile()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    if next(ReadIni(SKIN:ReplaceVariables("#@#").."clocks.var")) then return false end
    local clocks = {}

    local templateClocksVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\TemplateClocksDefault.inc")
    clocks = GenerateMetadata(clocks,"ClocksSettings","Lucky Penny","Variables for the clocks","0.0.1")
    table.insert(clocks,"[Variables]")

    for _,value in ipairs(templateClocksVars) do
        table.insert(clocks,value)
    end

    WriteFile(table.concat(clocks,"\n"),SKIN:ReplaceVariables("#@#").."clocks.var")

    return true
end

-- disks.var
function GenerateDisksFile()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    if next(ReadIni(SKIN:ReplaceVariables("#@#").."disks.var")) then return false end
    local disks = {}

    local templateSystemVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\TemplateDisksDefault.inc")
    disks = GenerateMetadata(disks,"DisksSettings","Lucky Penny","Variables for the disks","0.0.1")
    table.insert(disks,"[Variables]")
    table.insert(disks,"DisksTotal=1")

    for _,value in ipairs(templateSystemVars) do
        local str = ""
        if value:find("|") then
            str = value:gsub("|","Disk1")
        else
            str = value
        end
        table.insert(disks,str)
    end

    WriteFile(table.concat(disks,"\n"),SKIN:ReplaceVariables("#@#").."disks.var")

    return true
end

-- network.var
function GenerateNetworkFile()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    if next(ReadIni(SKIN:ReplaceVariables("#@#").."network.var")) then return false end
    local network = {}

    local templateNetworkVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\TemplateNetworkDefault.inc")
    network = GenerateMetadata(network,"NetworkSettings","Lucky Penny","Variables for the network","0.0.1")
    table.insert(network,"[Variables]")

    for _,value in ipairs(templateNetworkVars) do
        table.insert(network,value)
    end

    WriteFile(table.concat(network,"\n"),SKIN:ReplaceVariables("#@#").."network.var")

    return true
end

-- system.var
function GenerateSystemFile()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    if next(ReadIni(SKIN:ReplaceVariables("#@#").."system.var")) then return false end
    local system = {}

    local templateSystemVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\TemplateSystemDefault.inc")
    system = GenerateMetadata(system,"SystemSettings","Lucky Penny","Variables for the system","0.0.1")
    table.insert(system,"[Variables]")

    for _,value in ipairs(templateSystemVars) do
        local str = ""
        if value:find("|") then
            str = value:gsub("|","0")
        else
            str = value
        end
        table.insert(system,str)
    end

    WriteFile(table.concat(system,"\n"),SKIN:ReplaceVariables("#@#").."system.var")

    return true
end

function GenerateMetadata(inputtable,name,author,information,version)
	table.insert(inputtable,"[Metadata]")
	table.insert(inputtable,"Name="..name)
    table.insert(inputtable,"Author="..author)
    table.insert(inputtable,"Information="..information)
    table.insert(inputtable,"License=Creative Commons BY-NC-SA 3.0")
    table.insert(inputtable,"Version="..version.."\n")
    return inputtable
end
