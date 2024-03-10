#include "Domain.h"

Woman::Woman() {
    this->name="";
    this->nationality="";
    this->team="";
    this->goals_scored=0;
}

Woman::Woman(std::string &name, std::string &nationality, std::string &team, int goals_scored) {
    this->name = name;
    this->nationality = nationality;
    this->team = team;
    this->goals_scored = goals_scored;
}

Woman::Woman(const Woman &WomanToCopy) {
    this->name = WomanToCopy.name;
    this->nationality = WomanToCopy.nationality;
    this->team = WomanToCopy.team;
    this->goals_scored = WomanToCopy.goals_scored;
}

Woman::~Woman() = default;

std::string Woman::getName() const{
    return this->name;
}

std::string Woman::getNationality() const{
    return this->nationality;
}

std::string Woman::getTeam() const{
    return this->team;
}

int Woman::getGoals() const{
    return this->goals_scored;
}

std::string Woman::to_string() {
    return this->name + " | " + this->nationality + " | " + this->team + " | " + std::to_string(this->goals_scored);
}
