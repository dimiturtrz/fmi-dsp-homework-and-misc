#include "BinarySearchTree.h"

template<typename T>
void BinarySearchTree<T>::copy(const BinarySearchTree& other) {
	clear();
	
}

template<typename T>
void BinarySearchTree<T>::clear(const BinarySearchTree& other) {}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(): root(NULL) {}
