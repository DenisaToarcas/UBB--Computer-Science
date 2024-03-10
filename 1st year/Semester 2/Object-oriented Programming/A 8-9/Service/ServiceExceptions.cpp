#include "ServiceExceptions.h"

ServiceExceptions::ServiceExceptions(std::string &_message) {
    this->message = _message;
}

const char *ServiceExceptions::what() const noexcept {
    return this->message.c_str();
}

ServiceExceptions::~ServiceExceptions() = default;
