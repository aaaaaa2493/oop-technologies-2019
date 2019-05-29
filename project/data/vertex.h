#ifndef VERTEX_H
#define VERTEX_H

#include <QString>

struct Elem {
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

template <typename T>
class Vertex
{
public:
    Vertex(){}
    Vertex(T val): value(val) {}
    T value;
    bool isVisited = false;

    friend bool operator==(const Vertex<T>& left, const Vertex<T>& right) {
        return left.value == right.value;
    }
};

#endif // VERTEX_H
