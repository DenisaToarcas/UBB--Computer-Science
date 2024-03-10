#include "UserModeGUI.h"

User::User(Service &service, QWidget *parent): QDialog(parent), service{service}{
    userWindow.setupUi(this);
}

void User::SeeWatchList() {
    this->userWindow.WatchListWidget->clear();

    auto WatchList = this->service.getAll_watch_list();

    for (auto& tutorial: *WatchList)
    {
        this->userWindow.WatchListWidget->addItem(QString::fromStdString(tutorial.toString()));
    }

    this->userWindow.TitlelineEdit->clear();
    this->userWindow.PresenterlineEdit->clear();
}

void User::DeleteTutorial() {
    this->userWindow.WatchListWidget->clear();

    std::string title = this->userWindow.TitlelineEdit->text().toStdString();
    try {
        this->service.deleteTutorialWatchListService(title);
    }
    catch(ServiceExceptions& e)
    {
        QMessageBox::critical(nullptr, "Exception", e.what());
    }
    this->SeeWatchList();

    int last_element = this->service.getSizeWatchList() - 1;
    this->userWindow.WatchListWidget->setCurrentRow(last_element);
    this->userWindow.TitlelineEdit->clear();
    this->userWindow.PresenterlineEdit->clear();
}

void User::SamePresenter() {
    this->userWindow.WatchListWidget->clear();

    bool found = false;
    std::string presenter = this->userWindow.PresenterlineEdit->text().toStdString();

    auto same_presenter = this->service.getAllTutorials();

    for (auto& tutorial: *same_presenter)
    if (tutorial.getPresenter() == presenter or presenter == "all")
        {   found = true;
            std::string t_title = tutorial.getTitle();
            std::string  t_presenter = tutorial.getPresenter();
            Duration t_duration = tutorial.getDuration();
            std::string t_link = tutorial.getLink();

            this->userWindow.WatchListWidget->addItem(QString::fromStdString(tutorial.toString()));
            QUrl link_url = QUrl::fromUserInput(QString::fromStdString(t_link));
            QDesktopServices::openUrl(link_url);

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(nullptr, "Message", "Do you want to add this tutorial to the watch list?", QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes)
                this->service.addTutorialWatchListService(t_title, t_presenter, t_duration, tutorial.getLikes(), t_link);

            QMessageBox::StandardButton continue_or_not;
            continue_or_not = QMessageBox::question(nullptr, "Message", "Would you like to see the next tutorial?", QMessageBox::Yes | QMessageBox::No);
            if (continue_or_not == QMessageBox::No)
                break;
        }

    if (found == false)
    {
        QMessageBox::critical(nullptr, "Message", QString("There is no tutorial with given presenter!"));
    }

    this->userWindow.TitlelineEdit->clear();
    this->userWindow.PresenterlineEdit->clear();
}


