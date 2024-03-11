#include <bst.hpp>
#include <stack.hpp>
#include <queue.hpp>
#include <iomanip>
#include <string>
#include <sstream>
// Operator Overloading

bool operator<( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second);
}

bool operator>( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first > rhs.first) || (lhs.first == rhs.first && lhs.second > rhs.second);
}

bool operator==( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs ) {
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template<class T>
BSTNode<T>::BSTNode() {
    this->left = this->right = NULL;
    this->height = 0;
}

template<class T>
BSTNode<T>::BSTNode(T key, int height, BSTNode *left, BSTNode *right) {
    this->key = key;
    this->height = height;
    this->left = left;
    this->right = right;
}

template<class T>
BSTNode<T>::~BSTNode() {
    std::cout << "destroying node" << std::endl;
    this->left = this->right = NULL;
}

template<class T>
void BST<T>::clear(BSTNode<T> *node) {
    if(node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template<class T>
BSTNode<T> *BST<T>::find(T key, BSTNode<T> *node) const {
    if(node == nullptr) {
        return nullptr;
    }
    if(node->key == key) {
        return node;
    }

    if(node->key > key) {
        return find(key, node->left);
    } else {
        return find(key, node->right);
    }
}

template<class T>
BSTNode<T> *BST<T>::findMaximum(BSTNode<T> *node) {
    return node->right == nullptr ? node : findMaximum(node->right);
}

template<class T>
BSTNode<T> *BST<T>::insert(T key, BSTNode<T> *node) {
    if(this->root == nullptr){
        return this->root = new BSTNode<T>(key, 0, nullptr, nullptr);
    }

    BSTNode<T> *parent = nullptr;
    BSTNode<T> *current = node;
    while (current != nullptr) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (key < parent->key) {
        parent->left = new BSTNode<T>(key, parent->height + 1, nullptr, nullptr);
    } else {
        parent->right = new BSTNode<T>(key, parent->height + 1, nullptr, nullptr);
    }
    return node;
}

template<class T>
BSTNode<T> *BST<T>::remove(T key, BSTNode<T> *node) {
    if(!node) return nullptr;
    if(key < node->key) {
        node->left = remove(key, node->left);
    } else if(key > node->key) {
        node->right = remove(key, node->right);
    } else {
        if(!node->left) {
            return node->right;
        } else if (!node->right) {
            return node->left;
        }

        BSTNode<T> *temp = node->right;
        while(temp->left) {
            temp = temp->left;
        }
        node->key = temp->key;
        node->right = remove(temp->key, node->right);
    }
    return node;
}

template<class T>
BST<T>::BST() {
    this->root = NULL;
}

template<class T>
BST<T>::~BST() {
    this->clear(this->root);
 }


template<class T>
BSTNode<T> *BST<T>::find(T key) {
    return this->find(key, this->root);
}

template<class T>
BSTNode<T> *BST<T>::findMaximum() {
    return this->findMaximum(this->root);
}


template<class T>
BSTNode<T> *BST<T>::insert(T key) {
    return this->root = this->insert(key, this->root);
}

template<class T>
BSTNode<T> *BST<T>::remove(T key) {
    return this->root = this->remove(key, this->root);
}

template class BSTNode<int>;
template class BST<int>;

template class BSTNode<std::pair<int, int> >;
template class BST<std::pair<int, int> >;
