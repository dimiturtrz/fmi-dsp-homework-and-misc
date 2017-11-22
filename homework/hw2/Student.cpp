#include <iostream>
#include "Student.h"
#include "MyStrings.h"

// ------------------------------ HELPER --------------------------------
void Student::copy(const Student& other) {
	dynamicStrCpy(name, other.name);
	age = other.age;
	dynamicStrCpy(subject, other.subject);
	grade = other.grade;
	dynamicStrCpy(date, other.date);
}

// ---------------------------- BIG FOUR --------------------------------

Student::Student(): name(NULL), subject(NULL), date(NULL) {}
Student::Student(const char* name, int age, const char* subject,
				int grade, const char* date):
				name(NULL), age(age), subject(NULL), grade(grade), date(NULL) {
	dynamicStrCpy(this->name, name);
	dynamicStrCpy(this->subject, subject);
	dynamicStrCpy(this->date, date);
}

Student::Student(const Student& other): name(NULL), subject(NULL), date(NULL) {
	copy(other);
}

Student& Student::operator=(const Student& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}

Student::~Student() {
	delete [] name;
	delete [] subject;
	delete [] date;
}

void Student::print() {
	std::cout<< name<< ", "<< age<< ", "<< subject<< ", "<< grade<< ", "<< date;
}
