#include "userRepo.h"

userRepo::userRepo(std::vector<Tutorial>* watch_list, std::vector<Tutorial>* tutorials_same_presenter, std::string& filename) {
    this->watch_list = watch_list;
    this->tutorials_same_presenter = tutorials_same_presenter;
    this->filename = filename;
}

userRepo::userRepo() = default;

userRepo::~userRepo() {
    delete this->watch_list;
    delete this->tutorials_same_presenter;
}

std::vector<Tutorial> *userRepo::getAll_watch_list() {
    return this->watch_list;
}

std::vector<Tutorial> *userRepo::getAll_same_presenter() {
    return this->tutorials_same_presenter;
}
