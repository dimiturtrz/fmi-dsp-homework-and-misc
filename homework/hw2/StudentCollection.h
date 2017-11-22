#include "Student.h"

#ifndef STUDENT_COLLECTION
#define STUDENT_COLLECTION

class StudentCollection {
	Student* students;
	int size;
	int capacity;

	void clear();
	void copy(StudentCollection& other);
	void expand();
public:
	StudentCollection();
	StudentCollection(StudentCollection& other);
	StudentCollection operator=(StudentCollection& other);
	~StudentCollection();

	void add(Student& newStudent);
	void print();
};

#endif
