#include "Tutorial.h"

Tutorial::Tutorial() {
    this->title = "";
    this->presenter = "";
    this->duration = Duration();
    this->likes = 0;
    this->link = "";
}

Tutorial::Tutorial(const std::string &title, const std::string &presenter, const Duration &duration, int likes,
                   const std::string &link) {
    this->title = title;
    this->presenter = presenter;
    this->duration = duration;
    this->likes = likes;
    this->link = link;
}

Tutorial::Tutorial(const Tutorial& TutorialToCopy) {
    this->title = TutorialToCopy.title;
    this->presenter = TutorialToCopy.presenter;
    this->duration = TutorialToCopy.duration;
    this->likes = TutorialToCopy.likes;
    this->link = TutorialToCopy.link;
}

Tutorial::~Tutorial() = default;

std::string Tutorial::getTitle() const {
    return this->title;
}

std::string Tutorial::getPresenter() const {
    return this->presenter;
}

Duration Tutorial::getDuration() const {
    return this->duration;
}

int Tutorial::getLikes() const {
    return this->likes;
}

std::string Tutorial::getLink() const {
    return this->link;
}

std::string Tutorial::toString() {
    //return "TITLE: " + this->title + ", Presenter: " + this->presenter + ", Duration: " + std::to_string(this->duration.getMinutes()) + ":" +
            //std::to_string(this->duration.getSeconds()) + " " + ", No. of likes: " + std::to_string(this->likes) + ", and Link: " + this->link;
            return this->title + "  " + this->presenter + " " + std::to_string(this->duration.getMinutes()) + ":" + std::to_string((this->duration.getSeconds())) + " " + std::to_string(this->likes) + " " + this->link;
}

void Tutorial::TitleSetter(std::string &title1) {
    this->title = title1;
}

void Tutorial::PresenterSetter(std::string &presenter1) {
    this->presenter = presenter1;
}

void Tutorial::DurationSetter(Duration & duration1) {
    this->duration = duration1;
}

void Tutorial::LikesSetter(int likes1) {
    this->likes = likes1;
}

void Tutorial::LinkSetter(std::string &link1) {
    this->link = link1;
}

std::vector<std::string> split_string(const std::string &string_given, char delimiter) {
    std::vector<std::string> split_string_;
    std::stringstream stringStream(string_given);
    std::string token;

    while (getline(stringStream, token, delimiter))
        split_string_.push_back(token);


    return split_string_;
}

std::istream &operator>>(std::istream &inputStream, Tutorial &tutorial) {
    std::string line;
    std::getline(inputStream, line);
    std::vector<std::string> info_of_tutorial;
    if (line.empty())
        return inputStream;
    else
    {
        std::vector<std::string> split_info;
        split_info = split_string(line, ',');

        tutorial.title = split_info[0];
        tutorial.presenter = split_info[1];
        tutorial.likes = std::stoi(split_info[3]);
        tutorial.link = split_info[4];

        std::vector<std::string> duration_string;
        duration_string = split_string(split_info[2], ':');
        int minutes = std::stoi(duration_string[0]);
        int seconds = std::stoi(duration_string[1]);

        tutorial.duration = Duration(minutes, seconds);
    }
    return inputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const Tutorial &tutorial) {
    outputStream << tutorial.title << "," << tutorial.presenter << "," << tutorial.duration.getMinutes() << ":" << tutorial.duration.getSeconds() << ","<< tutorial.likes << "," << tutorial.link;
    return outputStream;
}


