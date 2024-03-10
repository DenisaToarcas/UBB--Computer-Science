#include "Service.h"

void Service::addDepartment(std::shared_ptr<HospitalDepartments> newDepartment) {
    this->departments.push_back(newDepartment);
}

std::vector<std::shared_ptr<HospitalDepartments>> Service::getAllDepartments() {
    return this->departments;
}

std::vector<std::shared_ptr<HospitalDepartments>> Service::getAllEFFICIENTDepartments() {
    std::vector<std::shared_ptr<HospitalDepartments>> efficientDep;
    for (auto department: this->departments)
    {
        if (department->isEfficient())
            efficientDep.push_back(department);
    }
    return efficientDep;
}

void Service::writeToFile(std::string& filename) {
    if (filename.empty())
        throw "The filename is empty!";
    else
    {
        std::ofstream fout(filename);
        for (auto department: this->departments)
            fout << department->toString() << "\n";
    }
}

