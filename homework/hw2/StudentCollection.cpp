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

// --------------------------- SORTING ----------------------------------
void StudentCollection::sort(SortDirection sortDirection, SortParameter sortParameter) {
	switch(sortParameter) {
		case name:
			mergeSort(sortDirection, sortParameter);
			break;
		case age:
			heapSort(sortDirection, sortParameter);
			break;
		case subject:
			mergeSort(sortDirection, sortParameter);
			break;
		case grade:
			gradeSort(sortDirection);
			break;
		case date:
			mergeSort(sortDirection, sortParameter);
			break;
	}
}

void StudentCollection::gradeSort(SortDirection sortDirection) {
	int start = (sortDirection == asc) ? 2 : 6;
	int end = (start == 6) ? 2 : 6;
	int step = (sortDirection == asc) ? 1 : -1;

	Student* sortedStudents = new Student[size];
	int sortedIndex = 0;
	for(int currentGrade; currentGrade != end; currentGrade += step) {
		for(int studentIndex = 0; studentIndex < size; ++studentIndex) {
			if(students[studentIndex].gradeCmp(currentGrade) == 0) {
				sortedStudents[sortedIndex++] = students[studentIndex];
			}
		}
	}

	delete [] students;
	students = sortedStudents;
}

void StudentCollection::mergeSort(SortDirection sortDirection, SortParameter sortParameter) {
	Student* secondaryArray = new Student[size];
	Student* primaryArray = students;

	int swapCmpResult = (sortDirection == asc) ? -1 : 1;
	
	for(int chunkSize = 2; chunkSize < size*2; chunkSize *= 2) {
		int chunkHalf = chunkSize/2;
		int chunks = size/chunkSize + ((size%chunkSize > chunkHalf) ? 1 : 0);
		for(int currChunk = 0; currChunk < chunks; ++currChunk) {
			int start = chunkSize*currChunk;
			int end = (start + chunkSize < size) ? (start + chunkSize) : size;
			int leftIndex = 0, rightIndex = chunkHalf;
			while(leftIndex < chunkHalf || rightIndex < end - start) {
				if((rightIndex >= end - start) || (leftIndex < chunkHalf && 
					studentCmp(primaryArray[start + leftIndex],
							   primaryArray[start + rightIndex], 
							   sortParameter) == swapCmpResult)) {
					secondaryArray[start + leftIndex + rightIndex - chunkHalf] = primaryArray[start + leftIndex];
					leftIndex++;
				} else {
					secondaryArray[start + leftIndex + rightIndex - chunkHalf] = primaryArray[start + rightIndex];
					rightIndex++;
				}
			}
		}

		if(size%chunkSize <= chunkHalf) { // remaining sorted indices
			for(int index = chunks*chunkSize; index<size; ++index) {
				secondaryArray[index] = primaryArray[index];
			}
		}

		Student* temp = secondaryArray;
		secondaryArray = primaryArray;
		primaryArray = temp;
	}

	students = primaryArray;
	delete [] secondaryArray;
}

void StudentCollection::heapSort(SortDirection sortDirection, SortParameter sortParameter) {
	int swapCmpResult = (sortDirection == asc) ? -1 : 1;
	for (int i = size/2; i>=0; --i) {
		heapifyNode(students, i, size, sortParameter, swapCmpResult);
	}

	int unsortedSize = size;
	while (unsortedSize > 1) {
		students[0].swapData(students[unsortedSize-1]);
		heapifyNode(students, 0, --unsortedSize, sortParameter, swapCmpResult);
	}
}

void heapifyNode(Student* students, int nodeIndex, int size, SortParameter sortParameter, int cmpExpectation) {
	int leftNodeIndex = 2*nodeIndex + 1, rightNodeIndex = leftNodeIndex + 1;

	if(leftNodeIndex < size && (studentCmp(students[nodeIndex], students[leftNodeIndex], sortParameter) == cmpExpectation)) {
		students[nodeIndex].swapData(students[leftNodeIndex]);
		heapifyNode(students, leftNodeIndex, size, sortParameter, cmpExpectation);
	}
	if(rightNodeIndex < size && (studentCmp(students[nodeIndex], students[rightNodeIndex], sortParameter) == cmpExpectation)) {
		students[nodeIndex].swapData(students[rightNodeIndex]);
		heapifyNode(students, rightNodeIndex, size, sortParameter, cmpExpectation);
	}
}

int studentCmp(Student& first, Student& second, SortParameter parameter) {
	switch(parameter) {
		case name:
			return first.nameCmp(second);
		case age:
			return first.ageCmp(second);
		case subject:
			return first.subjectCmp(second);
		case grade:
			return first.gradeCmp(second);
		case date:
			return first.dateCmp(second);
	}
}
