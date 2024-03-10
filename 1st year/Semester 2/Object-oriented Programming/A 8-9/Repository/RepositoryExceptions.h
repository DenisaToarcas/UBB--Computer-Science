#include <string>
#pragma once

class RepositoryException: public std::exception{
private:
    std::string message;
public:
    explicit RepositoryException(std::string& _message);
    ~RepositoryException();
    const char *what() const noexcept override;
};