#include "RepositoryExceptions.h"

RepositoryException::RepositoryException(std::string &_message) {
    this->message = _message;
}

const char *RepositoryException::what() const noexcept {
    return this->message.c_str();
}

RepositoryException::~RepositoryException() = default;
