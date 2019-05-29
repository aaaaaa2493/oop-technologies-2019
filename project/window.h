#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QSvgWidget>
#include "data/graph.h"
#include "windowadd.h"
#include "deletewindow.h"

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
    QSvgWidget *svgTree;

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
};

#endif // WINDOW_H
