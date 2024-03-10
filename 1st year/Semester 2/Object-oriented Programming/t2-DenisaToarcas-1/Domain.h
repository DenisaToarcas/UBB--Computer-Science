#pragma once
#include <string>
#include <vector>

class HospitalDepartments
{
protected:
    std::string hospitalName;
    int numberOfDoctors;

public:
    HospitalDepartments() = default;
    ~HospitalDepartments() = default;
    virtual bool isEfficient() = 0;
    virtual std::string toString() = 0;
};

class Surgery: public HospitalDepartments
{
private:
    int number_of_patients;
public:
    Surgery();
    Surgery(std::string& hospitalName, int noDoctors, int noPatients);
    ~Surgery();
    bool isEfficient() override;
    std::string toString() override;
};

class NeonatalUnit: public HospitalDepartments
{
private:
    double averageGrade;
public:
    NeonatalUnit();
    NeonatalUnit(std::string& hospitalName, int noDoctors, double averageGrade);
    ~NeonatalUnit();
    bool isEfficient() override;
    std::string toString() override;
};