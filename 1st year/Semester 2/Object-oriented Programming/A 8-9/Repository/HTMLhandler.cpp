#include "HTMLhandler.h"

HTMLRepository::HTMLRepository(std::vector<Tutorial> *watchList, std::vector<Tutorial> *tutorials_same_presenter,
                               const std::string &userFilename) {
    this->watch_list = watchList;
    this->tutorials_same_presenter = tutorials_same_presenter;
    this->filename = userFilename;
}

HTMLRepository::~HTMLRepository() {
    delete this->watch_list;
    delete this->tutorials_same_presenter;
}

unsigned long long HTMLRepository::getSizeWatchList() const {
    return this->watch_list->size();
}

void HTMLRepository::addTutorialWatchList(const Tutorial &tutorial) {
    this->watch_list->push_back(tutorial);
    this->writeWatchListToFile();
}

void HTMLRepository::deleteTutorialWatchList(long long int index) {
    this->watch_list->erase(this->watch_list->begin() + index);
    this->writeWatchListToFile();
}

long long HTMLRepository::findTutorialWatchList(std::string &title) {
    for (auto i=watch_list->begin(); i< this->watch_list->end(); i++){
        if (title == i->getTitle())
            return std::distance(watch_list->begin(), i);
    }
    return -1;
}

Tutorial HTMLRepository::getTutorialWatchList(long long int index) {
    return this->watch_list->at(index);
}

std::vector<Tutorial> *HTMLRepository::getTutorialsUSER() {
    return this->watch_list;
}

void HTMLRepository::addTutorialPresenter(const Tutorial &tutorial) {
    this->tutorials_same_presenter->push_back(tutorial);
}

unsigned long long HTMLRepository::getSizePresenter() {
    return this->tutorials_same_presenter->size();
}

void HTMLRepository::deleteTutorialPresenter(long long int index) {
    this->tutorials_same_presenter->erase(this->tutorials_same_presenter->begin() + index);
}

Tutorial HTMLRepository::getTutorialPresenter(long long int index) {
    return this->tutorials_same_presenter->at(index);
}

std::vector<Tutorial> *HTMLRepository::getTutorialsPresenter() {
    return this->tutorials_same_presenter;
}

void HTMLRepository::writeWatchListToFile() {
    if (this->filename.empty())
        throw UserException((std::string &) "The filename is invalid");
    else
    {
        std::ofstream fout(this->filename);
        for (const Tutorial& tutorial: *this->watch_list)
        {
            fout << "<!DOCTYPE html>\n<html><head><title>Watch List</title></head><body>\n";
            fout << "<table border=\"1\">\n";
            fout << "<tr><td>Title</td><td>Presenter</td><td>Duration</td><td>Likes</td><td>Link</td></tr>\n";
                fout << "<tr><td>" << tutorial.getTitle() << "</td>"
                     << "<td>" << tutorial.getPresenter() << "</td>"
                     << "<td>" << std::to_string(tutorial.getDuration().getMinutes()) <<":"<< std::to_string(tutorial.getDuration().getSeconds()) << "</td>"
                     << "<td>" << std::to_string(tutorial.getLikes()) << "</td>"
                     << "<td><a href=\"" << tutorial.getLink() << "\">"<< tutorial.getLink() <<"</a></td>" << '\n';
            fout << "</table></body></html>";
            fout.close();
        }
        fout.close();
    }
}

std::string &HTMLRepository::getFileName() {
    return this->filename;
}
