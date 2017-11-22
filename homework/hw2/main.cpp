#include <iostream>
#include <fstream>
#include "MyStrings.h"
#include "StudentCollection.h"

using namespace std;

int main (int argc, const char * argv[]) {
	const char* fileName = argv[1];
	const char* sortArg = argv[2];
	const char* sortDir = argv[3];

	ifstream file;
	file.open(fileName);
	
	StudentCollection sc;
	Student st1("pesho", 12, "js", 3, "2012-12-05");
	sc.add(st1);
	Student st2("tesho", 12, "js", 3, "2012-12-05");
	sc.add(st2);
	Student st3("gesho", 12, "js", 3, "2012-12-05");
	sc.add(st3);
	sc.print();
	
	file.close();

	return 0;
}
