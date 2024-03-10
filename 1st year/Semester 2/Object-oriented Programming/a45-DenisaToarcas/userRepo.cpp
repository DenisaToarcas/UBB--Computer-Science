#include "userRepo.h"

userRepo::userRepo(DynamicVector<Tutorial> *watch_list, DynamicVector<Tutorial>* tutorials_same_presenter) {
    this->watch_list = watch_list;
    this->tutorials_same_presenter = tutorials_same_presenter;
}

userRepo::~userRepo() {
    delete this->watch_list;
    delete this->tutorials_same_presenter;
}

int userRepo::getSizeWatchList() const {
    return this->watch_list->getSize();
}

void userRepo::addTutorialWatchList(const TElem &tutorial) {
    this->watch_list->addItem(tutorial);
}

void userRepo::deleteTutorialWatchList(int index) {
    this->watch_list->removeItem(index);
}

int userRepo::findTutorialWatchList(std::string &title) {
    for (int i=0; i<this->watch_list->getSize(); i++)
        if (title == this->watch_list->getItem(i).getTitle())
            return i;
    return -1;
}

TElem *userRepo::getTutorialsUSER() {
    return this->watch_list->getItems();
}

TElem userRepo::getTutorialWatchList(int index) {
    return this->watch_list->getItem(index);
}

void userRepo::addTutorialPresenter(const TElem &tutorial) {
    this->tutorials_same_presenter->addItem(tutorial);
}

TElem *userRepo::getTutorialsPresenter() {
    return this->tutorials_same_presenter->getItems();
}

int userRepo::getSizePresenter() {
    return this->tutorials_same_presenter->getSize();
}

void userRepo::deleteTutorialPresenter(int index) {
    this->tutorials_same_presenter->removeItem(index);
}

TElem userRepo::getTutorialPresenter(int index) {
    return this->tutorials_same_presenter->getItem(index);
}
