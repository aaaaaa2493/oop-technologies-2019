#ifndef LIST_H
#define LIST_H

#include "node.h"


template<typename T>
class List {
    Node<T> *curr;
    Node<T> *start;
    Node<T> *end;

public:
    T *value;

    List(T *v = 0) : curr(0), start(0), end(0), value(v) {}
    ~List() {
        curr = start;
        while (curr != end) {
            curr = curr->next;
            delete curr->prev;
        }
        delete curr;
        curr = start = end = 0;
    }

    List *addBefore(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == 0) {
            curr = start = end = node;
        }
        else if (curr == start) {
            start = node;
            node->next = curr;
            curr->prev = node;
        }
        else {
            node->next = curr;
            node->prev = curr->prev;
            curr->prev->next = node;
            curr->prev = node;
        }
        return this;
    }

    List *addAfter(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == 0) {
            curr = start = end = node;
        }
        else if (curr == end) {
            end = node;
            node->prev = curr;
            curr->next = node;
        }
        else {
            node->prev = curr;
            node->next = curr->next->next;
            curr->next->prev = node;
            curr->next = node;
        }
        return this;
    }

    List *deleteBefore() {
        if (curr == 0) {
            return;
        }
        else if (curr == start) {
            curr = curr->next;
            curr->prev = 0;
            delete start;
            start = curr;
        }
        else if(curr->prev == start){
            curr->prev = 0;
            delete start;
            start = curr;
        }
        else {
            Node<T> *node = curr->prev;
            node->prev->next = curr;
            curr->prev = node->prev;
            delete node;
        }
        return this;
    }

    List *deleteAfter() {
        if (curr == 0) {
            return;
        }
        else if (curr == end) {
            curr = curr->prev;
            delete curr->next;
            curr->next = 0;
            end = curr;
        }
        else if (curr->next == end) {
            delete curr->next;
            curr->next = 0;
            end = curr;
        }
        else {
            Node<T> *node = curr->next;
            curr->next = node->next;
            node->next->prev = curr;
            delete node;
        }
        return this;
    }

    List *next() {
        if (curr != end) {
            curr = curr->next;
        }
        return this;
    }

    Node<T> *getStart() {
        return start;
    }

    List *prev() {
        if (curr != start) {
            curr = curr->prev;
        }
        return this;
    }

    T *get() {
        return curr->value;
    }

    void toStart() {
        curr = start;
    }

    void toEnd() {
        curr = end;
    }

    bool hasNext() {
        return curr->next == 0;
    }

    bool isEnd() {
        return curr == end;
    }

    bool isStart() {
        return curr == start;
    }

    bool isEmpty() {
        return start == 0 && end == 0;
    }

    bool find(T *value) {
        if (isEmpty()) {
            return false;
        }
        toStart();
        while (curr != end) {
            if (curr->value == value) {
                return true;
            }
            curr = curr->next;
        }
        if (curr->value == value) {
            return true;
        }
        else {
            return false;
        }
    }

};

#endif // LIST_H
