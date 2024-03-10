/********************************************************************************
** Form generated from reading UI file 'AdministratorWindowhbaEAF.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADMINISTRATORWINDOWHBAEAF_H
#define ADMINISTRATORWINDOWHBAEAF_H

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

class Ui_AdministratorMode
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
    QLabel *SecondsLabel;
    QLineEdit *SecondslineEdit;
    QLabel *LikesLabel;
    QLineEdit *LikeslineEdit;
    QLabel *LinkLabel;
    QLineEdit *LinklineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *UpdateButton;
    QPushButton *ListButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdministratorMode)
    {
        if (AdministratorMode->objectName().isEmpty())
            AdministratorMode->setObjectName("AdministratorMode");
        AdministratorMode->resize(800, 600);
        centralwidget = new QWidget(AdministratorMode);
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

        SecondsLabel = new QLabel(centralwidget);
        SecondsLabel->setObjectName("SecondsLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, SecondsLabel);

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

        ListButton = new QPushButton(centralwidget);
        ListButton->setObjectName("ListButton");

        horizontalLayout->addWidget(ListButton);


        verticalLayout->addLayout(horizontalLayout);

        AdministratorMode->setCentralWidget(centralwidget);
        ListOfTutorials->raise();
        TitleLabel->raise();
        PresenterLabel->raise();
        DurationLabel->raise();
        MinutesLabel->raise();
        SecondsLabel->raise();
        LinkLabel->raise();
        TitlelineEdit->raise();
        PresenterlineEdit->raise();
        MinuteslineEdit->raise();
        SecondslineEdit->raise();
        LikeslineEdit->raise();
        LinklineEdit->raise();
        AddButton->raise();
        DeleteButton->raise();
        UpdateButton->raise();
        LikesLabel->raise();
        ListButton->raise();
        menubar = new QMenuBar(AdministratorMode);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        AdministratorMode->setMenuBar(menubar);
        statusbar = new QStatusBar(AdministratorMode);
        statusbar->setObjectName("statusbar");
        AdministratorMode->setStatusBar(statusbar);

        retranslateUi(AdministratorMode);

        QMetaObject::connectSlotsByName(AdministratorMode);
    } // setupUi

    void retranslateUi(QMainWindow *AdministratorMode)
    {
        AdministratorMode->setWindowTitle(QCoreApplication::translate("AdministratorMode", "MainWindow", nullptr));
        TitleLabel->setText(QCoreApplication::translate("AdministratorMode", "Title", nullptr));
        PresenterLabel->setText(QCoreApplication::translate("AdministratorMode", "Presenter", nullptr));
        DurationLabel->setText(QCoreApplication::translate("AdministratorMode", "Duration", nullptr));
        MinutesLabel->setText(QCoreApplication::translate("AdministratorMode", "Minutes", nullptr));
        SecondsLabel->setText(QCoreApplication::translate("AdministratorMode", "Seconds", nullptr));
        LikesLabel->setText(QCoreApplication::translate("AdministratorMode", "Likes", nullptr));
        LinkLabel->setText(QCoreApplication::translate("AdministratorMode", "Link", nullptr));
        AddButton->setText(QCoreApplication::translate("AdministratorMode", "Add a tutorial", nullptr));
        DeleteButton->setText(QCoreApplication::translate("AdministratorMode", "Delete a tutorial", nullptr));
        UpdateButton->setText(QCoreApplication::translate("AdministratorMode", "Update a tutorial", nullptr));
        ListButton->setText(QCoreApplication::translate("AdministratorMode", "List All Tutorials", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorMode: public Ui_AdministratorMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADMINISTRATORWINDOWHBAEAF_H
