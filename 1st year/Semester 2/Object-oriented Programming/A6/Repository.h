#pragma once
#include "Tutorial.h"
#include <vector>

class Repository
{
private:
    std::vector<Tutorial>* list_of_tutorials;
public:
    //constructor
    explicit Repository(std::vector<Tutorial>* tutorials);
    //destructor
    ~Repository();
    unsigned long long getSizeRepo() const;
    Tutorial getTutorialRepo(long long index);
    void addTutorial(const Tutorial& tutorial);
    void deleteTutorial(long long index);
    void updateTutorial(long long index, Tutorial& tutorial);
    long int findTutorial(const std::string& title);
    //std::vector<Tutorial>* getTutorials();
    void increase_likes(long long index);
};