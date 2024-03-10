#pragma once

#include <string>

class Message
{
private:
	std::string message;

public:
	Message() { message = ""; };
	Message(std::string message) : message(message) {};
	std::string getMessage() { return message; };
};