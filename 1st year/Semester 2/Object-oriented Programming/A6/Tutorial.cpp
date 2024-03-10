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
    return "TITLE: " + this->title + ", Presenter: " + this->presenter + ", Duration: " + std::to_string(this->duration.getMinutes()) + ":" +
            std::to_string(this->duration.getSeconds()) + " " + ", No. of likes: " + std::to_string(this->likes) + ", and Link: " + this->link;
}

//void Tutorial::TitleSetter(std::string &title1) {
//    this->title = title1;
//}
//
//void Tutorial::PresenterSetter(std::string &presenter1) {
//    this->presenter = presenter1;
//}
//
//void Tutorial::DurationSetter(Duration & duration1) {
//    this->duration = duration1;
//}

void Tutorial::LikesSetter(int likes1) {
    this->likes = likes1;
}

//void Tutorial::LinkSetter(std::string &link1) {
//    this->link = link1;
//}
