#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "Domain.h"

class Service
{
private:
    std::vector<std::shared_ptr<HospitalDepartments>> departments;
public:
    Service() = default;
    ~Service() = default;
    void addDepartment(std::shared_ptr<HospitalDepartments> newDepartment);
    std::vector<std::shared_ptr<HospitalDepartments>> getAllDepartments();
    std::vector<std::shared_ptr<HospitalDepartments>> getAllEFFICIENTDepartments();
    void writeToFile(std::string& filename);
};