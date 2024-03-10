#include <vector>
#include "Tutorial.h"
#pragma once

class userRepo{
private:
    std::vector<Tutorial>* watch_list;
    std::vector<Tutorial>* tutorials_same_presenter;
public:
    //constructor
    explicit userRepo(std::vector<Tutorial>*, std::vector<Tutorial>*);
    //destructor
    ~userRepo();
    unsigned long long getSizeWatchList() const;
    void addTutorialWatchList(const Tutorial& tutorial);
    void deleteTutorialWatchList(long long index);
    long long findTutorialWatchList(const std::string& title);
    // getTutorialsUSER();
    Tutorial getTutorialWatchList(long long index);

    void addTutorialPresenter(const Tutorial& tutorial);
    //std::vector<Tutorial>* getTutorialsPresenter();
    unsigned long long getSizePresenter();
    void deleteTutorialPresenter(long long index);
    Tutorial getTutorialPresenter(long long index);
};