#ifndef VERTEX_H
#define VERTEX_H

#include <QString>


class Vertex
{
public:
    Vertex(QString name): displayName(name) {}
    bool isVisited = false;
    const QString displayName;

};

#endif // VERTEX_H
