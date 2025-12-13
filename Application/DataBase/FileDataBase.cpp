#include <iostream>
#include <filesystem>
#include <fstream>

#include "FileDataBase.h"
#include "Location.h"

static std::string createDataFileName(std::filesystem::path dirPath) {
    std::string dirName = dirPath.string();
    std::string fileName = "";
    int n = dirName.size();
    int i = 0;
    while (i < n && dirName[i] != '\\') {
        if (dirName[i] == ':') {
            i++;
            continue;
        }
        fileName += dirName[i];
        i++;
    }
    fileName += "_";
    while (i < n) {
        while (i < n && dirName[i] == '\\') i++;
        std::string temp = "";
        while (i < n && dirName[i] != '\\') {
            temp += dirName[i];
            i++;
        }
        fileName += "_" + temp;
    }
    return fileName;
}

FileDataBase* FileDataBase::fileDBPtr = nullptr;
  
IDataBase * FileDataBase::getInstance() {
    if (fileDBPtr == nullptr) {
        fileDBPtr = new FileDataBase;
    }
    return fileDBPtr;
}

void FileDataBase::save(std::filesystem::path dirPath, std::unordered_map<std::string, int> fileMap,
	std::unordered_map<std::string, std::vector<Location>> wordMap) {

    std::filesystem::path current = std::filesystem::current_path();
    std::filesystem::path projectRoot = current.parent_path();

    std::filesystem::path dataDir = projectRoot / "Data";

    if (std::filesystem::exists(dataDir) && std::filesystem::is_directory(dataDir)) {
        std::cout << "Data folder exists\n";
    }
    else {
        std::filesystem::create_directory(dataDir);
    }

    std::cout << current << std::endl;
    std::cout << projectRoot << std::endl;

    std::string dataFileName = createDataFileName(dirPath);

    std::filesystem::path filePath = dataDir / dataFileName;

    std::ofstream file(filePath);
    if (std::filesystem::exists(filePath)) {
        std::cout << "Folder created\n";
    }

    file << "{\n";
    for (auto f : fileMap) {
        file << f.second << ":" << f.first << "\n";
    }
    file << "}\n";

    file << "{\n";
    for (auto wordInfo : wordMap) {
        file << wordInfo.first << ":";
        for (auto locations : wordInfo.second) {
            file << "[" << locations.lineNumber << "," << locations.fileIndex << "]";
        }
        file << "\n";
    }
    file << "}\n";
}

void FileDataBase::load(std::filesystem::path& dirPath, std::unordered_map<std::string, int>& fileMap,
    std::unordered_map<std::string, std::vector<Location>>& wordMap) {
    std::filesystem::path current = std::filesystem::current_path();
    std::filesystem::path projectRoot = current.parent_path();

    std::filesystem::path dataDir = projectRoot / "Data";

    // Say doesn't exist

    std::string dataFileName = createDataFileName(dirPath);

    std::filesystem::path filePath = dataDir / dataFileName;

    std::ifstream file(filePath);

    std::string line;
    getline(file, line);
    getline(file, line);
    while (!file.eof()) {
        if (line[0] == '}') break;
        int n = line.size();
        int i = 0;
        std::string temp = "";
        while (i < n && line[i] != ':') {
            temp += line[i];
            i++;
        }
        int fIdx = std::stoi(temp);
        std::string filePath = line.substr(i + 1);
        fileMap[filePath] = fIdx;
        getline(file, line);
    }
    getline(file, line);
    getline(file, line);
    while (!file.eof()) {
        int i = 0;
        int n = line.size();
        std::string word = "";
        while (i < n && line[i] != ':') {
            word += line[i];
            i++;
        }
        i += 2;
        while(i < n){
            std::string lNo = "";
            while (i < n && line[i] != ',') {
                lNo = line[i];
                i++;
            }
            int lineNo = std::stoi(lNo);
            i++;
            std::string fNo = "";
            while (i < n && line[i] != ']') {
                fNo += line[i];
                i++;
            }
            int fileNo = std::stoi(fNo);
            Location location(lineNo, fileNo);
            wordMap[word].push_back(location);
            i++;
        }
        std::getline(file, line);
    }
}
