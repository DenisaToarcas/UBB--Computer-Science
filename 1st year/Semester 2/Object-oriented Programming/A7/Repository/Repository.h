#pragma once
#include "Tutorial/Tutorial.h"
#include <vector>
#include <fstream>
#include "RepositoryExceptions.h"

class Repository
{
private:
    std::vector<Tutorial>* list_of_tutorials;
public:
    void loadTutorialsFromFile(std::string& fileName);
    void writeTutorialsToFile(std::string& fileName);
    //constructor
    explicit Repository(std::vector<Tutorial>* tutorials);
    //destructor
    ~Repository();
    unsigned long long getSizeRepo() const;
    Tutorial getTutorialRepo(long long index);
    void addTutorial(const Tutorial& tutorial);
    void deleteTutorial(long long index);
    void updateTutorial(long long index, Tutorial& tutorial);
    long long findTutorial(std::basic_string<char> title);
    Tutorial* getTutorials();
    void increase_likes(long long index);
};
