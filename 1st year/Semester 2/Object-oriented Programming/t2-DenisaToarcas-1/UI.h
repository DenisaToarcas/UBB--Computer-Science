#include "Service.h"
#include <iostream>

class UI
{
private:
    Service service;
public:
    UI(Service service);
    ~UI() = default;
    void menu();
};