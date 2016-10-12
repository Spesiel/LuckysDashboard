------- Metadata --------------------------------------------------------------
-- ReadWriteIni
-- Author: Lucky Penny
-- Description: Read and Write methods for ini files.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.1
--
-- ReadIni(inputfile): Reads an ini file and returns it as a table.
-- WriteIni(inputtable,filename): Writes the ini data to file.
-- ReadFile(FilePath): Reads a file as it is and returns it as a table.
-------------------------------------------------------------------------------


function ReadIni(inputfile)
	local file = assert(io.open(inputfile, 'r'), 'Unable to open ' .. inputfile)
	local table, section = {}
	local num = 0
	for line in file:lines() do
		num = num + 1
		if not line:match('^%s-;') then
			local key, command = line:match('^([^=]+)=(.+)')
			if line:match('^%s-%[.+') then
				section = line:match('^%s-%[([^%]]+)')
				if not table[section] then table[section] = {} end
			elseif key and command and section then
				table[section][key:match('^s*(%S*)%s*$')] = command:match('^s*(.-)%s*$')
			elseif #line > 0 and section and not key or command then
				print(num .. ': Invalid property or value.')
			end
		end
	end
	if not section then print('No sections found in ' .. inputfile) end
	file:close()
	return table
end

function WriteIni(inputtable, filename)
	assert(type(inputtable) == 'table', ('WriteIni must receive a table. Received %s instead.'):format(type(inputtable)))

	local file = assert(io.open(filename, 'w+'), 'Unable to open ' .. filename)

    if inputtable.Metadata ~= nil then
        file:write("[Metadata]","\n")
        file:write(("Name=%s"):format(inputtable.Metadata.Name),"\n")
        file:write(("Author=%s"):format(inputtable.Metadata.Author),"\n")
        file:write(("Information=%s"):format(inputtable.Metadata.Information),"\n")
        file:write("License=Creative Commons BY-NC-SA 3.0","\n")
        file:write(("Version=%s"):format(inputtable.Metadata.Version),"\n\n")
    end

	for section, contents in pairs(inputtable) do
        if section ~= "Metadata" then
            file:write(("[%s]"):format(section),"\n")
            for key, value in pairs(contents) do
				-- It's a comment
				if string.sub(key,1,1)==";" then
					file:write(("%s"):format(value),"\n")
				-- It's data
                else
					file:write(("%s=%s"):format(key,value),"\n")
				end
            end
            file:write("\n")
        end
	end

	file:close()
end

function ReadFile(FilePath)
	-- OPEN FILE.
	local File = io.open(FilePath)

	-- HANDLE ERROR OPENING FILE.
	if not File then
		print('ReadFile: unable to open file at ' .. FilePath)
		return
	end

	-- READ FILE CONTENTS AND CLOSE.
	local Contents = {}
	for Line in File:lines() do
		table.insert(Contents, Line)
	end

	return Contents
end

function WriteFile(Contents,FilePath)
	-- OPEN FILE.
	local File = assert(io.open(FilePath, 'w+'), 'Unable to open ' .. FilePath)

	-- WRITE CONTENTS AND CLOSE FILE
	File:write(Contents)
	File:close()

	return true
end
