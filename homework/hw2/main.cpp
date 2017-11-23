#include <iostream>
#include <fstream>
#include "MyStrings.h"
#include "StudentCollection.h"

using namespace std;

void readCollectionFromFile(StudentCollection& collection, const char* fileName);
void sortCollection(StudentCollection& collection, const char* sortArgStr, const char* sortDirStr);

int main (int argc, const char * argv[]) {
	const char* fileName = argv[1];
	const char* sortDir = argv[2];
	const char* sortArg = argv[3];

	StudentCollection sc;
	readCollectionFromFile(sc, fileName);
	sortCollection(sc, sortArg, sortDir);

	sc.print();
	return 0;
}

void readCollectionFromFile(StudentCollection& collection, const char* fileName) {
	ifstream file;
	file.open(fileName);

	char nameBuffer[1024];
	int age;
	char subjectBuffer[1024];
	int grade;
	char dateBuffer[1024];

	while(file.getline(nameBuffer, 1023, ',')) {
		file>> age;
		file.ignore();
		file.getline(subjectBuffer, 1023, ',');
		file>> grade;
		file.ignore();
		file.getline(dateBuffer, 1023, '\n');
	
		Student readStudent(nameBuffer, age, subjectBuffer, grade, dateBuffer);
		collection.add(readStudent);
	}
	
	file.close();
}

void sortCollection(StudentCollection& collection, const char* sortArgStr, const char* sortDirStr) {
	SortDirection direction = ((strcmp(sortDirStr, "asc") == 0) ? asc : desc);
	SortParameter parameter = date;
	if (strcmp(sortArgStr, "name") == 0) {
		parameter = name;
	} else if (strcmp(sortArgStr, "age") == 0) {
		parameter = age;
	} else if (strcmp(sortArgStr, "subject") == 0) {
		parameter = subject;
	} else if (strcmp(sortArgStr, "grade") == 0) {
		parameter = grade;
	}

	collection.sort(direction, parameter);
}
