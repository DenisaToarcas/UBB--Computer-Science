#include "UI.h"
#include <iostream>

UI::UI(Service *service) {
    this->service = service;
}

UI::~UI() {
    delete this->service;
}

void UI::menu() {
    bool done = false;
    while (!done) {
        try {
            std::cout << "Menu:" << std::endl;
            std::cout<<"0. EXIT"<<std::endl;
            std::cout << "1. Add player" << std::endl;
            std::cout << "2. Show all players" << std::endl;
            std::string option;
            std::getline(std::cin, option);

            if (option == "0")
            {
                std::cout<<"BYE!";
                done = true;
            }
            else if (option == "1")
            {
                std::string name;
                std::cout<<"Give name:"<<std::endl;
                std::getline(std::cin, name);

                std::string nationality;
                std::cout<<"Give nationality:"<<std::endl;
                std::getline(std::cin, nationality);

                std::string team;
                std::cout<<"Give team:"<<std::endl;
                std::getline(std::cin, team);

                std::string goals_scored_string;
                std::cout<<"Give goals:"<<std::endl;
                std::getline(std::cin, goals_scored_string);

                int goals_scored = std::stoi(goals_scored_string);

                int added = this->service->addPlayer(name, nationality, team, goals_scored);
                if (added == 1)
                    std::cout<<"Player added successfully!"<<std::endl;
                else
                    throw "Player is already part of the list!";
            }
            else if (option == "2")
            {
                for (auto woman: this->service->)
            }
        }
        catch (const char* msg){
            std::cout<< msg <<std::endl;}
    }
}
