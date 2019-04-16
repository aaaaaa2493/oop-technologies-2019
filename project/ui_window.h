/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralWidget;
    QPushButton *addEdge;
    QPushButton *removeEdge;
    QPushButton *addItem;
    QPushButton *removeItem;
    QLineEdit *fromEdit;
    QLineEdit *toEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(729, 496);
        centralWidget = new QWidget(Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        addEdge = new QPushButton(centralWidget);
        addEdge->setObjectName(QStringLiteral("addEdge"));
        addEdge->setGeometry(QRect(110, 50, 80, 25));
        removeEdge = new QPushButton(centralWidget);
        removeEdge->setObjectName(QStringLiteral("removeEdge"));
        removeEdge->setGeometry(QRect(10, 10, 80, 25));
        addItem = new QPushButton(centralWidget);
        addItem->setObjectName(QStringLiteral("addItem"));
        addItem->setGeometry(QRect(10, 50, 80, 25));
        removeItem = new QPushButton(centralWidget);
        removeItem->setObjectName(QStringLiteral("removeItem"));
        removeItem->setGeometry(QRect(110, 10, 80, 25));
        fromEdit = new QLineEdit(centralWidget);
        fromEdit->setObjectName(QStringLiteral("fromEdit"));
        fromEdit->setGeometry(QRect(10, 90, 181, 24));
        toEdit = new QLineEdit(centralWidget);
        toEdit->setObjectName(QStringLiteral("toEdit"));
        toEdit->setGeometry(QRect(10, 130, 181, 24));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 0, 511, 421));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setSpacing(6);
        layout->setContentsMargins(11, 11, 11, 11);
        layout->setObjectName(QStringLiteral("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 25));
        Window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Window->setStatusBar(statusBar);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", nullptr));
        addEdge->setText(QApplication::translate("Window", "Add Edge", nullptr));
        removeEdge->setText(QApplication::translate("Window", "Remove Edge", nullptr));
        addItem->setText(QApplication::translate("Window", "Add Item", nullptr));
        removeItem->setText(QApplication::translate("Window", "Remove Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
