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
    emit VertexAdded(data::Vertex<Elem>::create(Elem(s, "", "")));
}

void WindowAdd::on_pushButton_clicked()
{
    data::Vertex<Elem> *from = data::Vertex<Elem>::create(Elem(ui->FromEdit->text(), "", ""));
    data::Vertex<Elem> *to = data::Vertex<Elem>::create(Elem(ui->ToEdit->text(), "", ""));
    emit EdgeAdded(new data::Edge<Elem>(from, to, ""));
}
