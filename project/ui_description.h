/********************************************************************************
** Form generated from reading UI file 'description.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCRIPTION_H
#define UI_DESCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Description
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Description)
    {
        if (Description->objectName().isEmpty())
            Description->setObjectName(QStringLiteral("Description"));
        Description->resize(800, 600);
        centralwidget = new QWidget(Description);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        Description->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Description);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Description->setMenuBar(menubar);
        statusbar = new QStatusBar(Description);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Description->setStatusBar(statusbar);

        retranslateUi(Description);

        QMetaObject::connectSlotsByName(Description);
    } // setupUi

    void retranslateUi(QMainWindow *Description)
    {
        Description->setWindowTitle(QApplication::translate("Description", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Description: public Ui_Description {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCRIPTION_H
