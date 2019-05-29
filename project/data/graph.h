#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "vertex.h"
#include "edge.h"
#include "queue.h"
#include "stack.h"
#include "exceptions.h"

template <typename T>
class Graph
{
    List<Vertex<T>> *vertices = new List<Vertex<T>>();
    List<Edge<T>> *edges = new List<Edge<T>>();

    void resetVertices() {
        for (Vertex<T> *v : *vertices) {
            v->isVisited = false;
        }
        for (Edge<T> *e : *edges) {
            e->getFrom()->isVisited = false;
            e->getTo()->isVisited = false;
        }
    }

public:
    QString graphName;
    Graph(){ }
    Graph(QString name) {graphName = name; }
    ~Graph() {
        delete vertices;
        delete edges;
    }

    List<Vertex<T>> *getVertices() {
        return vertices;
    }

    List<Edge<T>> *getEdges() {
        return edges;
    }

    Vertex<T> *findVertex(QString name) {
        for (Vertex<T> *v : *vertices) {
            if (v->value.displayName == name) {
                return v;
            }
        }
        return nullptr;
    }

    bool containsVertex(Vertex<T> *v) {
        bool isEmpty = vertices->isEmpty();
        if (isEmpty) {
            return false;
        }

        for (Vertex<T> *curr : *vertices) {
            if (curr->value.displayName == v->value.displayName) {
                return true;
            }
        }

        return false;
    }

    bool containsEdge(Edge<T> *e) {
        bool isEmpty = edges->isEmpty();
        if (isEmpty) {
            return false;
        }
        Vertex<T> *from = e->getFrom();
        Vertex<T> *to = e->getTo();

        for (Edge<T> *ed : *edges) {
            if (ed->getFrom() == from && ed->getTo() == to) {
                return true;
            }
        }

        return false;
    }

    void addVertex(Vertex<T> *v) {
        if (!containsVertex(v)) {
            vertices->addBefore(v);
        }
        else {
            throw;
        }
    }

    void addEdge(Edge<T> *edge) {
        if (!containsEdge(edge)) {
            edges->addAfter(new Edge<T>(
                findVertex(edge->getFrom()->value.displayName),
                findVertex(edge->getTo()->value.displayName),
                edge->graphName
            ));
        }
        else {
            throw;
        }
    }

    void removeEdge(Edge<T> *e) {
        Vertex<T> *from = e->getFrom();
        Vertex<T> *to = e->getTo();
        bool isEnd = edges->isEmpty();
        edges->toStart();
        while (!isEnd) {
            Edge<T> *curr = edges->get();
            if (curr->getFrom() == from && curr->getTo() == to) {
                edges->deleteCurr();
                return;
            }
            isEnd = edges->isEnd();
            edges->next();
        }
        throw;
    }

    void removeEdge(QString from, QString to) {
        bool isEnd = edges->isEmpty();
        edges->toStart();
        while (!isEnd) {
            Edge<T> *curr = edges->get();
            if (curr->getFrom()->value.displayName == from && curr->getTo()->value.displayName == to) {
                edges->deleteCurr();
                return;
            }
            isEnd = edges->isEnd();
            edges->next();
        }
        throw;
    }

    void removeVertex(Vertex<T> *v) {
        if (!containsVertex(v)) {
            throw;
        }
        bool isEnd = edges->isEmpty();
        edges->toStart();
        while (!isEnd) {
            Edge<T> *curr = edges->get();
            if (curr->getFrom()->displayName == v->displayName
                    || curr->getTo()->displayName == v->displayName) {
                edges->deleteCurr();
                edges->prev();
            }
            isEnd = edges->isEnd();
            edges->next();
        }
        if (!edges->isEmpty()) {
            Edge<T> *curr = edges->get();
            if (curr->getFrom()->displayName == v->displayName
                    || curr->getTo()->displayName == v->displayName) {
                edges->deleteCurr();
                edges->prev();
            }
        }

        vertices->toStart();
        isEnd = vertices->isEmpty();
        while (!isEnd) {
            Vertex<T> *curr = vertices->get();
            if (curr->displayName == v->displayName) {
                vertices->deleteCurr();
                return;
            }
            isEnd = vertices->isEnd();
            vertices->next();
        }
        throw;
    }

    void removeVertex(QString v) {
        bool isEnd = edges->isEmpty();
        edges->toStart();
        while (!isEnd) {
            Edge<T> *curr = edges->get();
            if (curr->getFrom()->value.displayName == v || curr->getTo()->value.displayName == v) {
                edges->deleteCurr();
                edges->prev();
            }
            isEnd = edges->isEnd();
            edges->next();
        }
        if (!edges->isEmpty()) {
            Edge<T> *curr = edges->get();
            if (curr->getFrom()->value.displayName == v
                    || curr->getTo()->value.displayName == v) {
                edges->deleteCurr();
                edges->prev();
            }
        }

        vertices->toStart();
        isEnd = vertices->isEmpty();
        while (!isEnd) {
            Vertex<T> *curr = vertices->get();
            if (curr->value.displayName == v) {
                vertices->deleteCurr();
                return;
            }
            isEnd = vertices->isEnd();
            vertices->next();
        }
        throw;
    }


    List<Vertex<T>> *BFS(Vertex<T> *v) {

        resetVertices();

        Queue<Vertex<T>> *queue = new Queue<Vertex<T>>();
        List<Vertex<T>> *list = new List<Vertex<T>>();

        v->isVisited = true;
        list->addAfter(v);
        queue->push(v);

        while (!queue->isEmpty()) {
             Vertex<T> *currVertex = queue->pop();

             bool isEnd = edges->isEmpty();
             edges->toStart();
             while (!isEnd) {
                 Edge<T> *currEdge = edges->get();
                 if (currEdge->getFrom() == currVertex && !currEdge->getTo()->isVisited) {
                     Vertex<T> *nextVertex = currEdge->getTo();
                     nextVertex->isVisited = true;
                     queue->push(nextVertex);
                     list->addAfter(nextVertex);
                 }
                 isEnd = edges->isEnd();
                 edges->next();
             }
        }

        delete queue;
        return list;
    }


    List<Vertex<T>> *DFS(Vertex<T> *v) {

        resetVertices();

        List<Vertex<T>> *list = new List<Vertex<T>>();
        Stack<Vertex<T>> *stack = new Stack<Vertex<T>>();

        v->isVisited = true;
        list->addAfter(v);

        Vertex<T> *currVertex = v;

        while (true) {

            bool isDeeper = false;

            bool isEnd = edges->isEmpty();
            edges->toStart();
            while (!isEnd) {
                Edge<T> *currEdge = edges->get();
                if (currEdge->getFrom() == currVertex && !currEdge->getTo()->isVisited) {
                    currVertex = currEdge->getTo();
                    currVertex->isVisited = true;
                    list->addAfter(currVertex);
                    stack->push(currVertex);
                    isDeeper = true;
                    break;
                }
                isEnd = edges->isEnd();
                edges->next();
            }

            if (!isDeeper) {
                if (stack->isEmpty()) {
                    break;
                }
                else {
                    currVertex = stack->pop();
                }
            }
        }

        delete stack;
        return list;
    }


    List<Vertex<T>> *getLearningOrder(Vertex<T> *finalTopic) {

        resetVertices();
        List<Vertex<T>> *list = new List<Vertex<T>>();

        Vertex<T> *final = findVertex(finalTopic->displayName);

        list->addBefore(final);
        final->isVisited = true;

        for (Edge<T> *e : *edges) {
            if (e->getTo()->displayName == final->displayName) {
                e->getTo()->isVisited = true;
            }
            if (e->getFrom()->displayName == final->displayName) {
                e->getFrom()->isVisited = true;
            }
        }

        bool is_end = false;
        while (!is_end) {
            is_end = true;

            for (Edge<T> *e : *edges) {
                if (e->getTo()->isVisited && !e->getFrom()->isVisited) {

                    Vertex<T> *curr = findVertex(e->getFrom()->displayName);
                    list->addAfter(curr);

                    e->getFrom()->isVisited = true;
                    curr->isVisited = true;

                    is_end = false;
                }
            }
        }

        resetVertices();

        return list;
    }

};

#endif // GRAPH_H
