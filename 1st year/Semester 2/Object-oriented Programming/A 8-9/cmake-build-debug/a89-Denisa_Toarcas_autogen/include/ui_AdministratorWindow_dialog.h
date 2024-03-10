/********************************************************************************
** Form generated from reading UI file 'AdministratorWindow_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORWINDOW_DIALOG_H
#define UI_ADMINISTRATORWINDOW_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *ListOfTutorials;
    QWidget *layoutWidget;
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
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *UpdateButton;
    QPushButton *ListButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(879, 611);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ListOfTutorials = new QListWidget(Dialog);
        ListOfTutorials->setObjectName("ListOfTutorials");
        ListOfTutorials->setGeometry(QRect(60, 40, 731, 233));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 279, 731, 232));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        TitleLabel = new QLabel(layoutWidget);
        TitleLabel->setObjectName("TitleLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, TitleLabel);

        TitlelineEdit = new QLineEdit(layoutWidget);
        TitlelineEdit->setObjectName("TitlelineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, TitlelineEdit);

        PresenterLabel = new QLabel(layoutWidget);
        PresenterLabel->setObjectName("PresenterLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, PresenterLabel);

        PresenterlineEdit = new QLineEdit(layoutWidget);
        PresenterlineEdit->setObjectName("PresenterlineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, PresenterlineEdit);

        DurationLabel = new QLabel(layoutWidget);
        DurationLabel->setObjectName("DurationLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, DurationLabel);

        MinutesLabel = new QLabel(layoutWidget);
        MinutesLabel->setObjectName("MinutesLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, MinutesLabel);

        MinuteslineEdit = new QLineEdit(layoutWidget);
        MinuteslineEdit->setObjectName("MinuteslineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, MinuteslineEdit);

        SecondsLabel = new QLabel(layoutWidget);
        SecondsLabel->setObjectName("SecondsLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, SecondsLabel);

        SecondslineEdit = new QLineEdit(layoutWidget);
        SecondslineEdit->setObjectName("SecondslineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, SecondslineEdit);

        LikesLabel = new QLabel(layoutWidget);
        LikesLabel->setObjectName("LikesLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, LikesLabel);

        LikeslineEdit = new QLineEdit(layoutWidget);
        LikeslineEdit->setObjectName("LikeslineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, LikeslineEdit);

        LinkLabel = new QLabel(layoutWidget);
        LinkLabel->setObjectName("LinkLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, LinkLabel);

        LinklineEdit = new QLineEdit(layoutWidget);
        LinklineEdit->setObjectName("LinklineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, LinklineEdit);

        layoutWidget_2 = new QWidget(Dialog);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(60, 517, 731, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        AddButton = new QPushButton(layoutWidget_2);
        AddButton->setObjectName("AddButton");

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(layoutWidget_2);
        DeleteButton->setObjectName("DeleteButton");

        horizontalLayout->addWidget(DeleteButton);

        UpdateButton = new QPushButton(layoutWidget_2);
        UpdateButton->setObjectName("UpdateButton");

        horizontalLayout->addWidget(UpdateButton);

        ListButton = new QPushButton(layoutWidget_2);
        ListButton->setObjectName("ListButton");

        horizontalLayout->addWidget(ListButton);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));
        QObject::connect(AddButton, SIGNAL(clicked()), Dialog, SLOT(AddTutorial()));
        QObject::connect(DeleteButton, SIGNAL(clicked()), Dialog, SLOT(DeleteTutorial()));
        QObject::connect(UpdateButton, SIGNAL(clicked()), Dialog, SLOT(UpdateTutorial()));
        QObject::connect(ListButton, SIGNAL(clicked()), Dialog, SLOT(ListAll()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        TitleLabel->setText(QCoreApplication::translate("Dialog", "Title", nullptr));
        PresenterLabel->setText(QCoreApplication::translate("Dialog", "Presenter", nullptr));
        DurationLabel->setText(QCoreApplication::translate("Dialog", "Duration", nullptr));
        MinutesLabel->setText(QCoreApplication::translate("Dialog", "Minutes", nullptr));
        SecondsLabel->setText(QCoreApplication::translate("Dialog", "Seconds", nullptr));
        LikesLabel->setText(QCoreApplication::translate("Dialog", "Likes", nullptr));
        LinkLabel->setText(QCoreApplication::translate("Dialog", "Link", nullptr));
        AddButton->setText(QCoreApplication::translate("Dialog", "Add a tutorial", nullptr));
        DeleteButton->setText(QCoreApplication::translate("Dialog", "Delete a tutorial", nullptr));
        UpdateButton->setText(QCoreApplication::translate("Dialog", "Update a tutorial", nullptr));
        ListButton->setText(QCoreApplication::translate("Dialog", "List All Tutorials", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORWINDOW_DIALOG_H
