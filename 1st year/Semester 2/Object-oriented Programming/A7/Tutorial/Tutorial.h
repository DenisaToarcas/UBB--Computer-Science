#pragma once
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <istream>
#include <ostream>
#include "Duration/Duration.h"

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

    friend std::istream& operator>>(std::istream& inputStream, Tutorial& tutorial);
    friend std::ostream& operator<<(std::ostream& outputStream, const Tutorial& tutorial);
    //we declared them as friend functions to be able to overwrite them
};