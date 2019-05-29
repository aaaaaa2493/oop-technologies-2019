#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <QString>
using namespace std;

template <typename T>
class Graph;

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
    void (Graph<T>::*func)(T * vertex) = &Graph<T>::addVertex;
    T *arg1;
    AddExistingVertex(Graph<T> *g, T *vertex) :
        GraphException<T>(g, "ADD EXISTING VERTEX: Can not add already existing vertex: " + vertex->toString()),
        arg1(vertex)
    {}
};

template<typename T>
class AddExistingEdge : public GraphException<T> {
public:
    void (Graph<T>::*func)(T *v1, T *v2) = &Graph<T>::addEdge;
    T *arg1;
    T *arg2;
    AddExistingEdge(Graph<T> *g, T *v1, T *v2) :
        GraphException<T>(g, "ADD EXISTING EDGE: Edge between " + v1->toString() + " and " + v2->toString() + " already exists"),
        arg1(v1),
        arg2(v2)
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
    void (Graph<T>::*func)(T *v1, T *v2) = &Graph<T>::addEdge;
    T *arg1;
    T *arg2;
    AddEdgeWithFirstUnknownVertice(Graph<T> *g, T *v1, T *v2) :
        AddEdgeToUnknownVertice<T>(g, "First", v1->toString()),
        arg1(v1),
        arg2(v2)
    {}
};

template<typename T>
class AddEdgeWithSecondUnknownVertice : public AddEdgeToUnknownVertice<T> {
public:
    void (Graph<T>::*func)(T *v1, T *v2) = &Graph<T>::addEdge;
    T *arg1;
    T *arg2;
    AddEdgeWithSecondUnknownVertice(Graph<T> *g, T *v1, T *v2) :
        AddEdgeToUnknownVertice<T>(g, "Second", v2->toString()),
        arg1(v1),
        arg2(v2)
    {}
};

template<typename T>
class AddEdgeWithBothUnknownVertices : public AddEdgeToUnknownVertice<T> {
public:
    void (Graph<T>::*func)(T *v1, T *v2) = &Graph<T>::addEdge;
    T *arg1;
    T *arg2;
    AddEdgeWithBothUnknownVertices(Graph<T> *g, T *v1, T *v2) :
        AddEdgeToUnknownVertice<T>(g, "Both first and second", v1->toString() + " and " + v2->toString()),
        arg1(v1),
        arg2(v2)
    {}
};

template<typename T>
class AddNullVertice : public InvalidArgument<T> {
public:
    void (Graph<T>::*func)(T *vertex) = &Graph<T>::addVertex;
    T *arg1;
    AddNullVertice(Graph<T> *g, T *v1) :
        InvalidArgument<T>(g, "NULL VERTICE: trying to add null vertice"),
        arg1(v1)
    {}
};

template<typename T>
class AddNullEdge : public InvalidArgument<T> {
public:
    void (Graph<T>::*func)(T *vertex) = &Graph<T>::addVertex;
    T *arg1;
    AddNullEdge(Graph<T> *g, T *v1) :
        InvalidArgument<T>(g, "NULL EDGE: trying to add null edge"),
        arg1(v1)
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
    void (Graph<T>::*func)(T *v1, T *v2) = &Graph<T>::addEdge;
    T *arg1;
    T *arg2;
    AddEdgeWithFirstNullVertice(Graph<T> *g, T *v1, T *v2) :
        AddEdgeToNullVertice<T>(g, "First"),
        arg1(v1),
        arg2(v2)
    {}
};

template<typename T>
class AddEdgeWithSecondNullVertice : public AddEdgeToNullVertice<T> {
public:
    void (Graph<T>::*func)(T *v1, T *v2) = &Graph<T>::addEdge;
    T *arg1;
    T *arg2;
    AddEdgeWithSecondNullVertice(Graph<T> *g, T *v1, T *v2) :
        AddEdgeToNullVertice<T>(g, "Second"),
        arg1(v1),
        arg2(v2)
    {}
};

template<typename T>
class AddEdgeWithBothNullVertices : public AddEdgeToNullVertice<T> {
public:
    void (Graph<T>::*func)(T *v1, T *v2) = &Graph<T>::addEdge;
    T *arg1;
    T *arg2;
    AddEdgeWithBothNullVertices(Graph<T> *g, T *v1, T *v2) :
        AddEdgeToNullVertice<T>(g, "Both first and second"),
        arg1(v1),
        arg2(v2)
    {}
};
#endif // EXCEPTIONS_H
