#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Node.h"

template<class T>
class List {
	T data;
	Node<T>* head;
	int size;

	void clear();
	void copy(const List& other);

	void addNode(Node<T>* newNode, int index);
	void addFirstNode(Node<T>* newNode);
	void addLastNode(Node<T>* newNode);

	void removeFirstNode();
	void removeLastNode();
public:
	List();
	List(const List& other);
	List& operator=(const List& other);
	~List();

	bool isEmpty() const;

	int findNode(T data) const;
	Node<T>* getNode(int index) const;

	void addElement(T data, int index);
	void addElement(T data);

	void removeElement(int index);

	void print();
};

#include "SinglyLinkedList.hpp"

#endif
