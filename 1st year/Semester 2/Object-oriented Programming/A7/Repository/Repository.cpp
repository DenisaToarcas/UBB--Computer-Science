#include "Repository.h"
#include <iostream>

Repository::Repository(std::vector<Tutorial>* tutorials) {
    this->list_of_tutorials = tutorials;
}

Repository::~Repository() {
    delete this->list_of_tutorials;
}

unsigned long long Repository::getSizeRepo() const {
    return this->list_of_tutorials->size();
}

Tutorial Repository::getTutorialRepo(long long index) {
    return this->list_of_tutorials->at(index);
}

void Repository::addTutorial(const Tutorial &tutorial) {
    this->list_of_tutorials->push_back(tutorial);
}

void Repository::deleteTutorial(long long index) {
    this->list_of_tutorials->erase(list_of_tutorials->begin() + index);
}

void Repository::updateTutorial(long long index, Tutorial &tutorial) {
    this->list_of_tutorials->erase(list_of_tutorials->begin() + index);
    this->list_of_tutorials->push_back(tutorial);
}

Tutorial *Repository::getTutorials() {
    return this->list_of_tutorials->data();
}

long long Repository::findTutorial(std::basic_string<char> title) {
    for (auto i=list_of_tutorials->begin(); i< this->list_of_tutorials->end(); i++){
        if (title == i->getTitle())
            return std::distance(list_of_tutorials->begin(), i);
    }
    return -1;
}

void Repository::increase_likes(long long index) {
    int likes = this->list_of_tutorials->at(index).getLikes();
    likes = likes + 1;
    this->list_of_tutorials->at(index).LikesSetter(likes);
}

void Repository::loadTutorialsFromFile(std::string& fileName) {
    if (fileName.empty()) {
        std::string error = "The name of the file is invalid!";
        throw RepositoryException(error);
    }
    else {
        Tutorial TutorialFromFile;
        std::ifstream fin(fileName);
        if (!fin.is_open()) {
            std::string error = "File couldn't be opened";
            throw RepositoryException(error);
        }
        else {
            while (fin >> TutorialFromFile)
            {
                if (this->findTutorial(TutorialFromFile.getTitle()) == -1)
                    this->list_of_tutorials->push_back(TutorialFromFile);
                else {
                    std::string error = "Tutorial already part of the list";
                    throw RepositoryException(error);
                }
            }
            fin.close();
        }
    }

}

void Repository::writeTutorialsToFile(std::string& fileName) {
    if (fileName.empty()) {
        std::string error = "The name of the file is invalid!";
        throw RepositoryException(error);
    }
    else
    {
        std::ofstream fout(fileName);
        for (const Tutorial& tutorial: *this->list_of_tutorials)
        {
            fout<< tutorial << "\n";
        }
        fout.close();
    }
}
