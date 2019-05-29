#include "windowadd.h"
#include "ui_windowadd.h"

WindowAdd::WindowAdd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowAdd)
{
    ui->setupUi(this);
}

WindowAdd::~WindowAdd()
{
    delete ui;
}

void WindowAdd::on_AddVertexBut_clicked()
{
    QString s = ui->VertexEdit->text();
    emit VertexAdded(new Vertex<Elem>(Elem(s, "", "")));
}

void WindowAdd::on_pushButton_clicked()
{
    Vertex<Elem> *from = new Vertex<Elem>(Elem(ui->FromEdit->text(), "", ""));
    Vertex<Elem> *to = new Vertex<Elem>(Elem(ui->ToEdit->text(), "", ""));
    emit EdgeAdded(new Edge<Elem>(from, to, ""));
}
