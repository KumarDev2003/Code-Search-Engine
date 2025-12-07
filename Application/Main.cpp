#include <iostream>
//#include <thread> Karna h kya dekh lena baad me

#include "BasicFileParser.h"
#include "BasicTokenizer.h"
#include "BasicSearchEngine.h"
#include "IndexManager.h"

static bool valid(std::string& cmd, std::string& arg, std::string& parameter) {
	if (cmd.size() < 4) return false;
	else if (cmd == "exit" || cmd == "Exit") {
		arg = cmd;
		return true;
	}
	else if (cmd.substr(0, 6) == "-index") {
		arg = "-index";
		parameter = cmd.substr(7);
		return true;
	}
	else if (cmd.substr(0, 7) == "-search") {
		arg = "-search";
		parameter = cmd.substr(8);
		return true;
	}
	return false;
}

int main() {

	IndexManager* idxmgr = IndexManager::getInstance();
	IFileParser* fileParser = new BasicFileParser();
	ISearchEngine* basicSearchEngine = new BasicSearchEngine();

	std::cout << "Please enter the directory/folder path for indexing: -index path" << std::endl;

	while (true) {
		std::string cmd, arg, parameter;
		std::getline(std::cin, cmd);
		if (!valid(cmd, arg, parameter)) {
			break;
		}
		else if (arg == "exit" || arg == "Exit") {
			break;
		}
		else if (arg == "-index") {
			fileParser->ParseFile(parameter);
			std::cout << "Indexing has been done successfully. You can search the word by: -search word\n";
		}
		else if (arg == "-search") {
			std::vector<Location> result = basicSearchEngine->search(parameter);
			std::cout << "\nTotal occurnce of \""<< parameter << "\" is " << result.size() << std::endl;
			for (Location word : result) {
				std::cout << "{\n";
				std::cout << word.filePath << "\n";
				std::cout << "Line no. " << word.lineNumber << " " << word.lineText << std::endl;
				std::cout << "}\n";
			}
		}
	}
	if(idxmgr) delete idxmgr;
	if(fileParser) delete fileParser;
	if(basicSearchEngine) delete basicSearchEngine;
}