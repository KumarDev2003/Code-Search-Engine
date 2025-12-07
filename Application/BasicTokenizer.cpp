#include "BasicTokenizer.h"
#include <iostream>

std::vector<std::string> BasicTokenizer::tokenize(std::string line) {
	std::vector<std::string> words;
	int n = line.size();
	int i = 0;
	while (i < n) {
		while (i < n && !((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))) { i++; }
		std::string word = "";
		while (i < n && (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
			if (line[i] >= 'a' && line[i] <= 'z') {
				word += line[i];
			}
			else {
				word += (char)(line[i] - 'A' + 'a');
			}
			i++;
		}
		words.push_back(word);
	}
	return words;
}
