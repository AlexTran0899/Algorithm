#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = NULL;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    // YOUR CODE HERE

    // END OF YOUR CODE
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    // YOUR CODE HERE

    // END OF YOUR CODE
}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
    // YOUR CODE HERE
    
    // END OF YOUR CODE
}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    // YOUR CODE HERE
    
    // END OF YOUR CODE
}

template<class T>
int LinkedList<T>::size() {
    // YOUR CODE HERE 
    
    // END OF YOUR CODE
}

template class LinkedListNode<int>;
template class LinkedList<int>;
