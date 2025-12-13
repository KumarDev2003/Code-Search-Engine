#pragma once

#include "ICommand.h"

class IndexCommand : public ICommand {
public:
	void execute(std::string filePath);
};