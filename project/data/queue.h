#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template<typename T>
class Queue
{
    Node<T> *start = 0;
    Node<T> *end = 0;

public:
    Queue() {}
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return start == 0 && end == 0;
    }

    void push(T *value) {
        Node<T> *node = new Node<T>(value);
        if (isEmpty()) {
            start = end = node;
        }
        else {
            start->prev = node;
            start = node;
        }
    }

    T *pop() {
        if (isEmpty()) {
            throw;
        }
        if (start == end) {
            T *value = end->value;
            delete end;
            start = end = 0;
            return value;
        }
        else {
            T *value = end->value;
            Node<T> *node = end;
            end = end->prev;
            delete node;
            return value;
        }
    }

};

#endif // QUEUE_H
