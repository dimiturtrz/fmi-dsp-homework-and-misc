#include "Student.h"
#include "MyStrings.h"

// ------------------------------ HELPER --------------------------------
void Student::copy(Student& other) {
	dynamicStrCpy(name, other.name);
	age = other.age;
	dynamicStrCpy(subject, other.subject);
	grade = other.grade;
	dynamicStrCpy(date, other.date);
}

// ---------------------------- BIG FOUR --------------------------------

Student::Student(const char* name, int age, const char* subject,
				int grade, const char* date):
				name(NULL), age(age), subject(NULL), grade(grade), date(NULL) {
	dynamicStrCpy(this->name, name);
	dynamicStrCpy(this->subject, subject);
	dynamicStrCpy(this->date, date);
}

Student::Student(Student& other) {
	copy(other);
}

Student& Student::operator=(Student& other) {
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

// ------------------------------- OUTPUT ------------------------------

std::ostream operator<<(std::ostream& stream, Student& student) {
	stream<< name<< ", "<< age<< ", "<< subject<< ", "<< grade<< ", "<< date;
}
