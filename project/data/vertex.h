#ifndef VERTEX_H
#define VERTEX_H

#include <QString>

struct Elem {
    Elem(QString name, QString graph, QString cont): displayName(name), graphName(graph), content(cont) {}
    bool isVisited = false;
    QString displayName;
    QString graphName;
    QString content;
};

template <typename T>
class Vertex
{
public:
    Vertex(){}
    Vertex(T val): value(val) {}
    T value;
};

#endif // VERTEX_H
