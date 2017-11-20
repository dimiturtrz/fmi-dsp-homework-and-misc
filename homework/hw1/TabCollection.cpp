#include "TabCollection.h"
#include "Tab.h"

#include <iostream>

// ---------------------- HELPER ----------------------------
void TabCollection::copy(const TabCollection& other){
	clear();
	firstTab = new Tab(*(other.firstTab));
	Tab* iter = firstTab;

	if (other.isThereOneTab()) {
		currentTab = firstTab;
		return;
	}

	for(const Tab* otherIter = other.firstTab->getNext();
		otherIter != NULL;
		otherIter = otherIter->getNext()) {

		Tab* newTab = new Tab(otherIter->getUrl(), iter);
		iter = newTab;

		if(other.currentTab == otherIter) {
			currentTab = iter;
		}
	}
}

void TabCollection::clear() {
	const Tab* iter = firstTab;
	const Tab* nextIter = firstTab;
	while(nextIter != NULL) {
		nextIter = nextIter->getNext();
		delete iter;
		iter = nextIter;
	}

	firstTab = NULL;
	currentTab = NULL;
}

bool TabCollection::isThereOneTab() const {
	return (firstTab->getNext() == NULL);
}

int TabCollection::count() const {
	int count = 0;
	const Tab* iter = firstTab;
	for(; iter != NULL; count++, iter = iter->getNext());
	return count;
}

// ------------------------- BIG FOUR ----------------------------

TabCollection::TabCollection(): firstTab(NULL), currentTab(NULL) {
	firstTab = new Tab();
	currentTab = firstTab;
}

TabCollection::TabCollection(const TabCollection& other) {
	copy(other);
}

TabCollection& TabCollection::operator=(const TabCollection& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}

TabCollection::~TabCollection() {
	clear();
}

// ------------------- GETTERS, SETTERS --------------------

const Tab* TabCollection::getCurrentTab() const {
	return currentTab;
}
const Tab* TabCollection::getFirstTab() const {
	return firstTab;
}

// ------------------ CREATION, DELETION --------------------

void TabCollection::openTab(const char* url) {
	currentTab = new Tab(url, currentTab, currentTab->getNext());
}

void TabCollection::closeCurrentTab() {
	if(isThereOneTab()) {
		return openUrl();
	}

	bool isThereNextTab = (currentTab->getNext() != NULL);
	Tab* newCurrentTab = isThereNextTab ? currentTab->getNext() : currentTab->getPrev();

	if(currentTab != firstTab) {
		currentTab->getPrev()->setNext(currentTab->getNext());
	} else {
		firstTab = currentTab->getNext();
		firstTab->setPrev(NULL);
	}

	delete currentTab;
	currentTab = newCurrentTab;
}

// ----------------------- NAVIGATION --------------------------

void TabCollection::openUrl(const char* url) {
	currentTab->setUrl(url);
}

void TabCollection::goBackwards() {
	Tab* prevTab = currentTab->getPrev();
	if(prevTab != NULL) {
		currentTab = prevTab;
	}
}
void TabCollection::goForward() {
	Tab* nextTab = currentTab->getNext();
	if(nextTab != NULL) {
		currentTab = nextTab;
	}
}

// ------------------------ PRINTS -----------------------------

void TabCollection::print() const {
	std::cout<< *this;
}

std::ostream& operator<<(std::ostream& stream, const TabCollection& tabCollection) {
	for(const Tab* iter = tabCollection.getFirstTab(); iter != NULL; iter = iter->getNext()) {
		if(iter == tabCollection.getCurrentTab()) {
			std::cout<< "> ";
		}
		std::cout<< *iter<< std::endl;
	}
}

// ----------------------- SORT --------------------------------

void TabCollection::selectionSort(TabSortableParameters parameter) {
	Tab* currMin = NULL;
	for(Tab* outerIter = firstTab; outerIter != NULL; outerIter = outerIter->getNext()) {
		currMin = outerIter;
		for(Tab* innerIter = outerIter; innerIter != NULL; innerIter = innerIter->getNext()) {
			if(currMin->cmp(*innerIter, parameter) == 1) {
				currMin = innerIter;
			}
		}
		if(currMin != outerIter) {
			outerIter->swapData(currMin);
			if(currMin == currentTab || outerIter == currentTab) {
				currentTab = (currMin == currentTab) ? outerIter : currMin;
			}
		}
	}
}

void TabCollection::mergeSort(TabSortableParameters parameter) {
	mergeSortHelper(firstTab, parameter, count());
	for(; firstTab->getPrev(); firstTab = firstTab->getPrev());
}

Tab* TabCollection::mergeSortHelper(Tab* currentFirstTab, TabSortableParameters parameter, int count) {
	Tab* center = currentFirstTab;
	for(int counter = count/2; counter > 0; center = center->getNext(), --counter);

	if(count != 1) {
		currentFirstTab = mergeSortHelper(currentFirstTab, parameter, count/2);
		center = mergeSortHelper(center, parameter, count - count/2);
	}

	std::cout<< "\n\n\n"<< count<< "\n\n\n";
	int inCount = count;
	for(Tab* iter = currentFirstTab; inCount > 0; iter = iter->getNext(), inCount--) {
		std::cout<< (iter != NULL ? iter->getUrl() : "NULL")<< " ";
	}
	std::cout<< "-> ";

	Tab* firstHalfIter = currentFirstTab;
	Tab* secondHalfIter = center;
	Tab* iterPrev = currentFirstTab->getPrev();


	for(int count1 = count/2, count2 = count - count/2;
		count1 > 0 || count2 > 0;) {
		Tab* nextTab = NULL;
		
		//std::cout<< count1<< " "<< count2<< " "<< 
				//(firstHalfIter != NULL ? firstHalfIter->getUrl() : "NULL")<< ","<< 
				//(secondHalfIter != NULL ? secondHalfIter->getUrl() : "NULL")<< " \n";
		if(count2 == 0 || 
		  (count1 > 0 && firstHalfIter->cmp(*secondHalfIter, parameter) <= 0)) {
			nextTab = firstHalfIter;
			firstHalfIter = firstHalfIter->getNext();
			--count1;
			//std::cout<< count1<< " 1 "<< 
				//(firstHalfIter != NULL ? firstHalfIter->getUrl() : "NULL")<< " \n";
		} else {
			nextTab = secondHalfIter;
			secondHalfIter = secondHalfIter->getNext();
			--count2;
			//std::cout<< count2<< " 2 "<< 
				//(secondHalfIter != NULL ? secondHalfIter->getUrl() : "NULL")<< " \n";
		}
		std::cout<< count1<< " "<< count2<< " "<< nextTab->getUrl()<< ","<< (iterPrev != NULL ? iterPrev->getUrl() : "NULL")<< " \n";
		if(iterPrev == currentFirstTab->getPrev()) {
			currentFirstTab = nextTab;
		}
		nextTab->setPrev(iterPrev);
		nextTab->setNext(NULL);
		iterPrev = nextTab;
	}
	std::cout<< std::endl;
	return currentFirstTab;
}

