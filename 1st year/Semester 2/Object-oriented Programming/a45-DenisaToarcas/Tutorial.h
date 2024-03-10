#pragma once
#include <string>
#include "Duration.h"

class Tutorial{
private:
    std::string title;
    std::string presenter;
    Duration duration;
    int likes;
    std::string link;

public:
    Tutorial();
    Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, int likes, const std::string& link);
    Tutorial(const Tutorial&);
    ~Tutorial();

    std::string getTitle() const;
    std::string getPresenter() const;
    Duration getDuration() const;
    int getLikes() const;
    std::string getLink() const;

    std::string toString();
    void TitleSetter(std::string& title);
    void PresenterSetter(std::string& presenter);
    void DurationSetter(Duration& duration);
    void LikesSetter(int likes);
    void LinkSetter(std::string& link);
};