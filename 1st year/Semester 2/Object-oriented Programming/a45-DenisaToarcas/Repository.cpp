#include "Repository.h"

Repository::Repository(DynamicVector<Tutorial> *tutorials) {
    this->list_of_tutorials = tutorials;
}

Repository::~Repository() {
    delete this->list_of_tutorials;
}

int Repository::getSizeRepo() const {
    return this->list_of_tutorials->getSize();
}

TElem Repository::getTutorialRepo(int index) {
    return this->list_of_tutorials->getItem(index);
}

void Repository::addTutorial(const TElem &tutorial) {
    this->list_of_tutorials->addItem(tutorial);
}

void Repository::deleteTutorial(int index) {
    this->list_of_tutorials->removeItem(index);
}

void Repository::updateTutorial(int index, TElem &tutorial) {
    this->list_of_tutorials->updateItem(index, tutorial);
}

TElem *Repository::getTutorials() {
    return this->list_of_tutorials->getItems();
}

int Repository::findTutorial(std::string& title) {
    for (int i=0; i< this->list_of_tutorials->getSize(); i++){
        if (title == this->list_of_tutorials->getItem(i).getTitle())
            return i;
    }
    return -1;
}

void Repository::increase_likes(int index) {
    int likes = this->list_of_tutorials->getItem(index).getLikes();
    likes = likes + 1;
    this->list_of_tutorials->getItem(index).LikesSetter(likes);
}
