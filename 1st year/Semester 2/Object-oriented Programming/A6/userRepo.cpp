#include "userRepo.h"

userRepo::userRepo(std::vector<Tutorial>* watch_list, std::vector<Tutorial>* tutorials_same_presenter) {
    this->watch_list = watch_list;
    this->tutorials_same_presenter = tutorials_same_presenter;
}

userRepo::~userRepo() {
    delete this->watch_list;
    delete this->tutorials_same_presenter;
}

unsigned long long userRepo::getSizeWatchList() const {
    return this->watch_list->size();
}

void userRepo::addTutorialWatchList(const Tutorial &tutorial) {
    this->watch_list->push_back(tutorial);
}

void userRepo::deleteTutorialWatchList(long long index) {
    this->watch_list->erase(watch_list->begin() + index);
}

long long userRepo::findTutorialWatchList(const std::string &title) {
    for (auto i=watch_list->begin(); i< this->watch_list->end(); i++){
        if (title == i->getTitle())
            return std::distance(watch_list->begin(), i);
    }
    return -1;
}

//std::vector<Tutorial>* userRepo::getTutorialsUSER() {
//    return this->watch_list->data();
//}

Tutorial userRepo::getTutorialWatchList(long long index) {
    return this->watch_list->at(index);
}

void userRepo::addTutorialPresenter(const Tutorial &tutorial) {
    this->tutorials_same_presenter->push_back(tutorial);
}

//std::vector<Tutorial>* userRepo::getTutorialsPresenter() {
//    return this->tutorials_same_presenter->data();
//}

unsigned long long userRepo::getSizePresenter() {
    return this->tutorials_same_presenter->size();
}

void userRepo::deleteTutorialPresenter(long long index) {
    this->tutorials_same_presenter->erase(tutorials_same_presenter->begin() + index);
}

Tutorial userRepo::getTutorialPresenter(long long index) {
    return this->tutorials_same_presenter->at(index);
}
