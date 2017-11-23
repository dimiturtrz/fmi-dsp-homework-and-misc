#include <iostream>

#ifndef STUDENT
#define STUDENT

class Student {
	char* name;
	int age;
	char* subject;
	int grade;
	char* date;

	void copy(const Student& other);
public:
	Student();
	Student(const char* name, int age, const char* subject,
			int grade, const char* date);

	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	int nameCmp(const char* otherName);
	int ageCmp(const int otherAge);
	int subjectCmp(const char* otherSubject);
	int gradeCmp(const int otherGrade);
	int dateCmp(const char* otherDate);

	void print();
};

#endif
