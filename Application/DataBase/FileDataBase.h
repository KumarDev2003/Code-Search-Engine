#pragma once

#include "IDataBase.h"

class FileDataBase : public IDataBase {
private:
	FileDataBase(){}
public:
	static FileDataBase * fileDBPtr;
	static IDataBase * getInstance();
	void save(std::filesystem::path dirPath, std::unordered_map<std::string, int> fileMap,
		std::unordered_map<std::string, std::vector<Location>> wordMap) override ;
	void load(std::filesystem::path& dirPath, std::unordered_map<std::string, int>& fileMap,
		std::unordered_map<std::string, std::vector<Location>>& wordMap) override;
};