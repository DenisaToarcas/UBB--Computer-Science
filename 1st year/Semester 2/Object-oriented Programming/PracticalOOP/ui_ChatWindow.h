/********************************************************************************
** Form generated from reading UI file 'ChatWindowZcZKOL.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHATWINDOWZCZKOL_H
#define CHATWINDOWZCZKOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *ReportListWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddButton;
    QLineEdit *DescriptionLineEdit;
    QLineEdit *LatitudeLineEdit;
    QLineEdit *LongitudeLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *SendButton;
    QLineEdit *MessageLIneEdit;

    void setupUi(QWidget *ReportsWidget)
    {
        if (ReportsWidget->objectName().isEmpty())
            ReportsWidget->setObjectName("ReportsWidget");
        ReportsWidget->resize(400, 329);
        verticalLayout = new QVBoxLayout(ReportsWidget);
        verticalLayout->setObjectName("verticalLayout");
        ReportListWidget = new QListWidget(ReportsWidget);
        ReportListWidget->setObjectName("ReportListWidget");

        verticalLayout->addWidget(ReportListWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        AddButton = new QPushButton(ReportsWidget);
        AddButton->setObjectName("AddButton");

        horizontalLayout_2->addWidget(AddButton);

        DescriptionLineEdit = new QLineEdit(ReportsWidget);
        DescriptionLineEdit->setObjectName("DescriptionLineEdit");

        horizontalLayout_2->addWidget(DescriptionLineEdit);

        LatitudeLineEdit = new QLineEdit(ReportsWidget);
        LatitudeLineEdit->setObjectName("LatitudeLineEdit");

        horizontalLayout_2->addWidget(LatitudeLineEdit);

        LongitudeLineEdit = new QLineEdit(ReportsWidget);
        LongitudeLineEdit->setObjectName("LongitudeLineEdit");

        horizontalLayout_2->addWidget(LongitudeLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        SendButton = new QPushButton(ReportsWidget);
        SendButton->setObjectName("SendButton");

        horizontalLayout->addWidget(SendButton);

        MessageLIneEdit = new QLineEdit(ReportsWidget);
        MessageLIneEdit->setObjectName("MessageLIneEdit");

        horizontalLayout->addWidget(MessageLIneEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ReportsWidget);
        QObject::connect(AddButton, SIGNAL(clicked()), ReportsWidget, SLOT(AddReport()));
        QObject::connect(SendButton, SIGNAL(clicked()), ReportsWidget, SLOT(SendMessage()));

        QMetaObject::connectSlotsByName(ReportsWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportsWidget)
    {
        ReportsWidget->setWindowTitle(QCoreApplication::translate("ReportsWidget", "Form", nullptr));
        AddButton->setText(QCoreApplication::translate("ReportsWidget", "Add", nullptr));
        SendButton->setText(QCoreApplication::translate("ReportsWidget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportsWidget: public Ui_ReportsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHATWINDOWZCZKOL_H
