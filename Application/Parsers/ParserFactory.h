#pragma once

#include <string>
#include <memory>

#include "IFileParser.h"

class ParserFactory {
public:
	static std::unique_ptr<IFileParser> getParser(std::string type);
};