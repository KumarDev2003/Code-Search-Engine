#pragma once

#include <vector>
#include <string>
#include <filesystem>

class DirectoryScanner {
public:
	std::vector<std::filesystem::directory_entry> getFiles(std::filesystem::path path);
};
