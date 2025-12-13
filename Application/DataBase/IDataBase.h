#pragma once

#include <filesystem>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Location.h"

class IDataBase {
public:
	virtual void save(std::filesystem::path dirPath, std::unordered_map<std::string, int> fileMap,
		std::unordered_map<std::string, std::vector<Location>> wordMap) = 0;
	virtual void load(std::filesystem::path& dirPath, std::unordered_map<std::string, int>& fileMap,
		std::unordered_map<std::string, std::vector<Location>>& wordMap) = 0;
	virtual ~IDataBase(){}
};