
#include "Service.h"

void Service::read_from_file() {
    std::string filename = "list.txt";
    std::ifstream readFile(filename);

    std::string category;
    std::string name;
    std::string quantity;

    while(getline(readFile, category))
    {
        getline(readFile, name);
        getline(readFile, quantity);
        ShoppingList shopping(category, name, quantity);
        this->shopping_list.push_back(shopping);
    }
    readFile.close();
}

std::vector<ShoppingList> Service::getAll() {
    this->sort_list();
    return this->shopping_list;
}

void Service::sort_list() {
    std::sort(this->shopping_list.begin(), this->shopping_list.end(), [](const ShoppingList& a, const ShoppingList& b) {
        if (a.getName() < b.getName())
            return a.getCategory() < b.getCategory();
        else
        {
            return a.getName() < b.getName();
        }
    });
}

std::vector<ShoppingList> Service::getAll_category(std::string &category_given) {
    std::vector<ShoppingList> list_given_category;

    for (auto& list: this->shopping_list)
        if (list.getCategory() == category_given)
            list_given_category.push_back(list);

    return list_given_category;

}

Service::Service(const Service &serv) {
    this->shopping_list = serv.shopping_list;
}
