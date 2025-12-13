#pragma once

#include "IFileParser.h"

class BasicFileParser : public IFileParser {
public:
	void ParseFile(std::string filePath) override;
	virtual ~BasicFileParser(){}
};
