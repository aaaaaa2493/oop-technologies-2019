/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *VertexEdit;
    QPushButton *VertexDel;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *FromEdit;
    QLabel *label_4;
    QLineEdit *ToEdit;
    QPushButton *EdgeDel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeleteWindow)
    {
        if (DeleteWindow->objectName().isEmpty())
            DeleteWindow->setObjectName(QString::fromUtf8("DeleteWindow"));
        DeleteWindow->resize(240, 423);
        centralwidget = new QWidget(DeleteWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 111, 16));
        VertexEdit = new QLineEdit(centralwidget);
        VertexEdit->setObjectName(QString::fromUtf8("VertexEdit"));
        VertexEdit->setGeometry(QRect(10, 60, 113, 20));
        VertexDel = new QPushButton(centralwidget);
        VertexDel->setObjectName(QString::fromUtf8("VertexDel"));
        VertexDel->setGeometry(QRect(10, 90, 81, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 160, 101, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 200, 47, 13));
        FromEdit = new QLineEdit(centralwidget);
        FromEdit->setObjectName(QString::fromUtf8("FromEdit"));
        FromEdit->setGeometry(QRect(20, 220, 113, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 250, 47, 13));
        ToEdit = new QLineEdit(centralwidget);
        ToEdit->setObjectName(QString::fromUtf8("ToEdit"));
        ToEdit->setGeometry(QRect(20, 270, 113, 20));
        EdgeDel = new QPushButton(centralwidget);
        EdgeDel->setObjectName(QString::fromUtf8("EdgeDel"));
        EdgeDel->setGeometry(QRect(20, 290, 75, 23));
        DeleteWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DeleteWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 21));
        DeleteWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DeleteWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeleteWindow->setStatusBar(statusbar);

        retranslateUi(DeleteWindow);

        QMetaObject::connectSlotsByName(DeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteWindow)
    {
        DeleteWindow->setWindowTitle(QApplication::translate("DeleteWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("DeleteWindow", "Enter Vertex", nullptr));
        VertexDel->setText(QApplication::translate("DeleteWindow", "Delete Vertex", nullptr));
        label_2->setText(QApplication::translate("DeleteWindow", "Enter Edge", nullptr));
        label_3->setText(QApplication::translate("DeleteWindow", "From", nullptr));
        label_4->setText(QApplication::translate("DeleteWindow", "To", nullptr));
        EdgeDel->setText(QApplication::translate("DeleteWindow", "Delete Edge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteWindow: public Ui_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
