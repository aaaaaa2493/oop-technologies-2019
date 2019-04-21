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
#include "windowadd.h"
#include "graphdbhelper.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    GraphDbHelper *helper = new GraphDbHelper();

    graph = helper->Read();

    svgTree = new QSvgWidget();

    ui->layout->addWidget(svgTree);
    svgTree->resize(svgTree->sizeHint());

    window = new WindowAdd(this);
    connect(window, SIGNAL(VertexAdded(Vertex*)),this,SLOT(onVertexAdded(Vertex*)));
    connect(window, SIGNAL(EdgeAdded(Edge*)),this,SLOT(onEdgeAdded(Edge*)));

    win = new DeleteWindow(this);
    connect(win, SIGNAL(VertexDeleted(Vertex*)),this,SLOT(onVertexDeleted(Vertex*)));
    connect(win, SIGNAL(EdgeDeleted(Edge*)),this,SLOT(onEdgeDeleted(Edge*)));

    onGraphChanged(graph);
}

Window::~Window()
{
    disconnect(window, SIGNAL(VertexAdded(Vertex*)),this,SLOT(onVertexAdded(Vertex*)));
    disconnect(window, SIGNAL(EdgeAdded(Edge*)),this,SLOT(onEdgeAdded(Edge*)));
    delete window;

    disconnect(win, SIGNAL(VertexDeleted(Vertex*)),this,SLOT(onVertexDeleted(Vertex*)));
    disconnect(win, SIGNAL(EdgeDeleted(Edge*)),this,SLOT(onEdgeDeleted(Edge*)));
    delete win;

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
    svgTree->resize(svgTree->sizeHint());
}

void Window::onVertexAdded(Vertex *v)
{
    graph->addVertex(v);
    onGraphChanged(graph);
}

void Window::onEdgeAdded(Edge *e)
{
    graph->addEdge(e);
    onGraphChanged(graph);
}

void Window::onVertexDeleted(Vertex *v)
{
    graph->removeVertex(v);
    onGraphChanged(graph);
}

void Window::onEdgeDeleted(Edge *e)
{
    graph->removeEdge(e);
    onGraphChanged(graph);
}

void Window::on_addItem_clicked()
{
    window->show();
}

void Window::on_addEdge_clicked()
{

}

void Window::on_Remove_clicked()
{
    win->show();
}
