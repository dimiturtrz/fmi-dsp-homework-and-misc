#ifndef TAB_COLLECTION_H
#define TAB_COLLECTION_H

#include "Tab.h"
#include <iostream>
using namespace std;

class TabCollection {
	Tab* firstTab;
	Tab* currentTab;
	
	void copy(const TabCollection& other);
	void clear();

public:
	TabCollection();
	TabCollection(const TabCollection& other);
	TabCollection& operator=(const TabCollection& other);
	~TabCollection();

	bool isThereOneTab() const;

	void openTab(const char* url);
	void closeCurrentTab();

	void openUrl(const char* url = " about:blank");
	void goBackwards();
	void goForward();

	void print() const;

	const Tab* getCurrentTab() const;
	const Tab* getFirstTab() const;
};

ostream& operator<<(ostream& stream, const TabCollection& tabCollection);

#endif
