#include <iostream>
#include <iomanip>

#include "MyStrings.h"
#include "FileTreeConsoleInterface.h"

FileTreeConsoleInterface::FileTreeConsoleInterface(const char* folderPath, const char* pattern): fileTree(FileTree(folderPath, pattern)) {
	gettingInput = false;
}

void FileTreeConsoleInterface::interpretInput(const char* command, const char* argument) {
	if(strcmp(command, "refresh") == 0) {
		fileTree.refresh();
	} else if(strcmp(command, "print") == 0) {
        int patternIndex = 0;
        for(; argument[patternIndex] == ' '; ++patternIndex);
        if(strcmp(argument + patternIndex, "") == 0) {
            fileTree.print();
        } else {
            fileTree.print(argument);
        }
	} else if(strcmp(command, "quit") == 0) {
		stopGettingInput();
	}
}

void FileTreeConsoleInterface::startGettingInput() {
	gettingInput = true;
	char command[9]; // to be able to hold the longest command ("refresh", 7) + one extra char if we get something like "refreshs" (as it's wrong) + \0
	char argument[512];

	while(gettingInput) {
		std::cin>> std::setw(9)>> command;
		if(std::cin.peek() == ' ')
			std::cin.ignore();
		std::cin.getline(argument, 511);
		interpretInput(command, argument);
	}
}

void FileTreeConsoleInterface::stopGettingInput() {
	gettingInput = false;
}
