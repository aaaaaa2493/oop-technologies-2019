/********************************************************************************
** Form generated from reading UI file 'windowadd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWADD_H
#define UI_WINDOWADD_H

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

class Ui_WindowAdd
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *VertexEdit;
    QPushButton *AddVertexBut;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *FromEdit;
    QLineEdit *ToEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WindowAdd)
    {
        if (WindowAdd->objectName().isEmpty())
            WindowAdd->setObjectName(QString::fromUtf8("WindowAdd"));
        WindowAdd->resize(278, 367);
        centralwidget = new QWidget(WindowAdd);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 141, 16));
        VertexEdit = new QLineEdit(centralwidget);
        VertexEdit->setObjectName(QString::fromUtf8("VertexEdit"));
        VertexEdit->setGeometry(QRect(10, 40, 211, 20));
        AddVertexBut = new QPushButton(centralwidget);
        AddVertexBut->setObjectName(QString::fromUtf8("AddVertexBut"));
        AddVertexBut->setGeometry(QRect(10, 70, 75, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 160, 141, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 180, 47, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 230, 47, 13));
        FromEdit = new QLineEdit(centralwidget);
        FromEdit->setObjectName(QString::fromUtf8("FromEdit"));
        FromEdit->setGeometry(QRect(10, 200, 211, 20));
        ToEdit = new QLineEdit(centralwidget);
        ToEdit->setObjectName(QString::fromUtf8("ToEdit"));
        ToEdit->setGeometry(QRect(10, 250, 211, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 280, 75, 23));
        WindowAdd->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowAdd);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 278, 21));
        WindowAdd->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowAdd);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WindowAdd->setStatusBar(statusbar);

        retranslateUi(WindowAdd);

        QMetaObject::connectSlotsByName(WindowAdd);
    } // setupUi

    void retranslateUi(QMainWindow *WindowAdd)
    {
        WindowAdd->setWindowTitle(QApplication::translate("WindowAdd", "MainWindow", nullptr));
        label->setText(QApplication::translate("WindowAdd", "Enter item name", nullptr));
        AddVertexBut->setText(QApplication::translate("WindowAdd", "Add item", nullptr));
        label_2->setText(QApplication::translate("WindowAdd", "Enter edge parameters", nullptr));
        label_3->setText(QApplication::translate("WindowAdd", "From:", nullptr));
        label_4->setText(QApplication::translate("WindowAdd", "To:", nullptr));
        pushButton->setText(QApplication::translate("WindowAdd", "Add edge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowAdd: public Ui_WindowAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADD_H
