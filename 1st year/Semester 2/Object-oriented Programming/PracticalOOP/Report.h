#pragma once
#include <string>
#include <vector>
#include <istream>
#include <sstream>
#include <ostream>

class Report
{
private:
    std::string description;
    std::string reporter;
    std::pair<std::string, std::string> exact_location;
    std::string validation_status;

public:
    Report() {}
    ~Report() {}
    Report(const std::string description, const std::string reporter, const std::pair<std::string, std::string> location, std::string status)
    {
        this->description = description;
        this->reporter = reporter;
        this->exact_location = location;
        this->validation_status = status;
    }

    std::string getDescription() const {return this->description;}
    std::string getReporter() const {return this->reporter;}
    std::string getLocation() const {return this->exact_location.first + " " + this->exact_location.second;}
    std::string getStatus() const {return this->validation_status;}
    std::string toString() {return this->description + "," + this->reporter + "," + getLocation() + "," + this->validation_status;}

    void setDescription(const std::string& description_) {this->description = description_;}
    void setReporter(const std::string& reporter_) {this->reporter= reporter_;}
    void setLocation(const std::pair<std::string, std::string>& location_) {this->exact_location = location_;}
    std::string getLatitude() const {return this->exact_location.first;}
    std::string getLongitude() const {return this->exact_location.second;}
    void setValidation(const std::string& status) {this->validation_status = status;}

    static std::vector<std::string> split_string(std::string string_given, char delimiter)
    {
        std::vector<std::string> split_string_;
        std::string token;
        std::stringstream stringstream(string_given);

        while(getline(stringstream,token,delimiter))
            split_string_.push_back(token);

        return split_string_;
    }

    friend std::istream& operator>>(std::istream& input, Report& report)
    {
        std::string line;
        getline(input, line);

        if (line.empty())
            return input;
        else
        {
            std::vector<std::string> info = split_string(line,',');
            report.description = info[0];
            report.reporter = info[1];
            report.validation_status = info[3];
            std::vector<std::string> locations = split_string(info[2], ' ');
            std::string latitude = locations[0];
            std::string longitude = locations[1];
            report.exact_location = std::pair<std::string, std::string>(latitude, longitude);
        }

        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Report& report)
    {
        output << report.description << "," << report.reporter << "," << report.getLocation() << "," << report.validation_status;
        return output;
    }
};