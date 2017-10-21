#include <time.h>
#include <iostream>
using namespace std;

#ifndef TAB_H
#define TAB_H

class Tab {
	char* url;
	time_t timestamp;

	Tab* next;
	Tab* prev;

	void copy(const Tab& other);

public:
	Tab(const char* url = "about:blank", Tab* next = NULL, Tab* prev = NULL);
	Tab(const Tab& other);
	Tab& operator=(const Tab& other);
	~Tab();

	const Tab* getNext() const;
	const Tab* getPrev() const;

	void setNext(Tab* newNext);
	void setPrev(Tab* newPrev);

	const char* getUrl() const;
	void setUrl(const char* newName);

	time_t getTimestamp() const;
	void resetTimestamp();
};

ostream& operator<<(ostream& stream, const Tab& tab);

#endif
