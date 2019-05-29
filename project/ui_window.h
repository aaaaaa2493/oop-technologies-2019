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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QComboBox *GoalBox;
    QLabel *label;
    QComboBox *ThemeBox;
    QPushButton *findWay;
    QPushButton *Remove;
    QPushButton *addItem;
    QListWidget *list;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *layout;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(1173, 717);
        Window->setAutoFillBackground(true);
        centralWidget = new QWidget(Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        GoalBox = new QComboBox(centralWidget);
        GoalBox->setObjectName(QStringLiteral("GoalBox"));

        verticalLayout->addWidget(GoalBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        ThemeBox = new QComboBox(centralWidget);
        ThemeBox->setObjectName(QStringLiteral("ThemeBox"));

        verticalLayout->addWidget(ThemeBox);

        findWay = new QPushButton(centralWidget);
        findWay->setObjectName(QStringLiteral("findWay"));

        verticalLayout->addWidget(findWay);

        Remove = new QPushButton(centralWidget);
        Remove->setObjectName(QStringLiteral("Remove"));

        verticalLayout->addWidget(Remove);

        addItem = new QPushButton(centralWidget);
        addItem->setObjectName(QStringLiteral("addItem"));

        verticalLayout->addWidget(addItem);

        list = new QListWidget(centralWidget);
        list->setObjectName(QStringLiteral("list"));

        verticalLayout->addWidget(list);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        layout = new QVBoxLayout();
        layout->setSpacing(6);
        layout->setObjectName(QStringLiteral("layout"));
        layout->setSizeConstraint(QLayout::SetNoConstraint);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        layout->addWidget(label_3);


        horizontalLayout->addLayout(layout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1173, 25));
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
        label_2->setText(QApplication::translate("Window", "Selected theme", nullptr));
        label->setText(QApplication::translate("Window", "Selected goal", nullptr));
        findWay->setText(QApplication::translate("Window", "Find way?", nullptr));
        Remove->setText(QApplication::translate("Window", "Remove", nullptr));
        addItem->setText(QApplication::translate("Window", "Add", nullptr));
        label_3->setText(QApplication::translate("Window", "Goal scheme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
