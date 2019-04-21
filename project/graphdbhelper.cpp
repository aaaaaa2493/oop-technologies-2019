#include "graphdbhelper.h"

GraphDbHelper::GraphDbHelper()
{

}

Graph* GraphDbHelper::Read()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }
    Graph *g = new Graph();
    QSqlQuery queryVert("SELECT * FROM Vertices");
    while (queryVert.next()) {
             QString name = queryVert.value(0).toString();
             g->addVertex(new Vertex(name));
    }

    QSqlQuery query("SELECT * FROM Edges");
    while (query.next()) {
             QString from = query.value(0).toString();
             QString to = query.value(1).toString();
             Vertex *fromv = new Vertex(from);
             Vertex *tov = new Vertex(to);
             g->addEdge(new Edge(fromv, tov));
    }
    sdb.close();
    return g;
}

void GraphDbHelper::Write(Graph *graph)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }

}
