#include "Tab.h"
#include "MyStrings.h"
#include <time.h>
#include <iostream>
using namespace std;

// -------------------------- HELPER --------------------------
void Tab::copy(const Tab& other) {
	setUrl(other.url);
	timestamp = other.timestamp;
}

// ------------------------ BIG FOUR --------------------------
Tab::Tab(const char* url, Tab* prev, Tab* next) : url(NULL) {
	setNext(next);
	setPrev(prev);

	setUrl(url);
	timestamp = time(NULL);
}

Tab::Tab(const Tab& other): url(NULL), prev(other.prev), next(other.next) {
	copy(other);
}

Tab& Tab::operator=(const Tab& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}

Tab::~Tab() {
	delete [] url;
}

// --------------------- GETTERS, SETTERS ---------------------

Tab* Tab::getNext() {
	return next;
}
Tab* Tab::getPrev() {
	return prev;
}

const Tab* Tab::getNext() const {
	return next;
}
const Tab* Tab::getPrev() const {
	return prev;
}

void Tab::setNext(Tab* newNext){
	next = newNext;

	if(newNext != NULL) {
		newNext->prev = this;
	}
}
void Tab::setPrev(Tab* newPrev){
	prev = newPrev;

	if(newPrev != NULL) {
		newPrev->next = this;
	}
}

const char* Tab::getUrl() const {
	return url;
}
void Tab::setUrl(const char* newUrl) {
	delete [] url;

	int length = 0;
	for(; newUrl[length] != '\0'; ++length);

	url = new char[length];

	for(int i = 0; i < length; ++i) {
		url[i] = newUrl[i];
	}
}

time_t Tab::getTimestamp() const {
	return timestamp;
}
void Tab::resetTimestamp() {
	timestamp = time(NULL);
}

// ---------------- COMPARATORS ----------------------

int Tab::timecmp(const Tab& other) const {
	if(timestamp == other.timestamp) {
		return 0;
	}
	return timestamp > other.timestamp ? 1 : -1;
}
int Tab::urlcmp(const Tab& other) const {
	return strcmp(url, other.url);
}

// --------------------- SWAP ------------------------

void Tab::swapData(Tab* other) {
	Tab temp(*this);
	
	this->copy(*other);
	other->copy(temp);
}

// --------------------- PRINTS ----------------------

ostream& operator<<(ostream& stream, const Tab& tab) {
	stream<< tab.getUrl()<< " "<< tab.getTimestamp();
	return stream;
}
