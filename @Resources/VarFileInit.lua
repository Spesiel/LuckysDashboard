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
    local doRefreshForVariables = GenerateVarsFile("variables","TemplateVariablesDefault","Variables","Variables for the whole skin","")
    -- clocks.var
    local doRefreshForClocks = GenerateVarsFile("clocks","TemplateClocksDefault","ClocksSettings","Variables for the clocks","")
    -- disks.var
    local doRefreshForDisks = GenerateVarsFile("disks","TemplateDisksDefault","DisksSettings","Variables for the disks","Disk1")
    -- network.var
    local doRefreshForNetwork = GenerateVarsFile("network","TemplateNetworkDefault","NetworkSettings","Variables for the network","")
    -- fortune.var
    local doRefreshForFortune = GenerateVarsFile("fortune","TemplateFortuneDefault","FortuneSettings","Variables for the fortune","")
    -- system.var
    local doRefreshForSystem = GenerateVarsFile("system","TemplateSystemDefault","SystemSettings","Variables for the system","0")
    
    if doRefreshForVariables
     or doRefreshForClocks
     or doRefreshForDisks
     or doRefreshForNetwork
     or doRefreshForFortune
     or doRefreshForSystem then
        SKIN:Bang("!Refresh") end
end

-- Generator for var files
function GenerateVarsFile(varFileName,templateFileName,name,description,substitute)
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    if next(ReadIni(SKIN:ReplaceVariables("#@#")..varFileName..".var")) then return false end
    local variables = {}

    local templateFileVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\"..templateFileName..".inc")
    variables = GenerateMetadata(variables,name,"Lucky Penny",description,"0.0.1")
    table.insert(variables,"[Variables]")

    for _,value in ipairs(templateFileVars) do
        local str = ""
        if value:find("|") then
            str = value:gsub("|",substitute)
        else
            str = value
        end
        table.insert(variables,str)
    end

    WriteFile(table.concat(variables,"\n"),SKIN:ReplaceVariables("#@#")..varFileName..".var")

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
