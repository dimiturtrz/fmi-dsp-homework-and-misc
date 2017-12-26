#ifndef BASE_FILE
#define BASE_FILE 

class BaseFile {
protected:
	char* name;

	virtual void copy(const BaseFile& other);
	virtual void clear();
public:
	BaseFile(const char* name);
	BaseFile(const BaseFile& other);
	BaseFile& operator=(const BaseFile& other);
	virtual ~BaseFile();

	void setName(const char* newName);
	const char* getName() const;
};

#endif
