#include <iostream>
using namespace std;

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
	} else if(strcmp(command, "EXIT") == 0) {
		stopGettingInput();
	}
}

void TabCollectionConsoleInterface::startGettingInput() {
	gettingInput = true;
	char command[6];
	char argument[512];
	while(gettingInput) {
		std::cin>> command;
		std::cin.getline(argument, 511);
		interpretInput(command, argument);
	}
}
void TabCollectionConsoleInterface::stopGettingInput() {
	gettingInput = false;
}
