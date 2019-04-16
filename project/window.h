#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QSvgWidget>
#include "data/graph.h"

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

    Graph *graph;
    QSvgWidget *svgTree;


public slots:
    void onGraphChanged(Graph *graph);
private slots:
    void on_addItem_clicked();
    void on_addEdge_clicked();
};

#endif // WINDOW_H
