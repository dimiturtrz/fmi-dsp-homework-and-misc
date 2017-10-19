#ifndef NODE_HPP
#define NODE_HPP

#include "Node.h"

template<typename T>
Node<T>::Node(T data, Node* next): data(data), next(next) {}

template<typename T>
T Node<T>::getData() {
	return data;
}

template<typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template<typename T>
void Node<T>::setNext(Node* newNext) {
	next = newNext;
}

#endif
