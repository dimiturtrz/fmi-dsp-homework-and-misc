#include <iostream>
using namespace std;

int quickPartition(int* A, int lo, int hi) {

    int pivotIndex = hi-1;
    int i = lo;

    for(int j = lo; j < pivotIndex; ++j) {
        if(A[j] < A[pivotIndex]) {
            swap(A[i++], A[j]);
        }
    }
    swap(A[i], A[pivotIndex]);
    return i;
}

void quicksort(int* A, int lo, int hi) {
    if(lo >= hi) {
        return;
    }

    int pivotIndex = quickPartition(A, lo, hi);
    quicksort(A, lo, pivotIndex);
    quicksort(A, pivotIndex + 1, hi);
}

int main() {
    int A[] = {1, 12, 5, -72, 123, -34, 67, 68};
    int arrSize = 8;

    quicksort(A, 0, arrSize);
    for(int i = 0; i< arrSize; ++i) {
        cout<< A[i]<< " ";
    }

    return 0;
}
