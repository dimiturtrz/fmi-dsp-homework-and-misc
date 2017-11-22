#include <iostream>
#include <fstream>
#include "MyStrings.h"
#include "StudentCollection.h"

using namespace std;

void readCollectionFromFile(StudentCollection& collection, const char* fileName);

int main (int argc, const char * argv[]) {
	const char* fileName = argv[1];
	const char* sortArg = argv[2];
	const char* sortDir = argv[3];

	StudentCollection sc;

	readCollectionFromFile(sc, fileName);

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

	while(file) {
		if(file.peek() == -1) { // TODO: check!!!
			break;
		}

		file.getline(nameBuffer, 1023, ',');
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
