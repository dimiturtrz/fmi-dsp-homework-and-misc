#include <iostream>
#include "StudentCollection.h"

// ------------------------------ HELPER -------------------------------
void StudentCollection::clear() {
	delete [] students;
	students = NULL;
	capacity = size = 0;
}

void StudentCollection::copy(StudentCollection& other) {
	delete [] students;
	capacity = size = other.size;

	students = new Student[capacity];
	for(int i=0; i<size; ++i) {
		students[i] = other.students[i];
	}
}
	
void StudentCollection::expand() {
	capacity = (capacity == 0 ? 2 : capacity*2);
	Student* temp = new Student[capacity];
	for(int i=0; i< size; ++i) {
		temp[i] = students[i];
	}
	delete [] students;
	students = temp;
}

// ---------------------------- BIG FOUR -------------------------------

StudentCollection::StudentCollection(): size(0), capacity(0), students(NULL) {}

StudentCollection::StudentCollection(StudentCollection& other) {
	copy(other);
}
StudentCollection StudentCollection::operator=(StudentCollection& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}

StudentCollection::~StudentCollection() {
	clear();
}

// ---------------------------- ADDERS AND STUFF ------------------------
void StudentCollection::add(Student& newStudent) {
	if(size+1 > capacity) {
		expand();
	}
	students[size++] = newStudent;
}

void StudentCollection::print() {
	for(int i=0; i<size; ++i) {
		students[i].print();
		std::cout<< std::endl;
	}
}
