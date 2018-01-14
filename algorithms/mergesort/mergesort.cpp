#include<iostream>
using namespace std;

void mergesort(int* arr, int startIndex, int endIndex) {
	if(startIndex - endIndex == 0) {
		return;
	}

	mergesort(arr, startIndex, startIndex + ((endIndex - startIndex)/2));
	mergesort(arr, startIndex + ((endIndex - startIndex)/2) + 1, endIndex);

	const int size = endIndex - startIndex + 1;
	int tempArr[size];

	int middleIndex = startIndex + ((endIndex - startIndex) / 2) + 1;
	int firstIndex = startIndex;
	int secondIndex = middleIndex;

	while(firstIndex < middleIndex || secondIndex <= endIndex) {
        int index = firstIndex + secondIndex - startIndex - middleIndex;
		if((secondIndex > endIndex) || (firstIndex < middleIndex && arr[firstIndex] < arr[secondIndex])) {
			tempArr[index] = arr[firstIndex++];
		} else {
			tempArr[index] = arr[secondIndex++];
		}
	}

	for(int i = 0; i < size; ++i) {
		arr[startIndex + i] = tempArr[i];
	}
}

void mergesort(int* arr, int size) {
	mergesort(arr, 0, size - 1);
}

int main () {
	int arr[] = {560, 12, -1, 5231, 19, 18, 17, 6, -10, 20, 12};
	int size = 11;

	mergesort(arr, size);

	for(int i= 0; i<size; ++i) {
		cout<< arr[i] << endl;
	}

	return 0;
}
