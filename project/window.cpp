#include "window.h"
#include "ui_window.h"
#include <QFile>
#include <QTextStream>
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
    setWindowTitle("Visual Education");

    GraphDbHelper *helper = new GraphDbHelper();

    view = new QGraphicsView();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    zoom = new MouseZoom(view);
    zoom->set_modifiers(Qt::NoModifier);

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
        graph = new data::Graph<Elem>();
        graphs->append(graph);
    }
    else
    {
        graph = graphs->first();
    }


    window = new WindowAdd(this);
    connect(window, SIGNAL(VertexAdded(data::Vertex<Elem>*)),this,SLOT(onVertexAdded(data::Vertex<Elem>*)));
    connect(window, SIGNAL(EdgeAdded(data::Edge<Elem>*)),this,SLOT(onEdgeAdded(data::Edge<Elem>*)));

    win = new DeleteWindow(this);
    connect(win, SIGNAL(VertexDeleted(data::Vertex<Elem>*)),this,SLOT(onVertexDeleted(data::Vertex<Elem>*)));
    connect(win, SIGNAL(EdgeDeleted(data::Edge<Elem>*)),this,SLOT(onEdgeDeleted(data::Edge<Elem>*)));

    onGraphChanged(graph);
}

Window::~Window()
{
    delete helper;

    disconnect(window, SIGNAL(VertexAdded(data::Vertex<Elem>*)),this,SLOT(onVertexAdded(data::Vertex<Elem>*)));
    disconnect(window, SIGNAL(EdgeAdded(data::Edge<Elem>*)),this,SLOT(onEdgeAdded(data::Edge<Elem>*)));
    delete window;

    disconnect(win, SIGNAL(VertexDeleted(data::Vertex<Elem>*)),this,SLOT(onVertexDeleted(data::Vertex<Elem>*)));
    disconnect(win, SIGNAL(EdgeDeleted(data::Edge<Elem>*)),this,SLOT(onEdgeDeleted(data::Edge<Elem>*)));
    delete win;

    delete ui;
    delete graph;
}

void Window::onGraphChanged(data::Graph<Elem> *graph)
{
    QFile file("graph.dot");

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream( &file );
        stream << "digraph {\n";

        data::List<data::Vertex<Elem>> *vertices = graph->getVertices();
        for (data::Vertex<Elem> *v : *vertices) {
            stream << " \"" << v->value.displayName << "\";\n";
        }

        data::List<data::Edge<Elem>> *edges = graph->getEdges();
        for (data::Edge<Elem> *e : *edges) {
            data::Vertex<Elem> *from = e->getFrom();
            data::Vertex<Elem> *to = e->getTo();
            stream << " \"" << from->value.displayName << "\" -> \"" << to->value.displayName << "\";\n";
        }

        stream << "}\n";
    }

    file.close();

    QString command("dot -Tsvg graph.dot -o graph.svg");

    system(command.toStdString().c_str());

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(new QGraphicsSvgItem("graph.svg"));
    view->setScene(scene);
    view->show();
}

void Window::onVertexAdded(data::Vertex<Elem> *v)
{
    v->value.graphName = graph->graphName;
    graph->addVertex(v);
    onGraphChanged(graph);

    helper->writeVert(v);
}

void Window::onEdgeAdded(data::Edge<Elem> *e)
{
    e->graphName = graph->graphName;
    graph->addEdge(e);

    onGraphChanged(graph);
    helper->writeEdge(e);
}

void Window::onVertexDeleted(data::Vertex<Elem> *v)
{
    v->value.graphName = graph->graphName;
    helper->deleteVert(graph, v);

    graph->removeVertex(v);
    onGraphChanged(graph);
}

void Window::onEdgeDeleted(data::Edge<Elem> *e)
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
{ }

void Window::on_findWay_clicked()
{
    QString topicName = ui->ThemeBox->currentText();
    data::Vertex<Elem> *v = data::Vertex<Elem>::create(Elem(topicName, "", ""));
    data::List<data::Vertex<Elem>> * list = graph->getLearningOrder(v);

    ui->list->reset();

    for (data::Vertex<Elem> * e : *list)
    {
        ui->list->addItem(e->value.displayName);
    }
}

void Window::on_list_itemDoubleClicked(QListWidgetItem *item)
{
    QString topicName = item->text();
    data::Vertex<Elem> *v = data::Vertex<Elem>::create(Elem(topicName, "", ""));
    data::Vertex<Elem> *actualV = graph->findVertex(v);

    (new Description(topicName, actualV->value.content))->show();
}
