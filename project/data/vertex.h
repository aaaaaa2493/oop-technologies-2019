#ifndef VERTEX_H
#define VERTEX_H

#include <QString>
#include "pool.h"

struct Elem {
    Elem() {}
    Elem(QString name, QString graph, QString cont): displayName(name), graphName(graph), content(cont) {}
    QString displayName;
    QString graphName;
    QString content;

    QString str() {
        return displayName;
    }

    friend bool operator==(const Elem& left, const Elem& right) {
        return left.displayName == right.displayName;
    }
};


namespace data {

template <typename T>
class Vertex
{
protected:
    Vertex() {}
    Vertex(T val): value(val) {}


    static Pool<Vertex<T>> getPool() {
        static Pool<Vertex<T>> pool;
        return pool;
    }

    friend class Pool<Vertex<T>>;

public:

    static Vertex<T>* create(T value) {
        //Vertex<T> *v = Vertex<T>::getPool().createNewObject();
        Vertex<T> *v = new Vertex<T>(value);
        //v->value = value;
        return v;
    }

    ~Vertex() {
        Vertex<T>::getPool().deleteObject(this);
    }

    T value;
    bool isVisited = false;

    friend bool operator==(const Vertex<T>& left, const Vertex<T>& right) {
        return left.value == right.value;
    }
};

}

#endif // VERTEX_H
