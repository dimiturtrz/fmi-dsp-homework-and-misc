#include "Node.h"

template<typename T>
Node<T>::Node(T data, Node* left, Node* right): data(data), left(left), right(right) {} 
