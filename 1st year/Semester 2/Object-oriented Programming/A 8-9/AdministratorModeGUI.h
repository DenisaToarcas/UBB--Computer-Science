#pragma once
#include <QtWidgets/QMainWindow>
#include "Service/Service.h"
#include "ui_AdministratorWindow_dialog.h"
#include <QMessageBox>
class Administrator: public QDialog{

    Q_OBJECT
public:
    explicit Administrator(Service& service, QWidget *parent = Q_NULLPTR);
    ~Administrator() override = default;

private:
    Ui::Dialog admin_window;
    Service& service;

public slots:
    void AddTutorial();
    void DeleteTutorial();
    void UpdateTutorial();
    void ListAll();
};