#include "graphdbhelper.h"
#include <QMessageBox>
#include <QDebug>

GraphDbHelper::GraphDbHelper()
{
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("graph.db");

    if (!sdb.open())
    {
           qDebug() << sdb.lastError().text();
    }
}

QList<Graph<Elem>*>* GraphDbHelper::Read()
{

    QList<Graph<Elem>*>* g = new QList<Graph<Elem>*>();
    QSqlQuery queryGraph;
    queryGraph.exec("SELECT * FROM Graphs");
    while (queryGraph.next()) {
             QString name = queryGraph.value(0).toString();
             g->push_back(new Graph<Elem>(name));
    }

    QSqlQuery queryVert;
    queryVert.exec("SELECT * FROM Vertices");
    while (queryVert.next())
    {
        QSqlRecord rec = queryVert.record();
             QString name = rec.value(1).toString();
             QString display = rec.value(0).toString();
             QString cont = rec.value(2).toString();
             for(Graph<Elem>* var : *g)
             {
                if(var->graphName == name)
                    var->addVertex(new Vertex<Elem>(Elem(display, name, cont)));
             }
    }

    QSqlQuery queryEdge;
    queryEdge.exec("SELECT * FROM Edges");
    while (queryEdge.next()) {
             QString from = queryEdge.value(0).toString();
             QString to = queryEdge.value(1).toString();
             QString graphName = queryEdge.value(2).toString();
             Vertex<Elem> *fromv = new Vertex<Elem>(Elem(from, "", ""));
             Vertex<Elem> *tov = new Vertex<Elem>(Elem(to, "", ""));
             for(Graph<Elem>* var : *g)
             {
                if(var->graphName == graphName)
                    var->addEdge(new Edge<Elem>(fromv, tov, graphName));
             }
    }

    return g;
}

void GraphDbHelper::writeVert(Vertex<Elem> *v)
{
    QSqlQuery vertQuery;
    auto f = v->value.graphName;
    vertQuery.prepare(
              QString("INSERT INTO Vertices(Name,GraphName,Description) values(:Name,:GraphName,:Description);"));
    vertQuery.bindValue(":Name", v->value.displayName);
    vertQuery.bindValue(":GraphName", v->value.graphName);
    vertQuery.bindValue(":Description", v->value.graphName);
    qDebug() << vertQuery.exec() << endl;
}

void GraphDbHelper::writeEdge(Edge<Elem> *e)
{
    QSqlQuery edgeQuery;
    auto f = e->graphName;
    edgeQuery.prepare(
              QString("INSERT INTO Edges(FromEdge,ToEdge,GraphName) values(:FromEdge,:ToEdge,:GraphName);"));
    edgeQuery.bindValue(":FromEdge", e->getFrom()->value.displayName);
    edgeQuery.bindValue(":ToEdge", e->getTo()->value.displayName);
    edgeQuery.bindValue(":GraphName",e->graphName);
    qDebug() << edgeQuery.exec() << endl;
}

void GraphDbHelper::deleteVert(Graph<Elem> *g, Vertex<Elem> *v)
{
    QSqlQuery query;

    query.prepare("DELETE FROM Vertices WHERE Name='" + v->value.displayName +
                  "' AND GraphName='" + v->value.graphName +"';");
    qDebug() << query.exec();

    for(auto item : *g->getEdges())
    {
        if(item->getFrom()->value.displayName == v->value.displayName)
        {
            QSqlQuery query;

            query.prepare("DELETE FROM Edges WHERE FromEdge='" + item->getFrom()->value.displayName +
                          "' AND GraphName='" + v->value.graphName +"';");
            qDebug() << query.exec();
        }

        if(item->getTo()->value.displayName == v->value.displayName)
        {
            QSqlQuery query;

            query.prepare("DELETE FROM Edges WHERE ToEdge='" + v->value.displayName +
                          "' AND GraphName='" + v->value.graphName +"';");

            qDebug() << query.exec();
        }
    }
}


void GraphDbHelper::deleteEdge(Edge<Elem> *e)
{
    QSqlQuery query;

    auto a = e->getFrom()->value.displayName;
    auto b = e->getTo()->value.displayName  ;
    auto c = e->graphName;

    query.prepare("DELETE FROM Edges WHERE FromEdge='" + e->getFrom()->value.displayName +
                  "' AND ToEdge='" + e->getTo()->value.displayName +
                  "' AND GraphName='" + e->graphName +"';");
    qDebug() << query.exec();
}


