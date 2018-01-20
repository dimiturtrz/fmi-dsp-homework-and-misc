#include <iostream>

// -------------------------------- NODE ------------------------------------

template<typename T>
TrenarySearchTree<T>::Node::Node(bool leaf): leaf(leaf) {}

// ----------------------------- BRANCH_NODE --------------------------------

template<typename T>
TrenarySearchTree<T>::BranchNode::BranchNode(BranchNode* hi, BranchNode* lo, Node* equal): hi(hi), lo(lo), equal(equal), Node(false) {}

// ------------------------------ LEAF_NODE ---------------------------------

template<typename T>
TrenarySearchTree<T>::LeafNode::LeafNode(T data): data(data), Node(true) {}

// -------------------------------- TREE ------------------------------------

// ---------------------------- CLEAR HELPER

template<typename T>
void TrenarySearchTree<T>::clear() {
	if(root != NULL) {
		clearSubtree(root);
	}
}

template<typename T>
void TrenarySearchTree<T>::clearSubtree(BranchNode*& currRoot) {
	if(currRoot->equal->leaf) {
		delete currRoot->equal;
		return;
	}

	
	if(currRoot->lo != NULL) {
		clearSubtree(currRoot->lo);
	}

	if(currRoot->hi != NULL) {
		clearSubtree(currRoot->hi);
	}

	clearSubtree(reinterpret_cast<TrenarySearchTree<T>::BranchNode*&>(currRoot->equal));

	delete currRoot;
	currRoot = NULL;
}

// --------------------------- COPY HELPER

template<typename T>
void TrenarySearchTree<T>::copy(const TrenarySearchTree& other) {
	clear();
	if(other.root != NULL) {
		copySubtree(other.root);
	}
}

template<typename T>
void TrenarySearchTree<T>::copySubtree(BranchNode*& currRoot, BranchNode* otherCurrRoot) {

	currRoot = new BranchNode();

	if(otherCurrRoot->lo != NULL) {
		copySubtree(currRoot->lo, otherCurrRoot->lo);
	}

	if(otherCurrRoot->hi != NULL) {
		copySubtree(currRoot->hi, otherCurrRoot->hi);
	}

	if(otherCurrRoot->equal->leaf) {
		currRoot = new LeafNode((static_cast<LeafNode>(otherCurrRoot)).data);
		return;
	}
}

// --------------------------- BIG FOUR

template<typename T>
TrenarySearchTree<T>::TrenarySearchTree(): root(NULL) {}

template<typename T>
TrenarySearchTree<T>::TrenarySearchTree(const TrenarySearchTree& other) {
	copy(other);
}

template<typename T>
TrenarySearchTree<T>& TrenarySearchTree<T>::operator=(const TrenarySearchTree& other) {
	if(this != &other) {
		copy(other);
	}
	return *this;
}

template<typename T>
TrenarySearchTree<T>::~TrenarySearchTree() {
	clear();
}

// ---------------------------- ADD

template<typename T>
void TrenarySearchTree<T>::add(const char* key, const T& data) {
	if(root == NULL) {
		root = new BranchNode();
	}
	add(key, data, root);
}

template<typename T>
void TrenarySearchTree<T>::add(const char* key, const T& data, BranchNode*& currRoot) {
	if(key == '\0') {
		currRoot = new Node(data);
		return;
	}

	if(currRoot->data < data) {
		return add(data, currRoot->hi);
	} else {
		return add(data, currRoot->lo);
	}
}

// ------------------------- REMOVE

template<typename T>
void TrenarySearchTree<T>::remove(const T& data) {
    if(root->data != data) {
        return remove(data, root);
    }

    //removeNode(root);
}

template<typename T>
void TrenarySearchTree<T>::remove(const T& data, BranchNode*& currRoot) {
	if(currRoot == NULL) {
		throw;
	}

	if(currRoot->lo != NULL && currRoot->lo->data == data) {
		//currRoot->lo = removeNode(currRoot->lo);
        return;
	} else if(currRoot->hi != NULL && currRoot->hi->data == data) {
		//currRoot->hi = removeNode(currRoot->hi);
		return;
	}

	if(currRoot->data < data) {
		return remove(data, currRoot->hi);
	} else {
		return remove(data, currRoot->lo);
	}
}

// ------------------------ PRINT

template<typename T>
void TrenarySearchTree<T>::print() {
	if(root != NULL) {
		printSubtree(root);
	}
}

template<typename T>
void TrenarySearchTree<T>::printSubtree(BranchNode* currRoot) {
	if(currRoot->lo != NULL) {
		printSubtree(currRoot->lo);
	}
	std::cout<< currRoot->data<< std::endl;
	if(currRoot->hi != NULL) {
		printSubtree(currRoot->hi);
	}
}

// ------------------------ FIND

template<typename T>
T* TrenarySearchTree<T>::getElement(const T& data) {
	getElement(data, root);
}

template<typename T>
T* TrenarySearchTree<T>::getElement(const T& data, BranchNode* currRoot) {
	if(currRoot == NULL) {
		return NULL;
	}

	if(currRoot->data < data) {
		return getElement(data, currRoot->hi);
	} else if(currRoot->data > data) {
		return getElement(data, currRoot->lo);
	} else {
		return &(currRoot->data);
	}
}
