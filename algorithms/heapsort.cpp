#include<iostream>
using namespace std;

void siftDown(int* arr, int size, int pos) {
	int childIndex = pos*2 + 1;
	int tmp = 0;

	while(childIndex < size) {
		childIndex += ((childIndex + 1 < size) && 
					   (arr[childIndex + 1] > arr[childIndex])) ? 1 : 0;

		if(arr[pos] > arr[childIndex]) {
			break;
		}

		tmp = arr[childIndex];
		arr[childIndex] = arr[pos];
		arr[pos] = tmp;

		pos = childIndex;
		childIndex = childIndex*2 + 1;
	}
}

void heapsort(int* arr, int size) {
	for(int i = size/2; i >= 0; --i) {
		siftDown(arr, size, i);
	}

	int tmp = 0;
	for(int i = size - 1; i > 0; --i) {
		tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;

		siftDown(arr, i, 0);
	}
}

int main () {
	const int size = 8;
	int array[size] = {6, 43, 2, 39, 1234, 43, -12, 65};
	
	heapsort(array, size);
	for(int i=0; i<size; ++i) {
		cout<< array[i]<< " ";
	}
	cout<< endl;

	return 0;
}
