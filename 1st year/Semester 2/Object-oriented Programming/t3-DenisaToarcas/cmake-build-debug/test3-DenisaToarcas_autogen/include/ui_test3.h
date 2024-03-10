/********************************************************************************
** Form generated from reading UI file 'test3.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3_H
#define UI_TEST3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test3
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QListWidget *ShoppingList1;
    QLabel *CategoryLabel;
    QLineEdit *CategoryLineEdit;
    QPushButton *ShowButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *test3)
    {
        if (test3->objectName().isEmpty())
            test3->setObjectName("test3");
        test3->resize(538, 475);
        centralwidget = new QWidget(test3);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        ShoppingList1 = new QListWidget(centralwidget);
        ShoppingList1->setObjectName("ShoppingList1");

        formLayout->setWidget(0, QFormLayout::SpanningRole, ShoppingList1);

        CategoryLabel = new QLabel(centralwidget);
        CategoryLabel->setObjectName("CategoryLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, CategoryLabel);

        CategoryLineEdit = new QLineEdit(centralwidget);
        CategoryLineEdit->setObjectName("CategoryLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, CategoryLineEdit);

        ShowButton = new QPushButton(centralwidget);
        ShowButton->setObjectName("ShowButton");

        formLayout->setWidget(2, QFormLayout::SpanningRole, ShowButton);

        test3->setCentralWidget(centralwidget);
        menubar = new QMenuBar(test3);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 538, 25));
        test3->setMenuBar(menubar);
        statusbar = new QStatusBar(test3);
        statusbar->setObjectName("statusbar");
        test3->setStatusBar(statusbar);

        retranslateUi(test3);
        QObject::connect(ShowButton, SIGNAL(clicked()), test3, SLOT(ShowCategory()));

        QMetaObject::connectSlotsByName(test3);
    } // setupUi

    void retranslateUi(QMainWindow *test3)
    {
        test3->setWindowTitle(QCoreApplication::translate("test3", "MainWindow", nullptr));
        CategoryLabel->setText(QCoreApplication::translate("test3", "Category", nullptr));
        ShowButton->setText(QCoreApplication::translate("test3", "Show all given category", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test3: public Ui_test3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3_H
