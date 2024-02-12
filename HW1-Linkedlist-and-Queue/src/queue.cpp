#include <queue.hpp>

using namespace std;

template<class T>
Queue<T>::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
Queue<T>::~Queue() {
    while (this->head) {
        auto *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

template<class T>
void Queue<T>::push(T value) {
    auto *temp = new QueueNode<T>(value, nullptr, tail);
    if (head == nullptr) {
        head = temp;
    } else {
        tail->next = temp;
    }
    tail = temp;
}

template<class T>
T Queue<T>::pop() {
    T value = this->head->value;
    auto *temp = this->head;

    if (this->head->next) {
        this->head = this->head->next;
        this->head->prev = nullptr;
    } else {
        this->head = nullptr;
        this->tail = nullptr;
    }

    delete temp;
    return value;
}


template<class T>
bool Queue<T>::empty() {
    return head == nullptr;
}

template<class T>
void Queue<T>::print() {
    auto *curr = this->head;
    while (curr) {
        std::cout << curr->value << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr" << std::endl;
}

template<class T>
void Queue<T>::printBackward() {
    auto *curr = this->tail;
    while (curr) {
        std::cout << curr->value << " -> ";
        curr = curr->prev;
    }
    std::cout << "nullptr" << std::endl;
}

template<class T>
QueueNode<T>::QueueNode(T value, QueueNode<T> *next, QueueNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
QueueNode<T>::~QueueNode() {
//    cout << "queue - deleting node: " << this->value << endl;
}

template
class Queue<int>;
