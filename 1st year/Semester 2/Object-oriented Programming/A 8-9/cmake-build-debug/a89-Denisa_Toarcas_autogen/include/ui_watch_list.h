/********************************************************************************
** Form generated from reading UI file 'watch_list.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCH_LIST_H
#define UI_WATCH_LIST_H

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

class Ui_AdministratorWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *ListOfTutorials;
    QFormLayout *formLayout;
    QLabel *TitleLabel;
    QLineEdit *TitlelineEdit;
    QLabel *PresenterLabel;
    QLineEdit *PresenterlineEdit;
    QLabel *DurationLabel;
    QLabel *MinutesLabel;
    QLineEdit *MinuteslineEdit;
    QLabel *SeconsLabel;
    QLineEdit *SecondslineEdit;
    QLabel *LikesLabel;
    QLineEdit *LikeslineEdit;
    QLabel *LinkLabel;
    QLineEdit *LinklineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *UpdateButton;
    QPushButton *ListAllButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdministratorWindow)
    {
        if (AdministratorWindow->objectName().isEmpty())
            AdministratorWindow->setObjectName("AdministratorWindow");
        AdministratorWindow->resize(800, 600);
        centralwidget = new QWidget(AdministratorWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        ListOfTutorials = new QListWidget(centralwidget);
        ListOfTutorials->setObjectName("ListOfTutorials");

        verticalLayout->addWidget(ListOfTutorials);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        TitleLabel = new QLabel(centralwidget);
        TitleLabel->setObjectName("TitleLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, TitleLabel);

        TitlelineEdit = new QLineEdit(centralwidget);
        TitlelineEdit->setObjectName("TitlelineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, TitlelineEdit);

        PresenterLabel = new QLabel(centralwidget);
        PresenterLabel->setObjectName("PresenterLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, PresenterLabel);

        PresenterlineEdit = new QLineEdit(centralwidget);
        PresenterlineEdit->setObjectName("PresenterlineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, PresenterlineEdit);

        DurationLabel = new QLabel(centralwidget);
        DurationLabel->setObjectName("DurationLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, DurationLabel);

        MinutesLabel = new QLabel(centralwidget);
        MinutesLabel->setObjectName("MinutesLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, MinutesLabel);

        MinuteslineEdit = new QLineEdit(centralwidget);
        MinuteslineEdit->setObjectName("MinuteslineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, MinuteslineEdit);

        SeconsLabel = new QLabel(centralwidget);
        SeconsLabel->setObjectName("SeconsLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, SeconsLabel);

        SecondslineEdit = new QLineEdit(centralwidget);
        SecondslineEdit->setObjectName("SecondslineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, SecondslineEdit);

        LikesLabel = new QLabel(centralwidget);
        LikesLabel->setObjectName("LikesLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, LikesLabel);

        LikeslineEdit = new QLineEdit(centralwidget);
        LikeslineEdit->setObjectName("LikeslineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, LikeslineEdit);

        LinkLabel = new QLabel(centralwidget);
        LinkLabel->setObjectName("LinkLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, LinkLabel);

        LinklineEdit = new QLineEdit(centralwidget);
        LinklineEdit->setObjectName("LinklineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, LinklineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName("AddButton");

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName("DeleteButton");

        horizontalLayout->addWidget(DeleteButton);

        UpdateButton = new QPushButton(centralwidget);
        UpdateButton->setObjectName("UpdateButton");

        horizontalLayout->addWidget(UpdateButton);

        ListAllButton = new QPushButton(centralwidget);
        ListAllButton->setObjectName("ListAllButton");

        horizontalLayout->addWidget(ListAllButton);


        verticalLayout->addLayout(horizontalLayout);

        AdministratorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdministratorWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        AdministratorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdministratorWindow);
        statusbar->setObjectName("statusbar");
        AdministratorWindow->setStatusBar(statusbar);

        retranslateUi(AdministratorWindow);

        QMetaObject::connectSlotsByName(AdministratorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdministratorWindow)
    {
        AdministratorWindow->setWindowTitle(QCoreApplication::translate("AdministratorWindow", "MainWindow", nullptr));
        TitleLabel->setText(QCoreApplication::translate("AdministratorWindow", "Title", nullptr));
        PresenterLabel->setText(QCoreApplication::translate("AdministratorWindow", "Presenter", nullptr));
        DurationLabel->setText(QCoreApplication::translate("AdministratorWindow", "Duration", nullptr));
        MinutesLabel->setText(QCoreApplication::translate("AdministratorWindow", "Minutes", nullptr));
        SeconsLabel->setText(QCoreApplication::translate("AdministratorWindow", "Seconds", nullptr));
        LikesLabel->setText(QCoreApplication::translate("AdministratorWindow", "Likes", nullptr));
        LinkLabel->setText(QCoreApplication::translate("AdministratorWindow", "Link", nullptr));
        AddButton->setText(QCoreApplication::translate("AdministratorWindow", "Add a tutorial", nullptr));
        DeleteButton->setText(QCoreApplication::translate("AdministratorWindow", "Delete a tutorial", nullptr));
        UpdateButton->setText(QCoreApplication::translate("AdministratorWindow", "Update a tutorial", nullptr));
        ListAllButton->setText(QCoreApplication::translate("AdministratorWindow", "List all tutorials", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorWindow: public Ui_AdministratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCH_LIST_H
