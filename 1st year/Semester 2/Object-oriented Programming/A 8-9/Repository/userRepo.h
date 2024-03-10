#include <vector>
#include "Tutorial/Tutorial.h"
#include "UserExceptions.h"
#pragma once

class userRepo{
protected:
    std::vector<Tutorial>* watch_list;
    std::vector<Tutorial>* tutorials_same_presenter;
    std::string filename;
public:
    userRepo();
    //constructor
    explicit userRepo(std::vector<Tutorial>*, std::vector<Tutorial>*, std::string&);
    //destructor
    ~userRepo();
    //we transformed all the functions of the userRepository in pure virtual functions so we could actually override
    //them in the CSV and HTML repositories
    virtual unsigned long long getSizeWatchList() const = 0;
    virtual void addTutorialWatchList(const Tutorial& tutorial) = 0;
    virtual void deleteTutorialWatchList(long long index) = 0;
    virtual long long findTutorialWatchList(std::string& title) = 0;
    virtual std::vector<Tutorial>* getTutorialsUSER() = 0;
    virtual Tutorial getTutorialWatchList(long long index) = 0;

    virtual void addTutorialPresenter(const Tutorial& tutorial) = 0;
    virtual std::vector<Tutorial>* getTutorialsPresenter() = 0;
    virtual unsigned long long getSizePresenter() = 0;
    virtual void deleteTutorialPresenter(long long index) = 0;
    virtual Tutorial getTutorialPresenter(long long index) = 0;
    virtual void writeWatchListToFile() = 0;
    virtual std::string& getFileName() = 0;
    virtual std::vector<Tutorial> * getAll_watch_list();
    virtual  std::vector<Tutorial> * getAll_same_presenter();
};