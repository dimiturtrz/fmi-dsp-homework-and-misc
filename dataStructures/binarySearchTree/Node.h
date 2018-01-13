#include <iostream>

#ifndef TREE_NODE_H
#define TREE_NODE_H

template<class T>
class Node {
	Node* left;
	Node* right;
	T data;

public:
	Node(T data, Node* left = NULL, Node* right = NULL);
};

#endif
