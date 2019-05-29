#include "window.h"
#include "ui_window.h"
#include <QFile>
#include <QTextStream>
#include <QSvgWidget>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsView>
#include <QBoxLayout>
#include <QListView>
#include "data/list.h"
#include "data/vertex.h"
#include "data/edge.h"
#include "data/graph.h"
#include "windowadd.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    GraphDbHelper *helper = new GraphDbHelper();

    svgTree = new QSvgWidget();
    view = new QGraphicsView();
    view->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);

    //ui->layout->addWidget(svgTree);
    //svgTree->resize(svgTree->sizeHint());
    ui->layout->addWidget(view);

    helper = new GraphDbHelper();
    graphs = helper->Read();

    for(auto item : *graphs)
    {
        auto var = item->graphName;
        ui->GoalBox->addItem(item->graphName);
    }


    if(graphs->isEmpty())
    {
        graph = new Graph<Elem>();
        graphs->append(graph);
    }
    else
    {
        graph = graphs->first();
    }


    window = new WindowAdd(this);
    connect(window, SIGNAL(VertexAdded(Vertex<Elem>*)),this,SLOT(onVertexAdded(Vertex<Elem>*)));
    connect(window, SIGNAL(EdgeAdded(Edge<Elem>*)),this,SLOT(onEdgeAdded(Edge<Elem>*)));

    win = new DeleteWindow(this);
    connect(win, SIGNAL(VertexDeleted(Vertex<Elem>*)),this,SLOT(onVertexDeleted(Vertex<Elem>*)));
    connect(win, SIGNAL(EdgeDeleted(Edge<Elem>*)),this,SLOT(onEdgeDeleted(Edge<Elem>*)));

    onGraphChanged(graph);
}

Window::~Window()
{
    delete helper;

    disconnect(window, SIGNAL(VertexAdded(Vertex<Elem>*)),this,SLOT(onVertexAdded(Vertex<Elem>*)));
    disconnect(window, SIGNAL(EdgeAdded(Edge<Elem>*)),this,SLOT(onEdgeAdded(Edge<Elem>*)));
    delete window;

    disconnect(win, SIGNAL(VertexDeleted(Vertex<Elem>*)),this,SLOT(onVertexDeleted(Vertex<Elem>*)));
    disconnect(win, SIGNAL(EdgeDeleted(Edge<Elem>*)),this,SLOT(onEdgeDeleted(Edge<Elem>*)));
    delete win;

    delete ui;
    delete graph;
}

void Window::onGraphChanged(Graph<Elem> *graph)
{
    QFile file("graph.dot");

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream( &file );
        stream << "digraph {\n";

        List<Vertex<Elem>> *vertices = graph->getVertices();
        for (Vertex<Elem> *v : *vertices) {
            stream << " \"" << v->value.displayName << "\";\n";
        }

        List<Edge<Elem>> *edges = graph->getEdges();
        for (Edge<Elem> *e : *edges) {
            Vertex<Elem> *from = e->getFrom();
            Vertex<Elem> *to = e->getTo();
            stream << " \"" << from->value.displayName << "\" -> \"" << to->value.displayName << "\";\n";
        }

        stream << "}\n";
    }

    file.close();

    QString command("dot -Tsvg graph.dot -o graph.svg");

    system(command.toStdString().c_str());

    svgTree->load((QString) "graph.svg");

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(new QGraphicsSvgItem("graph.svg"));
    view->setScene(scene);
    view->show();

    svgTree->resize(svgTree->sizeHint());
    //svgTree->resize(svgTree->sizeHint());
}

void Window::onVertexAdded(Vertex<Elem> *v)
{
    v->value.graphName = graph->graphName;
    graph->addVertex(v);
    onGraphChanged(graph);

    helper->writeVert(v);
}

void Window::onEdgeAdded(Edge<Elem> *e)
{
    e->graphName = graph->graphName;
    graph->addEdge(e);

    onGraphChanged(graph);
    helper->writeEdge(e);
}

void Window::onVertexDeleted(Vertex<Elem> *v)
{
    v->value.graphName = graph->graphName;
    helper->deleteVert(graph, v);

    graph->removeVertex(v);
    onGraphChanged(graph);
}

void Window::onEdgeDeleted(Edge<Elem> *e)
{
    e->graphName = graph->graphName;

    graph->removeEdge(e);
    onGraphChanged(graph);
    helper->deleteEdge(e);
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

void Window::on_GoalBox_currentTextChanged(const QString &arg1)
{
    for(auto item : *graphs)
    {
        if(item->graphName == ui->GoalBox->currentText())
           graph = item;
    }
    ui->ThemeBox->clear();
    for(auto item : *graph->getVertices())
        ui->ThemeBox->addItem(item->value.displayName);
    onGraphChanged(graph);
}

void Window::on_ThemeBox_currentTextChanged(const QString &arg1)
{
    for(auto item : *graph->getVertices())
    {
        if(item->value.displayName == ui->ThemeBox->currentText())
           ui->textBrowser->setText(item->value.content);
    }
}

void Window::on_findWay_clicked()
{
    QString topicName = ui->ThemeBox->currentText();
    Vertex<Elem> *v = new Vertex<Elem>(Elem(topicName, "", ""));
    List<Vertex<Elem>> * list = graph->getLearningOrder(v);

    ui->list->reset();

    for (Vertex<Elem> * e : *list)
    {
        ui->list->addItem(e->value.displayName);
    }
}
