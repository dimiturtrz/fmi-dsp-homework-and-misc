#include "Tab.h"
#include <time.h>

void Tab::copy(const Tab& other) {
	setUrl(other.url);
	timestamp = other.timestamp;
}

Tab::Tab(char* url, Tab* next, Tab* prev) : url(NULL), next(next), prev(prev) {
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

Tab* Tab::getNext() {
	return next;
}
Tab* Tab::getPrev(){
	return prev;
}

void Tab::setNext(Tab* newNext){
	next = newNext;
}
void Tab::setPrev(Tab* newPrev){
	prev = newPrev;
}

char* Tab::getUrl(){
	return url;
}
void Tab::setUrl(char* newUrl) {
	delete [] url;

	int length = 0;
	for(; newUrl[length] != '\0'; ++length);

	url = new char[length];

	for(int i = 0; i < length; ++i) {
		url[i] = newUrl[i];
	}
}

time_t Tab::getTimestamp(){
	return timestamp;
}
