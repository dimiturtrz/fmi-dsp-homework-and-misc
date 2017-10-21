#ifndef TAB_COLLECTION_CONSOLE_INTERACE
#define TAB_COLLECTION_CONSOLE_INTERACE

#include "TabCollection.h"

class TabCollectionConsoleInterface {
	bool gettingInput;
	TabCollection tabCollection;

public:

	TabCollectionConsoleInterface();

	void interpretInput(const char* command, const char* argument);
	void startGettingInput();
	void stopGettingInput();
};

#endif

