#include "GUI.h"
#include <iostream>

GUI::GUI(Service& service, QWidget *parent): QMainWindow(parent), service{ service } {
    ui.setupUi(this);

    this->populateWidget();
}

void GUI::populateWidget() {
    this->ui.ShoppingList1->clear();
    std::vector<ShoppingList> allList;
    allList = this->service.getAll();
    //std::cout<<allList.size()<<std::endl;

    for (auto& list: allList) {
        this->ui.ShoppingList1->addItem(QString::fromStdString(list.toString()));
        ShoppingList item1((std::string &) "Drinks", (std::string &) "Orange juice", (std::string &) "2");
        //this->ui.ShoppingList1->update();
        this->ui.ShoppingList1->addItem(QString::fromStdString(item1.toString()));
    }
}

void GUI::ShowCategory() {
    std::string category_given = this->ui.CategoryLabel->text().toStdString();

    std::vector<ShoppingList> allGivenCategory;
    allGivenCategory = this->service.getAll_category(category_given);

    this->ui.ShoppingList1->clear();
    sort(allGivenCategory.begin(), allGivenCategory.end(), [](ShoppingList a, ShoppingList b){
        return std::stoi(a.getQuantity()) < std::stoi(b.getQuantity());
    });

    for (auto& list: allGivenCategory)
        this->ui.ShoppingList1->addItem(QString::fromStdString(list.toString()));

    this->ui.CategoryLabel->clear();
}
