#include<iostream>
using namespace std;

class HashedCollection {
	int capacity;

	struct HashCell {
		int value;
		bool empty;
		bool deleted;

		void assign(int value) {
			this->value = value;
			empty = false;
			deleted = false;
		}

		HashCell(): value(-1), empty(true), deleted(false) {}

	} * elements;

	int h(int x) {
		return x % capacity;
	}

	void expand() {
		HashCell* oldElements = new HashCell[capacity];
		for(int i = 0; i < capacity; ++i) {
			oldElements[i] = elements[i];
		}
		int oldCapacity = capacity;

		capacity *= 2;
		delete [] elements;
		elements = new HashCell[capacity];

		for(int i = 0; i < oldCapacity; ++i) {
			add(oldElements[i].value);
		}
	}

public:
	HashedCollection(int capacity): capacity(capacity) {
		elements = new HashCell[capacity];
	}

	~HashedCollection() {
		delete [] elements;
	}

	bool search(int number) {
		for(int i = 0; h(number) + i < capacity; ++i) {
			int index = h(number) + i;
			if(!elements[index].deleted && !elements[index].empty && elements[index].value == number) {
				return true;
			}
			if(elements[index].empty) {
				return false;
			}
		}
		return false;
	}

	void add(int number) {
		for(int i = 0; h(number) + i < capacity; ++i) {
			int index = h(number) + i;
			if(elements[index].empty || elements[index].deleted) {
				elements[index].assign(number);
				return;
			}
		}

		expand();
		return add(number);
	}

	void remove(int number) {
		for(int i = 0; h(number) + i < capacity; ++i) {
			int index = h(number) + i;
			if(elements[index].value == number) {
				elements[index].deleted = true;
			}
		}
	}
};

int main () {
	HashedCollection linearProbing(10);
	for(int i = 0; i < 100; ++i) {
		linearProbing.add(i);
	}
	
	linearProbing.remove(55);
	cout<< linearProbing.search(55)<< endl;

	return 0;
}
