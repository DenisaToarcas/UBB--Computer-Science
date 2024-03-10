/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
    QLabel *HospitalName;
    QLineEdit *HospitalLine;
    QLabel *Doctors;
    QLineEdit *DoctorsLine;
    QLabel *Patients;
    QLineEdit *PatientsLine;
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
        HospitalName = new QLabel(centralwidget);
        HospitalName->setObjectName("HospitalName");

        formLayout->setWidget(0, QFormLayout::LabelRole, HospitalName);

        HospitalLine = new QLineEdit(centralwidget);
        HospitalLine->setObjectName("HospitalLine");

        formLayout->setWidget(0, QFormLayout::FieldRole, HospitalLine);

        Doctors = new QLabel(centralwidget);
        Doctors->setObjectName("Doctors");

        formLayout->setWidget(1, QFormLayout::LabelRole, Doctors);

        DoctorsLine = new QLineEdit(centralwidget);
        DoctorsLine->setObjectName("DoctorsLine");

        formLayout->setWidget(1, QFormLayout::FieldRole, DoctorsLine);

        Patients = new QLabel(centralwidget);
        Patients->setObjectName("Patients");

        formLayout->setWidget(2, QFormLayout::LabelRole, Patients);

        PatientsLine = new QLineEdit(centralwidget);
        PatientsLine->setObjectName("PatientsLine");

        formLayout->setWidget(2, QFormLayout::FieldRole, PatientsLine);


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
        QObject::connect(AddButton, SIGNAL(clicked()), MainWindow, SLOT(AddHospital()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        HospitalName->setText(QCoreApplication::translate("MainWindow", "Hospital Name", nullptr));
        Doctors->setText(QCoreApplication::translate("MainWindow", "No of doctors", nullptr));
        Patients->setText(QCoreApplication::translate("MainWindow", "No of patients", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "Add Button", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "Delete Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
