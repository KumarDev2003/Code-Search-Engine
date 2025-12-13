#pragma once

#include <string>
#include <memory>

#include "ICommand.h"

class CommandFactory {
public:
	static std::unique_ptr<ICommand> getCommand(std::string command);
};