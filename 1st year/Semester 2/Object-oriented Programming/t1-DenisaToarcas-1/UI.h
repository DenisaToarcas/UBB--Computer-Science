#pragma once
#include "Service.h"

class UI
{
private:
    Service* service;
public:
    explicit UI(Service* service);
    ~UI();
    void menu();
};