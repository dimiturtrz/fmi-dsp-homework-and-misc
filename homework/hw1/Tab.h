#include<time.h>

#ifndef TAB_H
#define TAB_H

class Tab {
	char* url;
	time_t timestamp;

	Tab* next;
	Tab* prev;

	void copy(const Tab& other);

public:
	Tab(char* url = "about:blank", Tab* next = NULL, Tab* prev = NULL);
	Tab(const Tab& other);
	Tab& operator=(const Tab& other);
	~Tab();

	Tab* getNext();
	Tab* getPrev();

	void setNext(Tab* newNext);
	void setPrev(Tab* newPrev);

	char* getUrl();
	void setUrl(char* newName);

	time_t getTimestamp();
};

#endif
