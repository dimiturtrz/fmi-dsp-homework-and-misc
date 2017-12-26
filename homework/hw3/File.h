#include "BaseFile.h"

#ifndef FILE
#define FILE

class File: public BaseFile {
private:
	int size;

	void copy(const File& other);
public:
	File(const char* name, int size);
	
	void setSize(int newSize);
	int getSize();
};

#endif
