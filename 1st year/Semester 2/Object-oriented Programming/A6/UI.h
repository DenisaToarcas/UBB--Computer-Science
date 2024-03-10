#pragma once
#include "Service.h"

class UI{
private:
    Service* service;
public:
    explicit UI(Service* service);
    ~UI();
    static void menu();
    static void administratorMenu();
    static void userMenu();
    void administratorMode();
    void userMode();
    void start_up();
    void addTutorialUI();
    void deleteTutorialUI();
    void updateTutorialUI();
    void listTutorialsUI();
    static bool validateString(std::string whatever);
    void tutorials_with_given_presenter();
    void delete_from_watch_list();
    void see_watch_list();

};