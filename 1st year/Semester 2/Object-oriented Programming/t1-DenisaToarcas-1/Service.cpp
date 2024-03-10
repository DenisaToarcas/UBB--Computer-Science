#include "Service.h"

#include <utility>

Service::Service(Repository *repository1) {
    this->repository = repository1;
}

Service::~Service() {
    delete this->repository;
}

int Service::addPlayer(std::string &name, std::string &nationality, std::string &team, int goals_scored) {
    if (nationality.length() != 3)
        throw "Nationality is invalid!";
    auto woman_to_add = Woman(name, nationality, team, goals_scored);
    return this->repository->addPlayer(woman_to_add);
}

Woman Service::showPLayer(std::string name_to_verify) {
    return this->repository->showPLayer(name_to_verify);
}

unsigned long long Service::getSizeService() {
    return this->repository->getSizeRepo();
}
