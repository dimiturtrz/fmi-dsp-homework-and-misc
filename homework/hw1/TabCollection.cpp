#include "TabCollection.h"
#include "Tab.h"
#include <iostream>
using namespace std;

// ---------------------- HELPER ----------------------------
void TabCollection::copy(const TabCollection& other){
	clear();
	firstTab = new Tab(*(other.firstTab));
	Tab* iter = firstTab;

	if (other.isThereOneTab()) {
		currentTab = firstTab;
		return;
	}

	for(const Tab* otherIter = other.firstTab->getNext(); otherIter != NULL; otherIter = otherIter->getNext()) {

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

	currentTab->getPrev()->setNext(currentTab->getNext());

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
	cout<< *this;
}

ostream& operator<<(ostream& stream, const TabCollection& tabCollection) {
	for(const Tab* iter = tabCollection.getFirstTab(); iter != NULL; iter = iter->getNext()) {
		cout<< ">"<< *iter<< endl;
	}
}
