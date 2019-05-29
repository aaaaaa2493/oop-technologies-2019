#ifndef GRAPHDBHELPER_H
#define GRAPHDBHELPER_H

#include "data/graph.h"
#include "data/list.h"
#include <QtSql>
#include <QList>

class GraphDbHelper
{
    QSqlDatabase sdb;

public:
    GraphDbHelper();
    ~GraphDbHelper() {
        sdb.close();
    }

    QList<data::Graph<Elem>*>* Read();

    void writeVert(data::Vertex<Elem> *v);
    void updateVert(data::Vertex<Elem> *v);
    void writeEdge(data::Edge<Elem> *e);
    void deleteEdge(data::Edge<Elem> *e);
    void deleteVert(data::Graph<Elem> *g, data::Vertex<Elem> *v);
    void writeGraph(QString name);
    void deleteGraph(data::Graph<Elem> * g);
};

#endif // GRAPHDBHELPER_H
