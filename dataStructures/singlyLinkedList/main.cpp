#include<iostream>

#include "Node.h"
#include "SinglyLinkedList.h"

using namespace std;

int main () {
	cout<< endl;
	// node tests
	cout<< "-------------Node testing stuff--------------"<< endl;
	Node<int> n2(5);
	Node<int> n1(6, &n2);
	cout<< "node 1 data: "<< n1.getData()<< endl
		<< "node 1 next node data: "<< n1.getNext()->getData()<< endl;

	// list tests
	cout<< "-------------List Texting stuff--------------"<< endl;
	List<int> l1;
	l1.addElement(5);
	l1.addElement(6);
	l1.addElement(7);
	l1.addElement(8);
	l1.addElement(9);
	l1.addElement(10, 3);

	l1.print();

	l1.removeElement(5);
	l1.removeElement(0);
	l1.removeElement(2);

	l1.print();

	cout<< endl;
}
