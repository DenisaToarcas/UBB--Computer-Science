#include <string>
#include "Duration/Duration.h"
#include "Service/ServiceExceptions.h"

class Validator
{
public:
    Validator();
    ~Validator();
    void validateTutorial(std::string& title, std::string& presenter, Duration& duration, int likes, std::string& link);
};