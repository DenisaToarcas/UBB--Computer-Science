#include "Repository.h"
#include <algorithm>

Repository::Repository(std::vector<Woman> *women) {
    this->women = women;
}

Repository::~Repository() {
    delete this->women;
}

int Repository::addPlayer(const Woman &woman) {
    if (findWoman(woman.getName()) == -1) {
        this->women->push_back(woman);
        return 1;
    }
    return 0;
}

Woman Repository::showPLayer(std::string name_to_find) {
    if (findWoman(name_to_find) != -1)
        return this->women->at(findWoman(name_to_find));
    else
        throw "This woman is not part of the list";
}

unsigned long long Repository::getSizeRepo() {
    return this->women->size();
}

long long Repository::findWoman(std::string name) {
    for (auto i=this->women->begin(); i< this->women->end(); i++)
        if (i->getName() == name)
            return std::distance(this->women->begin(), i);
    return -1;
}
