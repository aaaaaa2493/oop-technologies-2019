#include "window.h"
#include "ui_window.h"
#include <QFile>
#include <QTextStream>
#include <QSvgWidget>
#include <QBoxLayout>
#include "data/list.h"
#include "data/vertex.h"
#include "data/edge.h"
#include "data/graph.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    graph = new Graph();

    svgTree = new QSvgWidget("graph.svg");

    ui->layout->addWidget(svgTree);
}

Window::~Window()
{
    delete ui;
    delete graph;
}

void Window::onGraphChanged(Graph *graph)
{
    QFile file("graph.dot");

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream( &file );
        stream << "digraph {\n";

        List<Vertex> *vertices = graph->getVertices();
        vertices->toStart();
        bool isEnd = false;
        while (!isEnd && !vertices->isEmpty()) {
            stream << " \"" << vertices->get()->displayName << "\";\n";
            isEnd = vertices->isEnd();
            vertices->next();
        }

        List<Edge> *edges = graph->getEdges();
        edges->toStart();
        isEnd = false;
        while (!isEnd && !edges->isEmpty()) {
            Vertex *from = edges->get()->getFrom();
            Vertex *to = edges->get()->getTo();
            stream << " \"" << from->displayName << "\" -> \"" << to->displayName << "\";\n";
            isEnd = edges->isEnd();
            edges->next();
        }

        stream << "}\n";
    }

    file.close();

    QString command("dot -Tsvg graph.dot -o graph.svg");

    system(command.toStdString().c_str());

    svgTree->load((QString) "graph.svg");
}

void Window::on_addItem_clicked()
{
    QString vertexName(ui->fromEdit->text());
    Vertex *vertex = new Vertex(vertexName);
    graph->addVertex(vertex);
    onGraphChanged(graph);
}

void Window::on_addEdge_clicked()
{
    QString vertexFrom(ui->fromEdit->text());
    QString vertexTo(ui->toEdit->text());

    Vertex *from = graph->findVertex(vertexFrom);
    Vertex *to = graph->findVertex(vertexTo);

    if (from != nullptr && to != nullptr) {
        Edge *edge = new Edge(from, to);
        graph->addEdge(edge);
    }

    onGraphChanged(graph);
}
