#pragma once

#include <string>

class User
{
private:
	std::string name;
	std::string uniqueUserName;

public:
	User() {name = ""; uniqueUserName = "";};
	User(std::string name, std::string uniqueUserName) : name(name), uniqueUserName(uniqueUserName) {};
	~User() {};
	std::string getName() { return name; };
	std::string getUniqueUserName() { return uniqueUserName; };
};