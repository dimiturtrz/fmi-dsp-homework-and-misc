#include <iostream>

// -------------------------------- NODE ------------------------------------

template<typename T>
TrenarySearchTree<T>::Node::Node(char character, T* data): character(character), data(data) {}

// -------------------------------- TREE ------------------------------------

// ---------------------------- CLEAR HELPER

template<typename T>
void TrenarySearchTree<T>::clear() {
	clearSubtree(root);
}

template<typename T>
void TrenarySearchTree<T>::clearSubtree(Node*& currRoot) {
	
	if(currRoot->lo != NULL) {
		clearSubtree(currRoot->lo);
	}

	if(currRoot->hi != NULL) {
		clearSubtree(currRoot->hi);
	}

	if(currRoot->equal != NULL) {
		clearSubtree(currRoot->equal);
	}

	delete currRoot;
	currRoot = NULL;
}

// --------------------------- COPY HELPER

template<typename T>
void TrenarySearchTree<T>::copy(const TrenarySearchTree& other) {
	clear();
	copySubtree(other.root);
}

template<typename T>
void TrenarySearchTree<T>::copySubtree(Node*& currRoot, Node* otherCurrRoot) {

	if(otherCurrRoot == NULL) {
		return;
	}

	currRoot = new Node(otherCurrRoot->character, otherCurrRoot->data);

	if(otherCurrRoot->left != NULL) {
		copySubtree(currRoot->left, otherCurrRoot->left);
	}

	if(otherCurrRoot->right != NULL) {
		copySubtree(currRoot->right, otherCurrRoot->right);
	}

	if(otherCurrRoot->equal != NULL) {
		copySubtree(currRoot->equal, otherCurrRoot->equal);
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
		root = new Node(*key);
	}
	add(key, data, root);
}

template<typename T>
void TrenarySearchTree<T>::add(const char* key, const T& data, Node*& currRoot) {
	if(*key == '\0') {
		delete currRoot->data;
		currRoot->data = new T(data);
		return;
	}

	if(*key > currRoot->character) {
		if(currRoot->hi == NULL) {
			currRoot->hi = new Node(*key);
		}
		return add(key + 1, data, currRoot->hi);
	} else if (*key < currRoot->character) {
		if(currRoot->lo == NULL) {
			currRoot->lo = new Node(*key);
		}
		return add(key + 1, data, currRoot->lo);
	}


	if(currRoot->equal == NULL) {
		currRoot->equal = new Node(*key);
	}
	return add(key + 1, data, currRoot->equal);
}

// ------------------------- REMOVE

template<typename T>
void TrenarySearchTree<T>::remove(const char* key, const T& data) {
    return remove(key, data, root);
}

template<typename T>
void TrenarySearchTree<T>::remove(const char* key, const T& data, Node*& currRoot) {
	if(*key == '\0') {
		delete currRoot->data;
		if(currRoot->hi == NULL && currRoot->lo == NULL && currRoot->equal == NULL) {
			delete currRoot;
		}
		return;
	}

	if(*key > currRoot->character) {
		if(currRoot->hi == NULL) {
			return;
		}
		remove(key + 1, data, currRoot->hi);
	} else if (*key < currRoot->character) {
		if(currRoot->lo == NULL) {
			return;
		}
		remove(key + 1, data, currRoot->lo);
	} else {
		if(currRoot->equal == NULL) {
			return;
		}
		remove(key + 1, data, currRoot->equal);
	}

	if(currRoot->hi == NULL && currRoot->lo == NULL && currRoot->equal == NULL) {
		delete currRoot;
	}
}

// ------------------------ PRINT

template<typename T>
void TrenarySearchTree<T>::print() {
	if(root != NULL) {
		char accumWord[51] = { '\0' };
		printSubtree(root, accumWord, 0);
	}
}

template<typename T>
void TrenarySearchTree<T>::printSubtree(Node* currRoot, char* accumWord, int accumWordIndex) {
	if(currRoot->lo != NULL) {
		accumWord[accumWordIndex++] = currRoot->lo->character;
		accumWord[accumWordIndex] = '\0';
		printSubtree(currRoot->lo, accumWord, accumWordIndex);
		accumWord[--accumWordIndex] = '\0';
	}
	if(currRoot->equal != NULL) {
		accumWord[accumWordIndex++] = currRoot->equal->character;
		accumWord[accumWordIndex] = '\0';
		printSubtree(currRoot->equal, accumWord, accumWordIndex);
		accumWord[--accumWordIndex] = '\0';
	}
	std::cout<< accumWord<< std::endl;
	if(currRoot->hi != NULL) {
		accumWord[accumWordIndex++] = currRoot->hi->character;
		accumWord[accumWordIndex] = '\0';
		printSubtree(currRoot->hi, accumWord, accumWordIndex);
		accumWord[--accumWordIndex] = '\0';
	}
}

// ------------------------ FIND

template<typename T>
T* TrenarySearchTree<T>::getElement(const char* key) {
	getElement(key, root);
}

template<typename T>
T* TrenarySearchTree<T>::getElement(const char* key, Node* currRoot) {
	if(currRoot == NULL) {
		return NULL;
	}

	if(*key == '\0') {
		return currRoot->data;
	}

	if(*key > currRoot->character) {
		return getElement(*key + 1, currRoot->hi);
	} else if(*key < currRoot->data) {
		return getElement(*key + 1, currRoot->lo);
	} else {
		return getElement(*key + 1, currRoot->equal);
	}
}
