#ifndef FILE
#define FILE 

class File {
private:
	char* name;
	int size;

	void copy(const File& other);
	void clear();
public:
	File(const char* name, int size);
	File(const File& other);
	File& operator=(const File& other);
	~File();

	void setName(const char* newName);
	void setSize(int newSize);

	const char* getName();
	int getSize();
};

#endif
