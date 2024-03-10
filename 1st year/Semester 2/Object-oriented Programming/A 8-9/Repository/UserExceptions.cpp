#include "UserExceptions.h"

UserException::UserException(std::string &_message) {
    this->message = _message;
}

const char *UserException::what() const noexcept {
    return this->message.c_str();
}

UserException::~UserException() = default;
