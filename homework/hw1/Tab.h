#ifndef TAB_H
#define TAB_H

#include <time.h>
#include <iostream>
using namespace std;

class Tab {
	char* url;
	time_t timestamp;

	Tab* next;
	Tab* prev;

	void copy(const Tab& other);

public:
	Tab(const char* url = " about:blank", Tab* prev = NULL, Tab* next = NULL);
	Tab(const Tab& other);
	Tab& operator=(const Tab& other);
	~Tab();

	Tab* getNext();
	Tab* getPrev();

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
