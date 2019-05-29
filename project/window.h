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

    QList<data::Graph<Elem>*> *graphs;

    DeleteWindow *win;
    WindowAdd *window;
    data::Graph<Elem> *graph;
    QGraphicsView *view;
    MouseZoom *zoom;

    GraphDbHelper *helper;

    void onGraphChanged(data::Graph<Elem> *graph);
public slots:   
    void onVertexAdded(data::Vertex<Elem> *v);
    void onEdgeAdded(data::Edge<Elem> *e);

    void onVertexDeleted(data::Vertex<Elem> *v);
    void onEdgeDeleted(data::Edge<Elem> *e);
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
