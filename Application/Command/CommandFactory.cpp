#include "CommandFactory.h"
#include "IndexCommand.h"
#include "SearchCommand.h"

std::unique_ptr<ICommand> CommandFactory::getCommand(std::string command) {
	if (command == "-index") return std::make_unique<IndexCommand>();
	else if (command == "-search") return std::make_unique<SearchCommand>();
	else return nullptr;
}