#pragma once
#include "Domain.h"
#include <vector>

class Repository
{
private:
    std::vector<Woman>* women;
public:
    explicit Repository(std::vector<Woman>* women);
    ~Repository();
    int addPlayer(const Woman& woman);
    Woman showPLayer(std::string name);
    unsigned long long getSizeRepo();
    long long findWoman(std::string name);
};