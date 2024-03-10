/********************************************************************************
** Form generated from reading UI file 'mainwindowDDgdMj.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWDDGDMJ_H
#define MAINWINDOWDDGDMJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *TESTlistWidget;
    QFormLayout *formLayout;
    QLabel *Artist;
    QLineEdit *ArtistlineEdit;
    QLabel *Title;
    QLineEdit *TitlelineEdit;
    QLabel *YTLink;
    QLineEdit *YTLinklineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        TESTlistWidget = new QListWidget(centralwidget);
        TESTlistWidget->setObjectName("TESTlistWidget");

        verticalLayout->addWidget(TESTlistWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        Artist = new QLabel(centralwidget);
        Artist->setObjectName("Artist");

        formLayout->setWidget(0, QFormLayout::LabelRole, Artist);

        ArtistlineEdit = new QLineEdit(centralwidget);
        ArtistlineEdit->setObjectName("ArtistlineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, ArtistlineEdit);

        Title = new QLabel(centralwidget);
        Title->setObjectName("Title");

        formLayout->setWidget(1, QFormLayout::LabelRole, Title);

        TitlelineEdit = new QLineEdit(centralwidget);
        TitlelineEdit->setObjectName("TitlelineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, TitlelineEdit);

        YTLink = new QLabel(centralwidget);
        YTLink->setObjectName("YTLink");

        formLayout->setWidget(2, QFormLayout::LabelRole, YTLink);

        YTLinklineEdit = new QLineEdit(centralwidget);
        YTLinklineEdit->setObjectName("YTLinklineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, YTLinklineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName("AddButton");

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName("DeleteButton");

        horizontalLayout->addWidget(DeleteButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Artist->setText(QCoreApplication::translate("MainWindow", "Artist", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        YTLink->setText(QCoreApplication::translate("MainWindow", "YT Link", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "Add Button", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "Delete Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWDDGDMJ_H
