#pragma once
#include <string>

class Woman
{
private:
    std::string name;
    std::string nationality;
    std::string team;
    int goals_scored;

public:
    Woman();
    Woman(std::string &name, std::string &nationality, std::string &team, int goals_scored);
    Woman(const Woman& WomanToCopy);
    ~Woman();
    std::string getName() const;
    std::string getNationality() const;
    std::string getTeam() const;
    int getGoals() const;
    std::string to_string();
};