#include<iostream>
#include<list>
using namespace std;

class HashedCollection {
	int capacity;
	list<int>* chains;

	int h(int x) {
		return x % capacity;
	}
public:
	HashedCollection(int capacity): capacity(capacity) {
		chains = new list<int>[capacity];
	}
	~HashedCollection() {
		delete [] chains;
	}

	void add(int number) {
		chains[h(number)].push_back(number);
	}

	bool search(int number) {
		list<int> chain = chains[h(number)];
		for(list<int>::iterator it = chain.begin(); it != chain.end(); ++it) {
			if(*it == number) {
				return true;
			}
		}
		return false;
	}

	void remove(int number) {
		list<int> chain = chains[h(number)];
		for(list<int>::iterator it = chain.begin(); it != chain.end(); ++it) {
			if(*it == number) {
				chain.erase(it);
			}
		}
	}
	
};

int main () {
	HashedCollection separateChain(10);
	for(int i = 0; i < 100; ++i) {
		separateChain.add(i);
	}
	std::cout<< separateChain.search(55)<< std::endl;

	return 0;
}
