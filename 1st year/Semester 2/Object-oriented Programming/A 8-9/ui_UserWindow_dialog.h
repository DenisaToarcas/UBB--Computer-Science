/********************************************************************************
** Form generated from reading UI file 'UserWindow_dialogOfgLFa.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef USERWINDOW_DIALOGOFGLFA_H
#define USERWINDOW_DIALOGOFGLFA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *WatchListWidget;
    QFormLayout *formLayout;
    QLabel *Titlelabel;
    QLineEdit *TitlelineEdit;
    QLabel *Presenterlabel;
    QLineEdit *PresenterlineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *SeeWatchListButton;
    QPushButton *DeleteTutorialButton;
    QPushButton *SamePresenterButton;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName("UserDialog");
        UserDialog->resize(639, 503);
        verticalLayout = new QVBoxLayout(UserDialog);
        verticalLayout->setObjectName("verticalLayout");
        WatchListWidget = new QListWidget(UserDialog);
        WatchListWidget->setObjectName("WatchListWidget");

        verticalLayout->addWidget(WatchListWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        Titlelabel = new QLabel(UserDialog);
        Titlelabel->setObjectName("Titlelabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, Titlelabel);

        TitlelineEdit = new QLineEdit(UserDialog);
        TitlelineEdit->setObjectName("TitlelineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, TitlelineEdit);

        Presenterlabel = new QLabel(UserDialog);
        Presenterlabel->setObjectName("Presenterlabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, Presenterlabel);

        PresenterlineEdit = new QLineEdit(UserDialog);
        PresenterlineEdit->setObjectName("PresenterlineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, PresenterlineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        SeeWatchListButton = new QPushButton(UserDialog);
        SeeWatchListButton->setObjectName("SeeWatchListButton");

        horizontalLayout->addWidget(SeeWatchListButton);

        DeleteTutorialButton = new QPushButton(UserDialog);
        DeleteTutorialButton->setObjectName("DeleteTutorialButton");

        horizontalLayout->addWidget(DeleteTutorialButton);

        SamePresenterButton = new QPushButton(UserDialog);
        SamePresenterButton->setObjectName("SamePresenterButton");

        horizontalLayout->addWidget(SamePresenterButton);


        verticalLayout->addLayout(horizontalLayout);

        WatchListWidget->raise();
        Titlelabel->raise();
        Presenterlabel->raise();
        TitlelineEdit->raise();
        PresenterlineEdit->raise();
        SamePresenterButton->raise();
        SeeWatchListButton->raise();
        DeleteTutorialButton->raise();

        retranslateUi(UserDialog);
        QObject::connect(SeeWatchListButton, SIGNAL(clicked()), UserDialog, SLOT(SeeWatchList()));
        QObject::connect(DeleteTutorialButton, SIGNAL(clicked()), UserDialog, SLOT(DeleteTutorial()));
        QObject::connect(SamePresenterButton, SIGNAL(clicked()), UserDialog, SLOT(SamePresenter()));

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QCoreApplication::translate("UserDialog", "Dialog", nullptr));
        Titlelabel->setText(QCoreApplication::translate("UserDialog", "Title", nullptr));
        Presenterlabel->setText(QCoreApplication::translate("UserDialog", "Presenter", nullptr));
        SeeWatchListButton->setText(QCoreApplication::translate("UserDialog", "See Watch List", nullptr));
        DeleteTutorialButton->setText(QCoreApplication::translate("UserDialog", "Delete tutorial from watch list", nullptr));
        SamePresenterButton->setText(QCoreApplication::translate("UserDialog", "Tutorials same presenter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // USERWINDOW_DIALOGOFGLFA_H
