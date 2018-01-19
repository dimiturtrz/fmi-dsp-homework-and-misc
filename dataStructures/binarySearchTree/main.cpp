#include <iostream>
#include "BinarySearchTree.h"

int main () {
	BinarySearchTree<int> bst;

	bst.add(5);
	bst.add(6);
	bst.add(4);
	bst.add(1832);
	bst.add(-5);
	bst.add(37);

	bst.print();

	return 0;
}
