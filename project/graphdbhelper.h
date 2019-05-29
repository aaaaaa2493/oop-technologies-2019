#ifndef GRAPHDBHELPER_H
#define GRAPHDBHELPER_H

#include "data/graph.h"
#include "data/list.h"
#include <QtSql>
#include <QList>

class GraphDbHelper
{
public:
    GraphDbHelper();
    QList<Graph<Elem>*>* Read();

    void writeVert(Vertex<Elem> *v);
    void writeEdge(Edge<Elem> *e);
    void deleteEdge(Edge<Elem> *e);
    void deleteVert(Graph<Elem> *g, Vertex<Elem> *v);
    void writeGraph(QString name);
    void deleteGraph(Graph<Elem> * g);
};

#endif // GRAPHDBHELPER_H
