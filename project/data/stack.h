#ifndef STACK_H
#define STACK_H

#include "node.h"

template<typename T>
class Stack
{
    Node<T> *top = 0;

public:
    Stack() {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == 0;
    }

    void push(T *value) {
        Node<T> *node = new Node<T>(value);
        if (isEmpty()) {
            top = node;
        }
        else {
            node->prev = top;
            top = node;
        }
    }

    T *pop() {
        if (isEmpty()) {
            throw;
        }
        else {
            T *value = top->value;
            Node<T> *node = top;
            top = top->prev;
            delete node;
            return value;
        }
    }

};

#endif // STACK_H
