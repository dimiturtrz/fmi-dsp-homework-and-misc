#include <iostream>
#include "Vector.h"

int main () {
	Vector<int> v1;
	v1.add(1);
	v1.add(2);
	v1.add(3);
	v1.add(4);
	v1.add(5);

	v1.remove(2);
	v1.remove(3);
	v1.remove(4);
	v1.remove(5);

	v1.add(2);
	v1.add(3);
	v1.add(4);
	v1.add(5);

	int size = v1.getSize();
	for(int i = 0; i < size; ++i) {
		std::cout<< v1[i]<< std::endl;
	}

	return 0;
}
