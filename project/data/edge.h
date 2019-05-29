#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

namespace data {

template <typename T>
class Edge
{
    Vertex<T> *from;
    Vertex<T> *to;

public:
    QString graphName;
    Edge(Vertex<T> *from, Vertex<T> *to, QString graph) : from(from), to(to), graphName(graph) {}

    Vertex<T> *getFrom() {return from;}
    Vertex<T> *getTo() {return to;}
};

}

#endif // EDGE_H
