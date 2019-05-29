#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QListWidgetItem>
#include "data/graph.h"
#include "windowadd.h"
#include "deletewindow.h"
#include "graphdbhelper.h"
#include "description.h"
#include "mousezoom.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private:
    Ui::Window *ui;

    QList<QString> selectedGraphs;

    QList<Graph<Elem>*> *graphs;

    DeleteWindow *win;
    WindowAdd *window;
    Graph<Elem> *graph;
    QGraphicsView *view;
    MouseZoom *zoom;

    GraphDbHelper *helper;

    void onGraphChanged(Graph<Elem> *graph);
public slots:   
    void onVertexAdded(Vertex<Elem> *v);
    void onEdgeAdded(Edge<Elem> *e);

    void onVertexDeleted(Vertex<Elem> *v);
    void onEdgeDeleted(Edge<Elem> *e);
private slots:
    void on_addItem_clicked();
    void on_addEdge_clicked();
    void on_Remove_clicked();
    void on_GoalBox_currentTextChanged(const QString &arg1);
    void on_ThemeBox_currentTextChanged(const QString &arg1);
    void on_findWay_clicked();
    void on_list_itemDoubleClicked(QListWidgetItem *item);
};

#endif // WINDOW_H
