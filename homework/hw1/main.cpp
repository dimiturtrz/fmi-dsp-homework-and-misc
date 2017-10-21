#include<iostream>
using namespace std;

#include "Tab.h"
#include "TabCollection.h"

int main () {
	Tab tab("sumUrl");
	cout<< endl<< tab<< endl;

	TabCollection tc;
	tc.openTab("t1");
	tc.openTab("t2");
	tc.closeCurrentTab();
	tc.openTab("t3");
	tc.goBackwards();
	tc.openTab("t2,5");
	tc.openTab("t2,75");
	tc.openUrl("fmi");
	tc.print();
}
