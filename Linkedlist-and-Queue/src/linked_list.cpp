#include <linked_list.hpp>

using namespace std;

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T> *next, LinkedListNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
//    cout << "l-list deleting node " << this->value << endl;
};

template<class T>
LinkedList<T>::LinkedList() {
    this->root = nullptr;
    this->tail = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
    LinkedListNode<T> *curr = this->root;
    while (curr != nullptr) {
        LinkedListNode<T> *temp = curr->next;
        delete curr;
        curr = temp;
    }
}

template<class T>
LinkedListNode<T> *LinkedList<T>::insert(T value) {
    auto *temp = new LinkedListNode<T>(value, nullptr, tail);

    if (root == nullptr) {
        root = temp;
    } else {
        tail->next = temp;
    }
    tail = temp;
    return temp;
}

template<class T>
LinkedListNode<T> *LinkedList<T>::find(T value) {
    LinkedListNode<T> *curr = this->root;
    while (curr != nullptr && curr->value != value) {
        curr = curr->next;
    }
    return curr;
}

template<class T>
LinkedListNode<T> *LinkedList<T>::remove(T value) {
    LinkedListNode<T> *curr = this->root;
    LinkedListNode<T> *prev = nullptr;

    while (curr && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return this->root;
    }

    if (curr == root) {
        this->root = this->root->next;
        this->root->prev = nullptr;
    } else {
        prev->next = curr->next;
        if (curr != tail) {
            curr->next->prev = prev;
        } else {
            tail = prev;
        }
    }

    delete curr;
    return this->root;
}

template<class T>
int LinkedList<T>::size() {
    LinkedListNode<T> *curr = this->root;
    int counter = 0;
    while (curr) {
        counter += 1;
        curr = curr->next;
    }
    return counter;
}

template<class T>
void LinkedList<T>::print() {
    LinkedListNode<T> *curr = this->root;
    while (curr) {
        cout << curr->value << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

template<class T>
void LinkedList<T>::printBackward() {
    LinkedListNode<T> *curr = this->tail;
    while (curr) {
        cout << curr->value << " -> ";
        curr = curr->prev;
    }
    cout << "nullptr" << endl;
}

template
class LinkedListNode<int>;

template
class LinkedList<int>;
