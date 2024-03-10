#pragma once
#include "Observer.h"
#include <vector>
#include <algorithm>

class Subject
{
private:
    std::vector<Observer*> observers;
public:
    Subject() {}
    virtual ~Subject() {}
    void AddObserver(Observer* observer)
    {
        this->observers.push_back(observer);
    }
    void DeleteObserver(Observer* observer)
    {
        this->observers.erase(std::find(this->observers.begin(), this->observers.end(), observer));
    }
    void notify()
    {
        for (auto observer: observers)
            observer->update();
    }
};