#include <iostream>
#include "TrenarySearchTree.h"

int main () {
	TrenarySearchTree<int> tst;

	tst.add("pesho", 1);
	tst.add("dcewspeter", 2);
	tst.add("acrwpenka", 3);
	tst.add("pesjen", 2);
	tst.add("jofsdafasdro", 2);
	tst.add("qedo", 2);
	tst.add("jdhk", 2);
	tst.add("neri", 2);
	tst.add("nerijksd", 2);
	tst.add("nksjsfdhfkjsddf", 2);
	tst.add("mwejkbhdsaui", 2);



	tst.print();

	return 0;
}
