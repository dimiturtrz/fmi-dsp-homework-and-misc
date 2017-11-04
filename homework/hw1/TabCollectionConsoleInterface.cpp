#include <iostream>
#include <iomanip>

#include "MyStrings.h"
#include "TabCollectionConsoleInterface.h"

TabCollectionConsoleInterface::TabCollectionConsoleInterface() {
	gettingInput = false;
	tabCollection = TabCollection();
}

void TabCollectionConsoleInterface::interpretInput(const char* command, const char* argument) {
	if(strcmp(command, "GO") == 0) {
		tabCollection.openUrl(argument);
	} else if(strcmp(command, "INSERT") == 0) {
		tabCollection.openTab(argument);
	} else if(strcmp(command, "BACK") == 0) {
		tabCollection.goBackwards();
	} else if(strcmp(command, "FORWARD") == 0) {
		tabCollection.goForward();
	} else if(strcmp(command, "REMOVE") == 0) {
		tabCollection.closeCurrentTab();
	} else if(strcmp(command, "PRINT") == 0) {
		tabCollection.print();
	} else if(strcmp(command, "SORT") == 0) {
		if(strcmp(argument, "TIME") == 0) {
			tabCollection.sort(Time);
		} else if(strcmp(argument, "URL") == 0) {
			tabCollection.sort(URL);
		}		
	} else if(strcmp(command, "EXIT") == 0) {
		stopGettingInput();
	}
}

void TabCollectionConsoleInterface::startGettingInput() {
	gettingInput = true;
	char command[9]; // to be able to hold the longest command ("FORWARD", 7) + one extra char if we get something like "FORWARDS" (as it's wrong) + \0
	char argument[512];
	
	while(gettingInput) {
		std::cin>> std::setw(9)>> command;
		if(std::cin.peek() == ' ')
			std::cin.ignore();
		std::cin.getline(argument, 511);
		interpretInput(command, argument);
	}
}

void TabCollectionConsoleInterface::stopGettingInput() {
	gettingInput = false;
}
