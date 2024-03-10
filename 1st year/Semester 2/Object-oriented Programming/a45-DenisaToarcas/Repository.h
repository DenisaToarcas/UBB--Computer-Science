#pragma once
#include "Tutorial.h"
#include "DynamicVector.h"

class Repository
{
private:
    DynamicVector<Tutorial>* list_of_tutorials;
public:
    //constructor
    explicit Repository(DynamicVector<Tutorial>* tutorials);
    //destructor
    ~Repository();
    int getSizeRepo() const;
    TElem getTutorialRepo(int index);
    void addTutorial(const TElem& tutorial);
    void deleteTutorial(int index);
    void updateTutorial(int index, TElem& tutorial);
    int findTutorial(std::string& title);
    TElem* getTutorials();
    void increase_likes(int index);
};