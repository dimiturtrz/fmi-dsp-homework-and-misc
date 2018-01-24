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

	/*tst.remove("pesho");
	tst.remove("brighten");
	tst.remove("peshoooslm");
	tst.remove("mwejkbhdsaui");
	tst.remove("neri");*/

	tst.print();

	//std::cout<< std::endl<< *(tst.getElement("pesjen"))<< std::endl;

	//TrenarySearchTree<int> tst2 = tst;

    /*tst2.add("pesho", 1);
	tst2.add("peshones", 1);
	tst2.add("peshonesil", 1);
	tst2.add("dcewspeter", 2);
	tst2.add("acrwpenka", 3);
	tst2.add("pesjen", 5);
	tst2.add("jofsdafasdro", 2);
	tst2.add("qedo", 2);
	tst2.add("jdhk", 2);
	tst2.add("nerijksd", 2);
	tst2.add("neri", 2);
	tst2.add("nksjsfdhfkjsddf", 2);
	tst2.add("mwejkbhdsaui", 2);
	tst2.add("brighten", 1);
    tst2.add("bright", 2);*/
    //tst2.add("pesho", 1);
    //tst2.add("peshoo", 1);
    //tst2.add("peshooo", 1);
    //tst2.add("peshooosl", 1);
    //tst2.add("peshool", 1);
    //tst2.add("peshoooslm", 1);
    //tst2.add("gsho", 4);
    //tst2.add("gshl", 5);

	/*char buff[30];
	char* buffPointer = buff;
	for(TrenarySearchTree<int>::Iterator iter = tst2.begin(); !iter.isFinished(); ++iter) {
		iter.getWord(buffPointer);
		std::cout<< buff<< std::endl;
	}
	std::cout<< std::endl;*/

	return 0;
}
