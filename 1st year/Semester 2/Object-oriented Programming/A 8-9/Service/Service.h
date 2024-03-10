#pragma once
#include "Repository/Repository.h"
#include "Repository/userRepo.h"
#include "Repository/CSVhandler.h"
#include "Repository/HTMLhandler.h"
#include "Validator.h"
#include <cstring>
#include <memory>

class Service{
private:
    std::shared_ptr<Repository> repository;
    std::shared_ptr<userRepo> userRepository;
    std::string fileName;
    std::shared_ptr<Validator> validator;
public:
    //constructor
    Service(std::shared_ptr<Repository> repository, std::shared_ptr<userRepo> userRepository, std::string& fileName, const std::shared_ptr<Validator>& validator);
    //explicit Service(Repository* repository, userRepo* userRepository, std::string& fileName, Validator* validator, std::string& type_of_file, std::string& filenameUSER);
    //destructor
    ~Service();
    //returns the size of the repository
    unsigned long long getSizeService() const;

    //returns a tutorial at a specified index
    //throws an exception if the index is out of range
    Tutorial getTutorialService(int index);

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
    long long findTutorial(std::string& title);

    Tutorial* getTutorials();

    bool addTutorialWatchListService(std::string& title, std::string& presenter, Duration& duration, int likes, std::string& link);

    bool deleteTutorialWatchListService(std::string& title);

    void Tutorials_with_presenter(std::string& presenter);

    unsigned long long getSizeWatchList() const;

    unsigned long long getSizePresenter() const;

    Tutorial getTutorialWatchList(int index);

    Tutorial getTutorialPresenter(int index);

    void increase_likes_service(std::string &title);

    void loadTutorialsFromFile();

    void writeTutorialsToFile();

    //void verify_type_file();

    std::string& getFileName();

    std::vector<Tutorial>* getAllTutorials();
    std::vector<Tutorial>* getAll_watch_list();
    std::vector<Tutorial> *getAll_same_presenter();
};
