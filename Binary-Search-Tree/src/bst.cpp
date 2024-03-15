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
    if(node == nullptr){
        return nullptr;
    }

    if(node->key == key){
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
BSTNode<T> *BST<T>::insert(T key, BSTNode<T> *node, BSTNode<T> *parent) {
    if(node == nullptr){ 
        int height = parent == nullptr ? 0 : parent->height + 1;
        return new BSTNode<T>(key, height, nullptr, nullptr); 
    }

    if(node->key > key) {
        node->left = insert(key, node->left, node);
    } else {
        node->right = insert(key, node->right, node);
    }

    return node;
}

template<class T>
BSTNode<T> *BST<T>::remove(T key, BSTNode<T> *node) {
    if(node == nullptr) return nullptr;
    if(node->key > key) {
        node->left = remove(key, node->left);
    } else if (node->key < key) {
        node->right = remove(key, node->right);
    } else {
        // case 1: 1 child
        if(node->right == nullptr){
            BSTNode<T> *temp = node->right;
            delete node;
            return temp;
        } else if(node->left == nullptr) {
            BSTNode<T> *temp = node->left;
            delete node;
            return temp;
        } else {
            std::cout << "Two child" << std::endl;
            BSTNode<T> *temp = node->right;
            while(temp && temp->left != nullptr) temp = temp->left;
            node->key = temp->key;
            node->right = remove(temp->key, node->right);
        }
        
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
    return this->root = this->insert(key, this->root, nullptr);
}

template<class T>
BSTNode<T> *BST<T>::remove(T key) {
    return this->root = this->remove(key, this->root);
}

template class BSTNode<int>;
template class BST<int>;

template class BSTNode<std::pair<int, int> >;
template class BST<std::pair<int, int> >;
