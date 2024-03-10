#include "Validator.h"

void Validator::validateTutorial(std::string &title, std::string &presenter, Duration &duration, int likes,
                                 std::string &link) {
    if (title.empty()) {
        std::string error;
        error = "The title is invalid!";
        throw ServiceExceptions(error);
    }
    else
    {
        if (presenter.empty())
        {
            std::string error;
            error = "The presenter is invalid!";
            throw ServiceExceptions(error);
        }
        else
        {
            if (likes < 0)
            {
                std::string error;
                error = "Invalid number of likes!";
                throw ServiceExceptions(error);
            }
            else
            {
                if (link.empty())
                {
                    std::string error;
                    error = "The link is invalid!";
                    throw ServiceExceptions(error);
                }
                else
                {
                    if (duration.getMinutes() < 0 or duration.getSeconds() < 0 or duration.getMinutes() > 60 or duration.getMinutes() > 60)
                    {
                        std::string error;
                        error = "The duration is invalid!";
                        throw ServiceExceptions(error);
                    }
                }
            }
        }
    }
}

Validator::Validator() {

}

Validator::~Validator() {

}
