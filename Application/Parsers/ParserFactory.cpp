#include "ParserFactory.h"
#include "BasicFileParser.h"

std::unique_ptr<IFileParser> ParserFactory::getParser(std::string type) {
	if (type == "basic") return std::make_unique<BasicFileParser>();
	else return nullptr;
}

