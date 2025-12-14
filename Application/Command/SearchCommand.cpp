#include <iostream>

#include "SearchCommand.h"
#include "BasicSearchEngine.h"
#include "SearchStrategy.h"
#include "ResultData.h"

void SearchCommand::execute(std::string word) {
	std::unique_ptr<ISearchEngine> basicSearchEngine = SearchStrategy::strategy("basic");
	ResultData resultData = basicSearchEngine->search(word);
	std::cout << "\nTotal occurnce of \"" << word << "\" is " << resultData.wordLocations.size() << std::endl;
	for (Location word : resultData.wordLocations) {
		std::cout << "{\n";
		std::cout << resultData.fileIndex[word.fileIndex] << "\n";
		std::cout << "Line no. " << word.lineNumber << std::endl;
		std::cout << "}\n";
	}
}