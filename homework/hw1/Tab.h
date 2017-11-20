#ifndef TAB_H
#define TAB_H

#include <time.h>
#include <iostream>

enum TabSortableParameters {Time, URL};

class Tab {
	char* url;
	time_t timestamp;

	Tab* next;
	Tab* prev;

	void copy(const Tab& other);

public:
	Tab(const char* url = "about:blank", Tab* prev = NULL, Tab* next = NULL);
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

	int timecmp(const Tab& other) const;
	int urlcmp(const Tab& other) const;

	int cmp(const Tab& other, TabSortableParameters parameter) const;

	void swapData(Tab* other);
};

std::ostream& operator<<(std::ostream& stream, const Tab& tab);

#endif
