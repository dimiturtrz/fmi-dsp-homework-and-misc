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

// ---------------------------- PUBLIC COMPARERS ------------------------------
int Student::nameCmp(const char* otherName) {
	return strcmp(name, otherName);
}
int Student::ageCmp(const int otherAge) {
	if(age == otherAge) {
		return 0;
	}
	return (age > otherAge) ? 1 : -1;
}
int Student::subjectCmp(const char* otherSubject) {
	return strcmp(subject, otherSubject);
}
int Student::gradeCmp(const int otherGrade) {
	if(grade == otherGrade) {
		return 0;
	}
	return (grade > otherGrade) ? 1 : -1;
}
int Student::dateCmp(const char* otherDate) {
	return strcmp(date, otherDate);
}

int Student::nameCmp(const Student& other) {
	return strcmp(name, other.name);
}

int Student::ageCmp(const Student& other) {
	return ageCmp(other.age);
}

int Student::subjectCmp(const Student& other){
	return strcmp(subject, other.subject);
}

int Student::gradeCmp(const Student& other){
	return gradeCmp(other.age);
}

int Student::dateCmp(const Student& other){
	return strcmp(date, other.date);
}

// --------------------------- SWAP ------------------------------------------

void Student::swapData(Student& other) {
	Student tmp(other);
	other = *this;
	*this = tmp;
}

// --------------------------- PRINTS ------------------------------------------
void Student::print() {
	std::cout<< (name != NULL ? name : "NULL")<< ", "<< age<< ", "
 			 << (subject != NULL ? subject : "NULL")<< ", "<< grade<< ", "
			 << (date != NULL ? date : "NULL");
}
