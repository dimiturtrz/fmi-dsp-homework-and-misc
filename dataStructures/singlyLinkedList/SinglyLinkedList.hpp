#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
using namespace std;

#include "SinglyLinkedList.hpp"

// ----------------------------- HELPER ------------------------

template<typename T>
bool List<T>::isEmpty() const {
	return !size;
}

template<typename T>
void List<T>::clear() {
	if(isEmpty()) {
		return;
	}
	
	Node<T>* deleteIterator = head;
	for(Node<T>* iterator = head->getNext(); iterator != NULL; iterator = iterator->getNext()) {
		delete deleteIterator;
		deleteIterator = iterator;
	}
}

template<typename T>
void List<T>::copy(const List<T>& other) {
	clear();
	Node<T> copyIterator = head;
}

template<typename T>
void List<T>::print() {
	for(Node<T>* iterator = head; iterator != NULL; iterator = iterator->getNext()) {
		cout<< iterator->getData()<< " ";
	}
	cout<< endl;
}

// ------------------------- GETTERS -------------------------

template<typename T>
int List<T>::findNode(T data) const {
	int counter = 0;
	for(Node<T>* iterator = head; iterator != NULL; iterator = iterator->getNext()) {
		++counter;
		if(iterator->getData() == data) {
			return counter;
		}
	}
	return -1;
}

template<typename T>
Node<T>* List<T>::getNode(int index) const {
	if(index > size) {
		return NULL;
	}

	Node<T>* iterator = head;
	for(; index > 0 && iterator != NULL; --index) {
		iterator = iterator->getNext();
	}

	return iterator;
}

// ----------------------- ADDERS ------------------------------

template<typename T>
void List<T>::addFirstNode(Node<T>* newNode) {
	head = newNode;

	++size;
}

template<typename T>
void List<T>::addLastNode(Node<T>* newNode) {

	if(isEmpty()) {
		return addFirstNode(newNode);
	}

	Node<T>* lastNode = getNode(size - 1);
	lastNode->setNext(newNode);

	++size;
}

template<typename T>
void List<T>::addNode(Node<T>* newNode, int index) {
	if(index == 0) {
		return addFirstNode(newNode);
	}
	if(!isEmpty() && index > size) {
		return;
	}

	Node<T>* node = getNode(index - 1);
	newNode->setNext(node->getNext());
	node->setNext(newNode);

	++size;
}

template<typename T>
void List<T>::addElement(T data, int index) {
	Node<T>* newNode = new Node<T>(data);
	addNode(newNode, index);
}

template<typename T>
void List<T>::addElement(T data) {
	Node<T>* newNode = new Node<T>(data);
	addLastNode(newNode);
}

// ---------------------- REMOVERS -----------------------------

template<typename T>
void List<T>::removeFirstNode() {
	if(isEmpty()) {
		return;
	}

	Node<T>* newHead = head->getNext();
	delete head;
	head = newHead;

	--size;
}

template<typename T>
void List<T>::removeLastNode() {
	if(isEmpty()) {
		return;
	}

	if(size == 1) {
		return removeFirstNode();
	}

	Node<T>* preLastNode = getNode(size - 2);
	delete preLastNode->getNext();
	preLastNode->setNext(NULL);

	--size;
}

template<typename T>
void List<T>::removeElement(int index) {
	if(index > size-1) {
		return;
	}
	if(index == 0) {
		return removeFirstNode();
	}
	if(index == size - 1) {
		return removeLastNode();
	}

	Node<T>* preOldNode = getNode(index - 1);
	Node<T>* oldNode = preOldNode->getNext();
	preOldNode->setNext(oldNode->getNext());
	delete oldNode;

	--size;
}

// ----------------------  BIG FOUR ----------------------------

template<typename T>
List<T>::List(): size(0), head(NULL) {}

template<typename T>
List<T>::List(const List& other) {
	copy(other);
}

template<typename T>
List<T>& List<T>::operator=(const List& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}

template<typename T>
List<T>::~List() {
	clear();
}

#endif
