#pragma once
#include "Repository.h"

class Service
{
private:
    Repository* repository;
public:
    explicit Service(Repository* repository1);
    ~Service();
    int addPlayer(std::string &name, std::string &nationality, std::string &team, int goals_scored);
    Woman showPLayer(std::string name);
    unsigned long long getSizeService();
};