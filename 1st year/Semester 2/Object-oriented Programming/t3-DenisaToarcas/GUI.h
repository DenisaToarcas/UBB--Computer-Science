#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_test3.h"
#include "Service.h"

class GUI: public QMainWindow
{
    Q_OBJECT

public:
    explicit GUI(Service& service, QWidget *parent = Q_NULLPTR);

private:
    Ui::test3 ui;
    Service& service;

    void populateWidget();

public slots:
    void ShowCategory();
};