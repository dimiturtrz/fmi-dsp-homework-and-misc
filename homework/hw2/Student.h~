#include <iostream>

#ifndef STUDENT
#define STUDENT

class Student {
	char* name;
	int age;
	char* subject;
	int grade;
	char* date;

	void copy(Student& other);
public:
	Student(const char* name = NULL, int age = 0, const char* subject = NULL,
			int grade = 2, const char* date = NULL);

	Student(Student& other);
	Student& operator=(Student& other);
	~Student();
};

std::ostream operator<<(std::ostream& stream, Student& student);

#endif
