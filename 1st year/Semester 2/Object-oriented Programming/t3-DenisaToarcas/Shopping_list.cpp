#include "Shopping_list.h"

ShoppingList::ShoppingList(std::string &category, std::string &name, std::string& quantity) {
    this->category = category;
    this->name = name;
    this->quantity = quantity;
}

std::string ShoppingList::getCategory() const {
    return this->category;
}

std::string ShoppingList::getName() const {
    return this->name;
}

std::string ShoppingList::getQuantity() const {
    return this->quantity;
}

std::string ShoppingList::toString() {
    return this->category + " " + this->name + " " + this->quantity;
}
