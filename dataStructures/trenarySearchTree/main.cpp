#include <iostream>
#include "TrenarySearchTree.h"

int main () {
	TrenarySearchTree<int> tst;

	tst.add("pesho", 1);
	tst.add("peshones", 1);
	tst.add("peshonesil", 1);
	tst.add("dcewspeter", 2);
	tst.add("acrwpenka", 3);
	tst.add("pesjen", 5);
	tst.add("jofsdafasdro", 2);
	tst.add("qedo", 2);
	tst.add("jdhk", 2);
	tst.add("nerijksd", 2);
	tst.add("neri", 2);
	tst.add("nksjsfdhfkjsddf", 2);
	tst.add("mwejkbhdsaui", 2);
	tst.add("brighten", 1);
    tst.add("bright", 2);
    tst.add("pesho", 1);
    tst.add("peshoo", 1);
    tst.add("peshooo", 1);
    tst.add("peshooosl", 1);
    tst.add("peshool", 1);
    tst.add("peshoooslm", 1);

	tst.remove("pesho");
	tst.remove("brighten");
	tst.remove("peshoooslm");
	tst.remove("mwejkbhdsaui");
	tst.remove("neri");

	tst.print();

	std::cout<< std::endl<< *(tst.getElement("pesjen"))<< std::endl;

	return 0;
}
