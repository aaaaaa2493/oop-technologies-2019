#ifndef LIST_H
#define LIST_H

#include "node.h"

template<typename T>
class ListIterator;


template<typename T>
class List {
    Node<T> *curr;
    Node<T> *first;
    Node<T> *last;

public:

    List(): curr(nullptr), first(nullptr), last(nullptr) { }
    ~List() {
        curr = first;
        while (curr != last) {
            curr = curr->next;
            delete curr->prev;
        }
        delete curr;
        curr = first = last = nullptr;
    }

    // APPROVED

    // curr ...
    // results in
    // NEW -> curr ...

    // ... node -> curr ...
    // results in
    // ... node -> NEW -> curr ...

    List *addBefore(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == nullptr) {
            curr = first = last = node;
        }
        else if (curr == first) {
            first = node;
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

    // APPROVED

    // ... curr
    // results in
    // ... curr -> NEW

    // ... curr -> node ...
    // results in
    // ... curr -> NEW -> node ...

    List *addAfter(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == nullptr) {
            curr = first = last = node;
        }
        else if (curr == last) {
            last = node;
            node->prev = curr;
            curr->next = node;
        }
        else {
            node->prev = curr;
            node->next = curr->next;
            curr->next->prev = node;
            curr->next = node;
        }
        return this;
    }

    List *append(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == nullptr) {
            curr = first = last = node;
        }
        else {
            last->next = node;
            node->prev = last;
            last = node;
        }
    }

    List *prepend(T *value) {
        Node<T> *node = new Node<T>(value);
        if (curr == nullptr) {
            curr = first = last = node;
        }
        else {
            first->prev = node;
            node->next = first;
            first = node;
        }
    }

    // APPROVED

    // ... node1 -> node2 -> curr ...
    // results in
    // ... node1 -> curr ...

    List *deleteBefore() {
        if (curr == nullptr) {
            return this;
        }
        else if (first == last) {
            delete curr;
            curr = first = last = nullptr;
        }
        else if (curr == first) {
            curr = curr->next;
            curr->prev = nullptr;
            delete first;
            first = curr;
        }
        else if (curr->prev == first) {
            curr->prev = nullptr;
            delete first;
            first = curr;
        }
        else {
            Node<T> *node = curr->prev;
            node->prev->next = curr;
            curr->prev = node->prev;
            delete node;
        }
        return this;
    }

    // APPROVED

    // ... curr -> node1 -> node2 ...
    // results in
    // ... curr -> node2 -> ...

    List *deleteAfter() {
        if (curr == nullptr) {
            return this;
        }
        else if (first == last) {
            delete curr;
            curr = first = last = nullptr;
        }
        else if (curr == last) {
            curr = curr->prev;
            curr->next = nullptr;
            delete last;
            last = curr;
        }
        else if (curr->next == last) {
            curr->next = nullptr;
            delete last;
            last = curr;
        }
        else {
            Node<T> *node = curr->next;
            node->next->prev = curr;
            curr->next = node->next;
            delete node;
        }
        return this;
    }

    List *deleteCurr() {
        if (curr == nullptr) {
            return this;
        }
        if (isStart() && isEnd()) {
            delete curr;
            curr = first = last = nullptr;
        }
        else if (isStart()) {
            next();
            deleteBefore();
        }
        else if (isEnd()) {
            prev();
            deleteAfter();
        }
        else {
            prev();
            deleteAfter();
        }
        return this;
    }

    List *next() {
        if (curr != last) {
            curr = curr->next;
        }
        return this;
    }

    Node<T> *getStart() {
        return first;
    }

    List *prev() {
        if (curr != first) {
            curr = curr->prev;
        }
        return this;
    }

    T *get() {
        return curr->value;
    }

    void toStart() {
        curr = first;
    }

    void toEnd() {
        curr = last;
    }

    bool hasNext() {
        return curr->next != nullptr;
    }

    bool isEnd() {
        return curr == last;
    }

    bool isStart() {
        return curr == first;
    }

    bool isEmpty() {
        return first == nullptr && last == nullptr;
    }

    bool find(T *value) {
        if (isEmpty()) {
            return false;
        }
        toStart();
        while (curr != last) {
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

    ListIterator<T> begin() {
        return ListIterator<T>(first);
    }

    ListIterator<T> end() {
        return ListIterator<T>(nullptr);
    }

};


template<typename T>
class ListIterator
{
public:
    ListIterator(Node<T> *curr) {
        this->curr = curr;
    }

    bool operator!=(ListIterator<T> &other)  {
        return other.curr != curr;
    }

    bool operator==(ListIterator<T> &other)  {
        return other.curr == curr;
    }

    T* operator*() {
        return curr->value;
    }

    ListIterator<T>& operator++() {
        curr = curr->next;
        return *this;
    }

private:
    Node<T> *curr;
};
#endif // LIST_H
