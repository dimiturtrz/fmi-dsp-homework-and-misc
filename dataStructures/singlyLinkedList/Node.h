#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
	T data;
	Node* next;

public:
	Node(T data, Node* next = NULL);
	T getData();
	Node* getNext();
	void setNext(Node* newNext);
};

#include "Node.hpp"

#endif
