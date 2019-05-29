#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "vertex.h"
#include "edge.h"
#include "queue.h"
#include "stack.h"
#include "exceptions.h"

namespace data {

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

    Vertex<T> *findVertex(Vertex<T> *vert) {
        for (Vertex<T> *v : *vertices) {
            if (*v == *vert) {
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
            if (*curr == *v) {
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
            if (*ed->getFrom() == *from && *ed->getTo() == *to) {
                return true;
            }
        }

        return false;
    }

    void addVertex(Vertex<T> *v) {
        if (v == nullptr) {
            throw AddNullVertice<T>(this, v);
        }
        if (!containsVertex(v)) {
            vertices->addBefore(v);
        }
        else {
            throw AddExistingVertex<T>(this, v);
        }
    }

    void addEdge(Edge<T> *edge) {
        if (edge == nullptr) {
            throw AddNullEdge<T>(this, edge);
        }

        Vertex<T> *fromV = edge->getFrom();
        Vertex<T> *toV = edge->getTo();

        if (fromV == nullptr && toV == nullptr) {
            throw AddEdgeWithBothNullVertices<T>(this, edge);
        }
        else if (fromV == nullptr) {
            throw AddEdgeWithFirstNullVertice<T>(this, edge);
        }
        else if (toV == nullptr) {
            throw AddEdgeWithSecondNullVertice<T>(this, edge);
        }

        bool from = containsVertex(edge->getFrom());
        bool to = containsVertex(edge->getTo());

        if (!from && !to) {
            throw AddEdgeWithBothUnknownVertices<T>(this, edge);
        }
        else if (!from) {
            throw AddEdgeWithFirstUnknownVertice<T>(this, edge);
        }
        else if (!to) {
            throw AddEdgeWithSecondUnknownVertice<T>(this, edge);
        }

        if (!containsEdge(edge)) {
            edges->addAfter(new Edge<T>(
                findVertex(fromV),
                findVertex(toV),
                edge->graphName
            ));
        }
        else {
            throw AddExistingEdge<T>(this, edge);
        }
    }

    void removeEdge(Edge<T> *e) {
        Vertex<T> *from = e->getFrom();
        Vertex<T> *to = e->getTo();
        bool isEnd = edges->isEmpty();
        edges->toStart();
        while (!isEnd) {
            Edge<T> *curr = edges->get();
            if (*curr->getFrom() == *from && *curr->getTo() == *to) {
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
            if (*curr->getFrom() == *v || *curr->getTo() == *v) {
                edges->deleteCurr();
                edges->prev();
            }
            isEnd = edges->isEnd();
            edges->next();
        }
        if (!edges->isEmpty()) {
            Edge<T> *curr = edges->get();
            if (*curr->getFrom() == *v || *curr->getTo() == *v) {
                edges->deleteCurr();
                edges->prev();
            }
        }

        vertices->toStart();
        isEnd = vertices->isEmpty();
        while (!isEnd) {
            Vertex<T> *curr = vertices->get();
            if (*curr == *v) {
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

        Vertex<T> *final = findVertex(finalTopic);

        list->prepend(final);
        final->isVisited = true;

        for (Edge<T> *e : *edges) {
            if (e->getTo() == final) {
                e->getTo()->isVisited = true;
            }
            if (e->getFrom() == final) {
                e->getFrom()->isVisited = true;
            }
        }

        bool is_end = false;
        while (!is_end) {
            is_end = true;

            for (Edge<T> *e : *edges) {
                if (e->getTo()->isVisited && !e->getFrom()->isVisited) {

                    Vertex<T> *curr = findVertex(e->getFrom());
                    list->prepend(curr);

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

}

#endif // GRAPH_H
