#include "Node.h"

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template <class T>
class BinarySearchTree {
	Node<T>* root;

	void copy(const BinarySearchTree& other);
	void clear(const BinarySearchTree& other);

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& other);
	BinarySearchTree& operator=(const BinarySearchTree);
	~BinarySearchTree();
};

#endif
