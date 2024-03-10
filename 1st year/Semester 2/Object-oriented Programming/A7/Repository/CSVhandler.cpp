#include "CSVhandler.h"
#include <iostream>
CSVRepository::CSVRepository(std::vector<Tutorial> *watchList, std::vector<Tutorial> *tutorials_same_presenter,
                             const std::string &userFilename) {
    this->watch_list = watchList;
    this->tutorials_same_presenter = tutorials_same_presenter;
    this->filename =userFilename;
}

CSVRepository::~CSVRepository() {
    delete this->watch_list;
    delete this->tutorials_same_presenter;
}

unsigned long long CSVRepository::getSizeWatchList() const {
    return this->watch_list->size();
}

void CSVRepository::addTutorialWatchList(const Tutorial &tutorial) {
    this->watch_list->push_back(tutorial);
    this->writeWatchListToFile();
}

void CSVRepository::deleteTutorialWatchList(long long int index) {
    this->watch_list->erase(watch_list->begin() + index);
    this->writeWatchListToFile();
}

long long CSVRepository::findTutorialWatchList(std::string &title) {
    for (auto i=watch_list->begin(); i< this->watch_list->end(); i++){
        if (title == i->getTitle())
            return std::distance(watch_list->begin(), i);
    }
    return -1;
}

Tutorial CSVRepository::getTutorialWatchList(long long int index) {
    return this->watch_list->at(index);
}

void CSVRepository::addTutorialPresenter(const Tutorial &tutorial) {
    this->tutorials_same_presenter->push_back(tutorial);
}

unsigned long long CSVRepository::getSizePresenter() {
    return this->tutorials_same_presenter->size();
}

void CSVRepository::deleteTutorialPresenter(long long int index) {
    this->tutorials_same_presenter->erase(tutorials_same_presenter->begin() + index);
}

Tutorial CSVRepository::getTutorialPresenter(long long int index) {
    return this->tutorials_same_presenter->at(index);
}

void CSVRepository::writeWatchListToFile() {
    if (this->filename.empty())
        throw UserException((std::string &) "The filename is invalid");
    else
    {
        std::ofstream fout(this->filename);
        for (const Tutorial& tutorial: *this->watch_list)
        {
            fout << tutorial << "\n";
        }
        fout.close();
    }
}

std::vector<Tutorial> *CSVRepository::getTutorialsUSER() {
    return this->watch_list;
}

std::vector<Tutorial> *CSVRepository::getTutorialsPresenter() {
    return this->tutorials_same_presenter;
}

std::string &CSVRepository::getFileName() {
    return this->filename;
}


