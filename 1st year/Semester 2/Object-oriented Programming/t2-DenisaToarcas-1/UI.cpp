#include "UI.h"

void UI::menu() {
    while(1) {
        try {
            std::cout << "Choose between:" << std::endl;
            std::cout << "1. Add a new department" << std::endl;
            std::cout << "2. Get all departments" << std::endl;
            std::cout << "3. Get all EFFICIENT departments" << std::endl;
            std::cout << "4. Write to file" << std::endl;

            std::string option;
            getline(std::cin, option);

            if (option == "1") {
                std::cout<< "Hospital name: "<<std::endl;
                std::string hospitalName;
                getline(std::cin, hospitalName);

                std::cout<< "Number of Doctors: "<<std::endl;
                std::string noDoctors;
                getline(std::cin, noDoctors);

                int numberOfDoctors;
                numberOfDoctors = std::stoi(noDoctors);

                std::cout<<" What are we adding? \n 1.Surgery \n 2.NeonatalUnit"<<std::endl;
                std::string department;
                getline(std::cin, department);

                if (department == "1")
                {
                    std::cout<<" Number of patients: "<<std::endl;
                    std::string noPatients;
                    getline(std::cin, noPatients);

                    int numberOfPatients;
                    numberOfPatients = std::stoi(noPatients);

                    std::shared_ptr<Surgery> department_to_add;
                    department_to_add = std::make_shared<Surgery>(hospitalName, numberOfDoctors, numberOfPatients);
                    this->service.addDepartment(department_to_add);
                }
                else
                {
                    if (department == "2")
                    {
                        std::cout<<" Average Grade: "<<std::endl;

                        double AverageGrade;
                        std::cin >> AverageGrade;
                        std::cin.clear();
                        std::cin.ignore();

                        std::shared_ptr<NeonatalUnit> department_to_add;
                        department_to_add = std::make_shared<NeonatalUnit>(hospitalName, numberOfDoctors, AverageGrade);
                        this->service.addDepartment(department_to_add);
                    }
                    else
                        std::cout << "Invalid option!" <<std::endl;
                }
            }
            else
            {
                if (option == "2")
                {
                    std::vector<std::shared_ptr<HospitalDepartments>> allDepartments;
                    allDepartments = this->service.getAllDepartments();
                    for (auto dep: allDepartments)
                        std::cout<< dep->toString() <<std::endl;
                }
                else
                {
                    if (option == "3")
                    {
                        std::vector<std::shared_ptr<HospitalDepartments>> allDepartments;
                        allDepartments = this->service.getAllEFFICIENTDepartments();
                        for (auto dep: allDepartments)
                            std::cout<< dep->toString() <<std::endl;
                    }
                    else
                    {
                        if (option == "4")
                        {
                            std::string filename;
                            std::cout <<" Filename: "<<std::endl;
                            getline(std::cin, filename);
                            this->service.writeToFile(filename);
                        }
                        else
                        {std::cout <<"Invalid input" <<std::endl;
                            break;
                        }
                    }
                }
            }
        }
        catch (const char& msg)
        {
            std::cout<< msg << std::endl;
        }
    }
}

UI::UI(Service service) {
    this->service = service;
}
