#include <string>
#pragma once

class UserException: public std::exception{
private:
    std::string message;
public:
    explicit UserException(std::string& _message);
    ~UserException();
    const char *what() const noexcept override;
};