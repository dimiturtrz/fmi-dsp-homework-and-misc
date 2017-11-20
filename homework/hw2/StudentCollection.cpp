#include <iostream>
#include "StudentCollection.h"

// ------------------------------ HELPER -------------------------------
void StudentCollection::clear() {
	delete [] students;
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
void StudentCollection::add(Student& newStudent) {}
void StudentCollection::print() {
	for(int i=0; i<size; ++i) {
		std::cout<< students[i]<< std::endl;
	}
}
