#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
    Node(T *elem) : value(elem), next(0), prev(0) {}
    ~Node() {
        // delete value;
    }

    T *value;
    Node<T> *next;
    Node<T> *prev;
};

#endif // NODE_H
