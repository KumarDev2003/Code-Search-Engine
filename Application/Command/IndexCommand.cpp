#include <iostream>

#include "IndexCommand.h"
#include "ParserFactory.h"

void IndexCommand::execute(std::string filePath) {
	std::unique_ptr<IFileParser> fileParser = ParserFactory::getParser("basic");
	fileParser->ParseFile(filePath);
	std::cout << "Indexing has been done successfully. You can search the word by: -search word\n";
}