#ifndef TAB_COLLECTION_H
#define TAB_COLLECTION_H

#include "Tab.h"
#include <iostream>

class TabCollection {
	Tab* firstTab;
	Tab* currentTab;
	
	void copy(const TabCollection& other);
	void clear();

	int count() const; // too slow for public

public:
	TabCollection();
	TabCollection(const TabCollection& other);
	TabCollection& operator=(const TabCollection& other);
	~TabCollection();

	bool isThereOneTab() const;

	void openTab(const char* url);
	void closeCurrentTab();

	void openUrl(const char* url = "about:blank");
	void goBackwards();
	void goForward();

	void selectionSort(TabSortableParameters parameter);
	void mergeSort(TabSortableParameters parameter);
	Tab* mergeSortHelper(Tab* currentFirstTab, TabSortableParameters parameter, int count);

	void print() const;

	const Tab* getCurrentTab() const;
	const Tab* getFirstTab() const;
};

std::ostream& operator<<(std::ostream& stream, const TabCollection& tabCollection);

#endif
