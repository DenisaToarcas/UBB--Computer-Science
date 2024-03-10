#include "ui_mainwindow.h"
#include "Service.h"
#include <QtWidgets/QMainWindow>

class Gui: public QMainWindow{

    Q_OBJECT

public:
    explicit Gui(Service& service, QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindow ui;
    Service& service;

    void populateList();
    int getSelectedIndexes() const;
public slots:
    void AddHospital();
};