#include "Tab.h"
#include <time.h>
#include <iostream>
using namespace std;

void Tab::copy(const Tab& other) {
	setUrl(other.url);
	timestamp = other.timestamp;
}

Tab::Tab(const char* url, Tab* next, Tab* prev) : url(NULL), next(next), prev(prev) {
	setUrl(url);
	timestamp = time(NULL);
}
Tab::Tab(const Tab& other) {
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

const Tab* Tab::getNext() const {
	return next;
}
const Tab* Tab::getPrev() const {
	return prev;
}

void Tab::setNext(Tab* newNext){
	next = newNext;
}
void Tab::setPrev(Tab* newPrev){
	prev = newPrev;
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

ostream& operator<<(ostream& stream, const Tab& tab) {
	stream<< tab.getUrl()<< " "<< tab.getTimestamp();
	return stream;
}
