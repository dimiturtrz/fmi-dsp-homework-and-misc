#ifndef TRENARY_SEARCH_TREE_H
#define TRENARY_SEARCH_TREE_H

template <class T>
class TrenarySearchTree {
	struct Node {
		bool leaf;

		Node(bool leaf);
	};

	struct BranchNode: Node {
		BranchNode* hi;
		BranchNode* lo;
		Node* equal;

		public:
			BranchNode(BranchNode* hi = NULL, BranchNode* lo = NULL, Node* equal = NULL);
	} * root;

	struct LeafNode: Node {
		T data;

		public:
			LeafNode(T data);
	};

	void clear();
	void clearSubtree(BranchNode*& currRoot);

	void copy(const TrenarySearchTree& other);
	void copySubtree(BranchNode*& currRoot, BranchNode* otherCurrRoot);

	void add(const char* key,const T& data, BranchNode*& currRoot);
	void remove(const T& data, BranchNode*& currRoot);

	T* getElement(const T& data, BranchNode* currRoot);
	void printSubtree(BranchNode* currRoot);
public:
	TrenarySearchTree();
	TrenarySearchTree(const TrenarySearchTree& other);
	TrenarySearchTree& operator=(const TrenarySearchTree& other);
	~TrenarySearchTree();

	void add(const char* key, const T& data);
	void remove(const T& data);

	T* getElement(const T& data);

	void print();
};

#include "TrenarySearchTree.hpp"

#endif
