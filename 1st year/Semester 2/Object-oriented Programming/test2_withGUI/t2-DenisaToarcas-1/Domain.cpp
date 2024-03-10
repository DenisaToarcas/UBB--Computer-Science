#include "Domain.h"

Surgery::Surgery() {
    this->hospitalName = "";
    this->numberOfDoctors = 0;
    this->number_of_patients = 0;
}

Surgery::Surgery(std::string &hospitalName, int noDoctors, int noPatients) {
    this->hospitalName = hospitalName;
    this->numberOfDoctors = noDoctors;
    this->number_of_patients = noPatients;
}

Surgery::~Surgery() {

}

bool Surgery::isEfficient() {
    if (this->number_of_patients >= 2*this->numberOfDoctors)
        return true;
    else
        return false;
}

std::string Surgery::toString() {
    if (this->isEfficient())
        return this->hospitalName + ", " + std::to_string(this->numberOfDoctors) + ", " + std::to_string(this->number_of_patients) + " efficient";
    else
        return this->hospitalName + ", " + std::to_string(this->numberOfDoctors) + ", " + std::to_string(this->number_of_patients) + " non-efficient";
}

NeonatalUnit::NeonatalUnit() {
    this->hospitalName = "";
    this->numberOfDoctors = 0;
    this->averageGrade = 0;
}

NeonatalUnit::NeonatalUnit(std::string &hospitalName, int noDoctors, double averageGrade) {
    this->hospitalName = hospitalName;
    this->numberOfDoctors = noDoctors;
    this->averageGrade = averageGrade;
}

NeonatalUnit::~NeonatalUnit() {

}

bool NeonatalUnit::isEfficient() {
    if (this->averageGrade >= 8.5)
        return true;
    else
        return false;
}

std::string NeonatalUnit::toString() {
    if (this->isEfficient())
        return this->hospitalName + ", " + std::to_string(this->numberOfDoctors) + ", " + std::to_string(this->averageGrade) + " efficient";
    else
        return this->hospitalName + ", " + std::to_string(this->numberOfDoctors) + ", " + std::to_string(this->averageGrade) + " non-efficient";
}
