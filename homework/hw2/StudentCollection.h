#include "Student.h"

#ifndef STUDENT_COLLECTION
#define STUDENT_COLLECTION

enum SortDirection {asc, desc};
enum SortParameter {name, age, subject, grade, date};

class StudentCollection {
	Student* students;
	int size;
	int capacity;

	void clear();
	void copy(StudentCollection& other);
	void expand();

	void gradeSort(SortDirection sortDirection);
	void mergeSort(SortDirection sortDirection, SortParameter sortParameter);
	void heapSort(SortDirection sortDirection, SortParameter sortParameter);
public:
	StudentCollection();
	StudentCollection(StudentCollection& other);
	StudentCollection operator=(StudentCollection& other);
	~StudentCollection();

	void add(Student& newStudent);
	void print();

	void sort(SortDirection sortDirection, SortParameter sortParameter);
};

void heapifyNode(Student* students, int nodeIndex, int size, 
				 SortParameter sortParameter, int cmpExpectation);
int studentCmp(Student& first, Student& second, SortParameter parameter);

#endif
