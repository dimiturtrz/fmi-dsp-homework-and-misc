#include <iostream>
#include "TrenarySearchTree.h"

int main () {
	TrenarySearchTree<int> tst;

	tst.add("pesho", 1);
	tst.add("peter", 2);
	tst.add("penka", 3);
	tst.add("pesjen", 2);
	tst.add("joro", 2);
	tst.add("pesj", 5);
	tst.add("qedo", 2);
	tst.print();

	return 0;
}
