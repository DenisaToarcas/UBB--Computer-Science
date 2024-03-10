#pragma once
#include "ReportChatSession.h"
#include "ui_ChatWindow.h"
#include <QWidget>

class ChatWindow: public QWidget, public Observer
{
private:
    Ui::ReportsWidget ui;
    Driver* driver;
    ReportSession& reportSession;

public:
    ChatWindow(Driver* driver1, ReportSession& reportSession1, QWidget* parent = 0);
    ~ChatWindow();
    void update() override;

public slots:
    void SendMessage();
    void AddReport();
};