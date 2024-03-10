#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include "Shopping_list.h"

class Service
{
private:
    std::vector<ShoppingList> shopping_list;

public:
    Service() =default;
    Service(const Service& serv);
    ~Service() = default;

    void read_from_file();
    std::vector<ShoppingList> getAll();
    void sort_list();
    std::vector<ShoppingList> getAll_category(std::string& category_given);
};