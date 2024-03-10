#include "ui_Tutorials.h"
#include <QtWidgets/QMainWindow>
#include <QDialog>
#include "Service/Service.h"
#pragma once
#include "AdministratorModeGUI.h"
#include "UserModeGUI.h"
#include <QMessageBox>


class Gui: public QMainWindow{

    Q_OBJECT

public:
    explicit Gui(Service& service, QWidget *parent = Q_NULLPTR);
    ~Gui() override;
private:
    Ui::MainWindow ui;
    Service& service;

public slots:
    void AdministratorMode();
    void UserMode();
};