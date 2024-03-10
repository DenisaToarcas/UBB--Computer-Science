#pragma once
#include <string>

class ShoppingList
{
private:
    std::string category;
    std::string name;
    std::string quantity;

public:
    ShoppingList(std::string& category, std::string& name, std::string& quantity);
    ~ShoppingList() = default;

    [[nodiscard]] std::string getCategory() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getQuantity() const;

    std::string toString();
};