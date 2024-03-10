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
    int getSizeService() const;

    //returns a tutorial at a specified index
    //throws an exception if the index is out of range
    TElem getTutorialService(int index);

    //returns true if the tutorial was added successfully
    //returns false if the tutorial to be added is already part of the list
    bool addTutorialService(std::string& title, std::string& presenter, Duration& duration, int likes, std::string& link);

    //returns true if the tutorial was deleted
    //returns false if the tutorial to be deleted is not part of the list
    bool deleteTutorialService(std::string& title);

    //returns true if the tutorial was updated
    //returns false otherwise
    bool updateTutorialService(std::string& title, std::string& new_presenter, Duration& new_duration, int likes, std::string& link);

    //returns the index of the tutorial with the specified title
    //returns -1 otherwise
    int findTutorial(std::string& title);

    TElem* getTutorials();

    bool addTutorialWatchListService(std::string& title, std::string& presenter, Duration& duration, int likes, std::string& link);

    bool deleteTutorialWatchListService(std::string& title);

    void Tutorials_with_presenter(std::string& presenter);

    int getSizeWatchList() const;

    int getSizePresenter() const;

    TElem getTutorialWatchList(int index);

    TElem getTutorialPresenter(int index);

    void increase_likes_service(std::string &title);
};