#include "DynamicVector.h"
#include "Tutorial.h"
#pragma once

class userRepo{
private:
    DynamicVector<Tutorial>* watch_list;
    DynamicVector<Tutorial>* tutorials_same_presenter;
public:
    //constructor
    explicit userRepo(DynamicVector<Tutorial>*, DynamicVector<Tutorial>*);
    //destructor
    ~userRepo();
    int getSizeWatchList() const;
    void addTutorialWatchList(const TElem& tutorial);
    void deleteTutorialWatchList(int index);
    int findTutorialWatchList(std::string& title);
    TElem* getTutorialsUSER();
    TElem getTutorialWatchList(int index);

    void addTutorialPresenter(const TElem& tutorial);
    TElem* getTutorialsPresenter();
    int getSizePresenter();
    void deleteTutorialPresenter(int index);
    TElem getTutorialPresenter(int index);
};