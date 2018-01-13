#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template <class T>
class BinarySearchTree {
	struct Node {
		Node* left;
		Node* right;
		T data;

		public:
			Node(T data, Node* left = NULL, Node* right = NULL);
	} * root;

	void copy(const BinarySearchTree& other);
	void copySubtree(Node* currRoot, Node* otherCurrRoot);

	void clear();
	void clearSubtree(Node* currRoot);

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& other);
	BinarySearchTree& operator=(const BinarySearchTree& other);
	~BinarySearchTree();
};

#endif
