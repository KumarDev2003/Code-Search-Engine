#pragma once

#include <string>

class IFileParser {
public:
	virtual void ParseFile(std::string filePath) = 0;
	virtual ~IFileParser() {}
};
