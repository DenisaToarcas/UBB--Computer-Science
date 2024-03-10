#pragma once
#include <string>
#include <vector>
#include <istream>
#include <sstream>

class Driver
{
private:
    std::string name;
    std::pair<std::string, std::string> current_location;
    std::string score;

public:
    Driver() {}
    Driver(const std::string name, const std::pair<std::string, std::string> location, std::string score)
    {
        this->name = name;
        this->current_location = location;
        this->score = score;
    }
    ~Driver() {}
    std::string getName() const {return this->name;}
    std::string getLocation() const {return this->current_location.first + " " + this->current_location.second;}
    std::string getScore() const {return this->score;}
    std::string getLatitude() const {return this->current_location.first;}
    std::string getLongitude() const {return this->current_location.second;}
    std::string toString(){
        return this->name + "," + getLocation() + "," + this->score;
    }

    void setName(const std::string& name_) {this->name = name_;}
    void setLocation(const std::pair<std::string, std::string>& location_) {this->current_location=location_;}
    void setScore(const std::string& score_) {this->score = score_;}

    static std::vector<std::string> split_string(std::string string_given, char delimiter)
    {
        std::vector<std::string> split_string_;
        std::string token;
        std::stringstream stringstream(string_given);

        while(getline(stringstream,token,delimiter))
            split_string_.push_back(token);

        return split_string_;
    }

    friend std::istream& operator>>(std::istream& input, Driver& driver)
    {
        std::string line;
        getline(input, line);

        if (line.empty())
            return input;
        else
        {
            std::vector<std::string> info = split_string(line,',');
            driver.name = info[0];
            driver.score = info[2];
            std::vector<std::string> locations = split_string(info[1], ' ');
            std::string latitude = locations[0];
            std::string longitude = locations[1];
            driver.current_location = std::pair<std::string, std::string>(latitude, longitude);
        }

        return input;
    }
};