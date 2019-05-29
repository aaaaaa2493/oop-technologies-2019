#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <QString>
using namespace std;

namespace data {

template <typename T>
class Graph;

template <typename T>
class Vertex;

template <typename T>
class Edge;

template <typename T>
class GraphException {
public:
    const QString str;
    Graph<T> *graph;

    friend ostream& operator<< (ostream& os, GraphException const ex) {
        os << ex.str << endl;
        return os;
    }

protected:
    GraphException(Graph<T> *g, QString s) :
        graph(g),
        str("GRAPH EXCEPTION: " + s)
    {}
};

template<typename T>
class AddExistingVertex : public GraphException<T> {
public:
    void (Graph<T>::*func)(Vertex<T> * vertex) = &Graph<T>::addVertex;
    Vertex<T> *arg1;
    AddExistingVertex(Graph<T> *g, Vertex<T> *vertex) :
        GraphException<T>(g, "ADD EXISTING VERTEX: "
                             "Can not add already existing vertex: " +
                          vertex->value.str()),
        arg1(vertex)
    {}
};

template<typename T>
class AddExistingEdge : public GraphException<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddExistingEdge(Graph<T> *g, Edge<T> *e) :
        GraphException<T>(g, "ADD EXISTING EDGE: "
                             "Edge between " +
                          e->getFrom()->value.str() + " and " +
                          e->getTo()->value.str() + " already exists"),
        arg1(e)
    {}
};

template<typename T>
class InvalidArgument : public GraphException<T> {
protected:
    InvalidArgument(Graph<T> *g, QString str) :
        GraphException<T>(g, "INVALID ARGUMENT: " + str)
    {}
};

template<typename T>
class AddNullVertice : public InvalidArgument<T> {
public:
    void (Graph<T>::*func)(Vertex<T> * vertex) = &Graph<T>::addVertex;
    Vertex<T> *arg1;
    AddNullVertice(Graph<T> *g, Vertex<T> *vertex) :
        InvalidArgument<T>(g, "NULL VERTICE: trying to add null vertice"),
        arg1(vertex)
    {}
};

template<typename T>
class AddNullEdge : public InvalidArgument<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddNullEdge(Graph<T> *g, Edge<T> *e) :
        InvalidArgument<T>(g, "NULL EDGE: trying to add null edge"),
        arg1(e)
    {}
};

template<typename T>
class AddEdgeWithInvalidVertice : public InvalidArgument<T> {
protected:
    AddEdgeWithInvalidVertice(Graph<T> *g, QString str) :
        InvalidArgument<T>(g, "WHILE ADDING EDGE: " + str)
    {}
};

template<typename T>
class AddEdgeToUnknownVertice : public AddEdgeWithInvalidVertice<T> {
protected:
    AddEdgeToUnknownVertice(Graph<T> *g, QString str, QString v1) :
        AddEdgeWithInvalidVertice<T>(g, "UNKNOWN VERTICE: " + str + " argument is unknown vertice: " + v1)
    {}
};

template<typename T>
class AddEdgeWithFirstUnknownVertice : public AddEdgeToUnknownVertice<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddEdgeWithFirstUnknownVertice(Graph<T> *g, Edge<T> *e) :
        AddEdgeToUnknownVertice<T>(g, "First", e->getFrom()->value.str()),
        arg1(e)
    {}
};

template<typename T>
class AddEdgeWithSecondUnknownVertice : public AddEdgeToUnknownVertice<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddEdgeWithSecondUnknownVertice(Graph<T> *g, Edge<T> *e) :
        AddEdgeToUnknownVertice<T>(g, "Second", e->getTo()->value.str()),
        arg1(e)
    {}
};

template<typename T>
class AddEdgeWithBothUnknownVertices : public AddEdgeToUnknownVertice<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddEdgeWithBothUnknownVertices(Graph<T> *g, Edge<T> *e) :
        AddEdgeToUnknownVertice<T>(g, "Both first and second",
                                   e->getFrom()->value.str() +
                                   " and " +
                                   e->getTo()->value.str()),
        arg1(e)
    {}
};

template<typename T>
class AddEdgeToNullVertice : public AddEdgeWithInvalidVertice<T> {
protected:
    AddEdgeToNullVertice(Graph<T> *g, QString str) :
        AddEdgeWithInvalidVertice<T>(g, "NULL VERTICE: " + str + " argument is null vertice")
    {}
};

template<typename T>
class AddEdgeWithFirstNullVertice : public AddEdgeToNullVertice<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddEdgeWithFirstNullVertice(Graph<T> *g, Edge<T> *e) :
        AddEdgeToNullVertice<T>(g, "First"),
        arg1(e)
    {}
};

template<typename T>
class AddEdgeWithSecondNullVertice : public AddEdgeToNullVertice<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddEdgeWithSecondNullVertice(Graph<T> *g, Edge<T> *e) :
        AddEdgeToNullVertice<T>(g, "Second"),
        arg1(e)
    {}
};

template<typename T>
class AddEdgeWithBothNullVertices : public AddEdgeToNullVertice<T> {
public:
    void (Graph<T>::*func)(Edge<T> *e) = &Graph<T>::addEdge;
    Edge<T> *arg1;
    AddEdgeWithBothNullVertices(Graph<T> *g, Edge<T> *e) :
        AddEdgeToNullVertice<T>(g, "Both first and second"),
        arg1(e)
    {}
};

}

#endif // EXCEPTIONS_H
