#pragma once
#include "Subject.h"
#include "Report.h"
#include "Driver.h"
#include <fstream>

class ReportSession: public Subject
{
private:
    std::vector<std::string> messages;
    std::vector<Driver*> drivers;
    std::vector<Report*> reports;
public:
    ReportSession() {}
    ~ReportSession() override{}

    std::vector<Driver*> getDrivers() {return this->drivers;}
    std::vector<Report*> getReports() {return this->reports;}

    void AddMessage(const std::string& message)
    {
        this->messages.push_back(message);
        this->notify();
    }

    std::vector<std::string> getMessages()
    {
        return this->messages;
    }

    void AddReport(Report* report)
    {
        this->reports.push_back(report);
        this->notify();
    }

    void readDriversFromFile(std::string& filename)
    {
        std::ifstream fin(filename);
        Driver driver;

        while (fin>>driver)
        {
            auto pair = std::pair<std::string, std::string>(driver.getLatitude(), driver.getLongitude());
            auto* driver_to_add = new Driver(driver.getName(), pair, driver.getScore());
            this->drivers.push_back(driver_to_add);
        }
    }

    void readReportsFromFile(std::string& filename)
    {
        std::ifstream fin(filename);
        Report report;

        while(fin>>report)
        {
            auto pair = std::pair<std::string, std::string>(report.getLatitude(), report.getLongitude());
            auto* report_to_add = new Report(report.getDescription(), report.getReporter(), pair, report.getStatus());
            this->reports.push_back(report_to_add);
        }
    }

    void WriteToFile()
    {
        std::string file_reports = "D:/PracticalOOP/Reports";
        std::ofstream fout(file_reports);

        for (auto report: this->reports)
        {
            fout << report;
        }
    }
};