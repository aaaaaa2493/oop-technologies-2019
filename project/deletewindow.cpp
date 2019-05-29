#include "deletewindow.h"
#include "ui_deletewindow.h"

DeleteWindow::DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_VertexDel_clicked()
{
    QString s = ui->VertexEdit->text();
    data::Vertex<Elem> *vert = data::Vertex<Elem>::create(Elem(s, "", ""));
    emit VertexDeleted(vert);
}

void DeleteWindow::on_EdgeDel_clicked()
{
    data::Vertex<Elem> *from = data::Vertex<Elem>::create(Elem(ui->FromEdit->text(), "", ""));
    data::Vertex<Elem> *to = data::Vertex<Elem>::create(Elem(ui->ToEdit->text(), "", ""));
    emit EdgeDeleted(new data::Edge<Elem>(from, to, ""));
}
