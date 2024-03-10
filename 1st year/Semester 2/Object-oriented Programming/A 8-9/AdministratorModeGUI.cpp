#include "AdministratorModeGUI.h"
#include <string>

Administrator::Administrator(Service &service, QWidget *parent): QDialog(parent), service { service }{
    admin_window.setupUi(this);
}

void Administrator::AddTutorial() {
    this->admin_window.ListOfTutorials->clear();

    std::string title = this->admin_window.TitlelineEdit->text().toStdString();
    std::string presenter = this->admin_window.PresenterlineEdit->text().toStdString();
    int minutes = this->admin_window.MinuteslineEdit->text().toInt();
    int seconds = this->admin_window.SecondslineEdit->text().toInt();
    int likes = this->admin_window.LikeslineEdit->text().toInt();
    std::string link = this->admin_window.LinklineEdit->text().toStdString();
    Duration duration(minutes, seconds);
    try {
        this->service.addTutorialService(title, presenter, duration, likes, link);
    }
    catch(ServiceExceptions& e)
    {
        QMessageBox::critical(nullptr, "Exception", e.what());
    }
    this->ListAll();

    int last_element = this->service.getAllTutorials()->size() - 1;
    this->admin_window.ListOfTutorials->setCurrentRow(last_element);

    this->admin_window.TitlelineEdit->clear();
    this->admin_window.PresenterlineEdit->clear();
    this->admin_window.MinuteslineEdit->clear();
    this->admin_window.SecondslineEdit->clear();
    this->admin_window.LikeslineEdit->clear();
    this->admin_window.LinklineEdit->clear();
}

void Administrator::DeleteTutorial() {
    this->admin_window.ListOfTutorials->clear();

    std::string title = this->admin_window.TitlelineEdit->text().toStdString();
    try {
        this->service.deleteTutorialService(title);
    }
    catch(ServiceExceptions& e)
    {
        QMessageBox::critical(nullptr, "Exception", e.what());
    }
    this->ListAll();

    int last_element = this->service.getAllTutorials()->size() - 1;
    this->admin_window.ListOfTutorials->setCurrentRow(last_element);
    this->admin_window.TitlelineEdit->clear();
    this->admin_window.PresenterlineEdit->clear();
    this->admin_window.MinuteslineEdit->clear();
    this->admin_window.SecondslineEdit->clear();
    this->admin_window.LikeslineEdit->clear();
    this->admin_window.LinklineEdit->clear();
}

void Administrator::UpdateTutorial() {
    this->admin_window.ListOfTutorials->clear();

    std::string title = this->admin_window.TitlelineEdit->text().toStdString();
    std::string presenter = this->admin_window.PresenterlineEdit->text().toStdString();
    int minutes = this->admin_window.MinuteslineEdit->text().toInt();
    int seconds = this->admin_window.SecondslineEdit->text().toInt();
    int likes = this->admin_window.LikeslineEdit->text().toInt();
    std::string link = this->admin_window.LinklineEdit->text().toStdString();
    Duration duration(minutes, seconds);

    try {
        this->service.updateTutorialService(title, presenter, duration, likes, link);
    }
    catch(ServiceExceptions& e)
    {
        QMessageBox::critical(nullptr, "Exception", e.what());
    }
    this->ListAll();

    int last_element = this->service.getAllTutorials()->size() - 1;
    this->admin_window.ListOfTutorials->setCurrentRow(last_element);
    this->admin_window.TitlelineEdit->clear();
    this->admin_window.PresenterlineEdit->clear();
    this->admin_window.MinuteslineEdit->clear();
    this->admin_window.SecondslineEdit->clear();
    this->admin_window.LikeslineEdit->clear();
    this->admin_window.LinklineEdit->clear();
}

void Administrator::ListAll() {
    this->admin_window.ListOfTutorials->clear();

    auto allTutorials = this->service.getAllTutorials();

    for (auto& tutorial: *allTutorials)
    {
        this->admin_window.ListOfTutorials->addItem(QString::fromStdString(tutorial.toString()));
    }
}
