#include <iostream>
#include "BinarySearchTree.h"

int main () {
	BinarySearchTree<int> bst;

	bst.add(5);
	bst.add(7);
	bst.add(6);
	bst.add(4);
	bst.add(1832);
	bst.add(-5);
	bst.add(37);

	bst.remove(7);
	bst.remove(1832);
    bst.remove(-5);

	bst.print();

	std::cout<< std::endl<< *(bst.getElement(4))<< std::endl<< std::endl;

    BinarySearchTree<int> bst2 = bst;

	for(BinarySearchTree<int>::Iterator iter = bst2.begin(); !iter.isFinished(); ++iter) {
		std::cout<< *(iter)<< " ";
	}
	std::cout<< std::endl;

	return 0;
}
