#include <string>
class ServiceExceptions: public std::exception
{
private:
    std::string message;
public:
    explicit ServiceExceptions(std::string& _message);
    ~ServiceExceptions();
    const char *what() const noexcept override;
};
