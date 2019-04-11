#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"


class Edge
{
    Vertex *from;
    Vertex *to;

public:
    Edge(Vertex *from, Vertex *to) : from(from), to(to) {}

    Vertex *getFrom() {return from;}
    Vertex *getTo() {return to;}
};

#endif // EDGE_H
