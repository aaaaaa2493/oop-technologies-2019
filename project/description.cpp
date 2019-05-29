#include "description.h"
#include "ui_description.h"

Description::Description(QString title, QString text, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Description)
{
    ui->setupUi(this);
    ui->textEdit->setHtml(text);
    setWindowTitle(title);
}

Description::~Description()
{
    delete ui;
}
