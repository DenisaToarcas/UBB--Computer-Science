#pragma once
#include "Repository.h"
#include "userRepo.h"

class Service{
private:
    Repository* repository;
    userRepo* userRepository;
public:
    //constructor
    explicit Service(Repository* repository, userRepo* userRepository);

    //destructor
    ~Service();

    //returns the size of the repository
    unsigned long long getSizeService() const;

    //returns a tutorial at a specified index
    //throws an exception if the index is out of range
    Tutorial getTutorialService(int index);

    //returns true if the tutorial was added successfully
    //returns false if the tutorial to be added is already part of the list
    bool addTutorialService(const std::string& title, const std::string& presenter, const Duration& duration, int likes, const std::string& link);

    //returns true if the tutorial was deleted
    //returns false if the tutorial to be deleted is not part of the list
    bool deleteTutorialService(const std::string& title);

    //returns true if the tutorial was updated
    //returns false otherwise
    bool updateTutorialService(const std::string &title, const std::string &new_presenter, const Duration &new_duration, int likes,
                               const std::string &link);

    //returns the index of the tutorial with the specified title
    //returns -1 otherwise
    long long findTutorial(std::string& title);

    //std::vector<Tutorial>* getTutorials();

    bool addTutorialWatchListService(std::string& title, std::string& presenter, Duration& duration, int likes, std::string& link);

    bool deleteTutorialWatchListService(std::string& title);

    void Tutorials_with_presenter(std::string& presenter);

    unsigned long long getSizeWatchList() const;

    unsigned long long getSizePresenter() const;

    Tutorial getTutorialWatchList(int index);

    Tutorial getTutorialPresenter(int index);

    void increase_likes_service(std::string &title);
};