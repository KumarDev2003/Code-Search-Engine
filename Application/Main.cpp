#include <iostream>
#include <memory>
//#include <thread> Karna h kya dekh lena baad me

#include "BasicTokenizer.h"
#include "IndexManager.h"
#include "ParserFactory.h"
#include "SearchStrategy.h"
#include "CommandFactory.h"

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
	//std::unique_ptr<IFileParser> fileParser = ParserFactory::getParser("basic");
	//std::unique_ptr<ISearchEngine> basicSearchEngine = SearchStrategy::strategy("basic");

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
		std::unique_ptr<ICommand> command = CommandFactory::getCommand(arg);
		command->execute(parameter);
	}
	if(idxmgr) delete idxmgr;
}