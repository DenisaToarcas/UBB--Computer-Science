#pragma once
#include <QtWidgets/QMainWindow>
#include "Service/Service.h"
#include "ui_UserWindow_dialog.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

class User: public QDialog{

Q_OBJECT
public:
    explicit User(Service& service, QWidget *parent = Q_NULLPTR);
    ~User() override = default;

private:
    Ui::UserDialog userWindow;
    Service& service;

public slots:
    void SeeWatchList();
    void DeleteTutorial();
    void SamePresenter();
};