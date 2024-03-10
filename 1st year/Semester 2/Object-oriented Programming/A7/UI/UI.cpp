#include "UI.h"
#include <iostream>
#include <windows.h>

UI::UI(Service *service) {
    this->service = service;
}

UI::~UI() = default;

void UI::menu() {
    std::cout<<std::endl;
    std::cout<<"MASTER C++"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"MENU:"<<std::endl;
    std::cout<<"0. Exit."<<std::endl;
    std::cout<<"1. Administrator mode."<<std::endl;
    std::cout<<"2. User mode."<<std::endl;
    std::cout<<"Choose an option: "<<std::endl;
}

void UI::administratorMenu() {
    std::cout<<std::endl;
    std::cout<<"ADMINISTRATOR MENU: "<<std::endl;
    std::cout<<"0. Exit"<<std::endl;
    std::cout<<"1. List all tutorials."<<std::endl;
    std::cout<<"2. Add a new tutorial."<<std::endl;
    std::cout<<"3. Delete a tutorial."<<std::endl;
    std::cout<<"4. Update a tutorial."<<std::endl;
    std::cout<<"Choose an option: "<<std::endl;
}

void UI::userMenu() {
    std::cout<<std::endl;
    std::cout<<"USER MENU:"<<std::endl;
    std::cout<<"0. Exit"<<std::endl;
    std::cout<<"1. See all tutorials having a specific presenter"<<std::endl;
    std::cout<<"2. Delete a tutorial from the watch list"<<std::endl;
    std::cout<<"3. See the watch list"<<std::endl;
    std::cout<<"Choose an option: "<<std::endl;
}

void UI::userMode() {
    std::cout << "~You entered the user mode~" << std::endl;
    bool done = false;
    while (!done)
        try {
            userMenu();
            std::string option;
            getline(std::cin, option);
            if (option == "0") {
                done = true;
                std::cout << "Exiting user mode..." << std::endl;
            } else if (option == "1")
                this->tutorials_with_given_presenter();
            else if (option == "2")
                this->delete_from_watch_list();
            else if (option == "3")
                this->see_watch_list();
        } catch (ServiceExceptions& error) {
            std::cout<<error.what()<<std::endl;
        }
        catch (RepositoryException& error) {
            std::cout << error.what() << std::endl;
        }catch (const std::exception &exc) {
            std::cerr << exc.what();
            std::cout << std::endl;
        }
}

void UI::administratorMode() {
    std::cout<<"~You entered the administrator mode~"<<std::endl;
    bool done = false;
    while (!done)
        try {
            administratorMenu();
            std::string option;
            getline(std::cin, option);
            if (option == "0") {
                done = true;
                std::cout << "Exiting admin mode..." << std::endl;
            } else if (option == "1")
                this->listTutorialsUI();
            else if (option == "2")
                this->addTutorialUI();
            else if (option == "3")
                this->deleteTutorialUI();
            else if (option == "4")
                this->updateTutorialUI();
            else
                std::cout << "Bad input!" << std::endl;
        } catch (ServiceExceptions& error) {
            std::cout<<error.what()<<std::endl;
        }
        catch (RepositoryException& error) {
            std::cout << error.what() << std::endl;
        }
        catch(UserException& error)
        {
            std::cout<< error.what() << std::endl;
        }catch (const char& msg){
            std::cout<<msg<<std::endl;
        } catch (const std::exception &exc) {
            std::cerr << exc.what();
            std::cout << std::endl;
        }

}

void UI::addTutorialUI() {
    std::cout<<"Add a new tutorial"<<std::endl;
    std::string new_title;
    std::string new_presenter;
    Duration new_duration;
    int new_likes = 0;
    std::string new_link;

    std::cout<<"Enter the info of the tutorial:"<<std::endl;

    std::cout<<"Title: "<<std::endl;
    getline(std::cin, new_title);

    std::cout<<"Presenter: "<<std::endl;
    getline(std::cin, new_presenter);

    std::string minutes_string;
    std::string seconds_string;
    int minutes = 0;
    int seconds = 0;

    std::cout<<"Duration: "<<std::endl;
    std::cout<<"Minutes: "<<std::endl;
    getline(std::cin, minutes_string);

    if (validateString(minutes_string) == 0 && minutes_string.length() != 0)
        minutes = std::stoi(minutes_string);
    else {
        std::cout << "Invalid input for minutes!"<<std::endl;
        while(validateString(minutes_string) != 0 || minutes_string.length() == 0)
        {
            std::cout<<"Minutes: "<<std::endl;
            getline(std::cin, minutes_string);
        }
        minutes = std::stoi(minutes_string);
    }

    std::cout<<"Seconds: "<<std::endl;
    getline(std::cin, seconds_string);
    if (validateString(seconds_string) == 0 && seconds_string.length() != 0)
        seconds = std::stoi(seconds_string);
    else {
        std::cout << "Invalid input for seconds!" << std::endl;
        while(validateString(seconds_string) != 0 || seconds_string.length() == 0)
        {
            std::cout<<"Minutes: "<<std::endl;
            getline(std::cin, seconds_string);
        }
        seconds = std::stoi(seconds_string);
    }

    new_duration = Duration(minutes, seconds);

    std::string likes_string;
    std::cout<<"No. of likes: "<<std::endl;
    getline(std::cin, likes_string);
    if (likes_string.length() != 0)
        new_likes = std::stoi(likes_string);

    std::cout<<"Link: "<<std::endl;
    getline(std::cin, new_link);

   this->service->addTutorialService(new_title, new_presenter, new_duration, new_likes, new_link);
    std::cout<<"Addition Successful!"<<std::endl;
}

void UI::deleteTutorialUI() {
    std::cout<<"Delete a tutorial"<<std::endl;
    std::string tutorial_to_delete;

    std::cout<<"Enter the title of the tutorial to delete"<<std::endl;
    std::cout<<">>>"<<std::endl;
    getline(std::cin, tutorial_to_delete);

    if (!validateString(tutorial_to_delete) || tutorial_to_delete.length() == 0)
        std::cout<<"Invalid title!"<<std::endl;
    else {
        this->service->deleteTutorialService(tutorial_to_delete);
        std::cout << "Tutorial deleted successfully!" << std::endl;
    }
}

void UI::updateTutorialUI() {

    std::cout<<"Update a tutorial"<<std::endl;
    std::string title;
    std::string new_presenter;
    Duration new_duration;
    int new_likes = 0;
    std::string new_link;

    std::cout<<"Enter the info of the tutorial:"<<std::endl;

    std::cout<<"Title: "<<std::endl;
    getline(std::cin, title);
    if (!validateString(title) || (title.length() == 0))
        std::cout<<"Invalid title!"<<std::endl;
    else {
        if (this->service->findTutorial(title) == -1)
            std::cout << "Tutorial is not part of the list!" << std::endl;
        else {

            std::cout << "Enter the changes here: " << std::endl;
            std::cout << "NEW Presenter: " << std::endl;
            getline(std::cin, new_presenter);

            std::string minutes_string;
            std::string seconds_string;
            int minutes = 0;
            int seconds = 0;

            std::cout<<"Duration: "<<std::endl;
            std::cout<<"Minutes: "<<std::endl;
            getline(std::cin, minutes_string);

            if (validateString(minutes_string) == 0 && minutes_string.length() != 0)
                minutes = std::stoi(minutes_string);
            else {
                std::cout << "Invalid input for minutes!"<<std::endl;
                while(validateString(minutes_string) != 0 || minutes_string.length() == 0)
                {
                    std::cout<<"Minutes: "<<std::endl;
                    getline(std::cin, minutes_string);
                }
                minutes = std::stoi(minutes_string);
            }

            std::cout<<"Seconds: "<<std::endl;
            getline(std::cin, seconds_string);
            if (validateString(seconds_string) == 0 && seconds_string.length() != 0)
                seconds = std::stoi(seconds_string);
            else {
                std::cout << "Invalid input for seconds!" << std::endl;
                while(validateString(seconds_string) != 0 || seconds_string.length() == 0)
                {
                    std::cout<<"Minutes: "<<std::endl;
                    getline(std::cin, seconds_string);
                }
                seconds = std::stoi(seconds_string);
            }

            new_duration = Duration(minutes, seconds);

            std::string likes_string;
            std::cout << "NEW No. of likes: " << std::endl;
            getline(std::cin, likes_string);
            if (likes_string.length() != 0)
                new_likes = std::stoi(likes_string);

            std::cout << "NEW Link: " << std::endl;
            getline(std::cin, new_link);

            this->service->updateTutorialService(title, new_presenter, new_duration, new_likes, new_link);
            std::cout << "Tutorial was updated!" << std::endl;
        }
    }
}

void UI::listTutorialsUI() {
    if (this->service->getSizeService() == 0)
        std::cout<<"There are no tutorials in the list!"<<std::endl;
    else
    {
        std::cout<<"The list of tutorials is: "<<std::endl;
        for (int i=0; i< this->service->getSizeService(); i++)
            std::cout<<this->service->getTutorialService(i)<<std::endl;
    }
}

void UI::start_up() {
    bool done = false;
    while (!done) {
        menu();
        std::string option;
        getline(std::cin,option);
        if (option == "1")
            administratorMode();
        else if (option == "2")
            userMode();
        else if (option == "0") {
            done = true;
            std::cout << "Goodbye!" << std::endl;
        }else
           std::cout<<"Bad input!"<<std::endl;
    }
}

bool UI::validateString(std::string whatever) {
    for (int i=0; i<whatever.length(); i++)
        if (std::isdigit(whatever[i]) != false)
            return false;
    return true;
}

void UI::tutorials_with_given_presenter() {
    std::cout<<"Tutorials in the database having a given presenter"<<std::endl;
    std::cout<<"Give the name of the presenter or null to receive all of them: "<<std::endl;
    std::string presenter;
    getline(std::cin, presenter);
    if (!validateString(presenter) || presenter.length() == 0)
        std::cout<<"Invalid name for the presenter!"<<std::endl;
    else {

        this->service->Tutorials_with_presenter(presenter);
        std::string show_next = "next";
        int i = 0;

        while (show_next == "next") {
            bool added;
            if (this->service->getSizePresenter() != 0 and i == this->service->getSizePresenter())
                i = 0;

            std::cout << this->service->getTutorialPresenter(i).toString() << std::endl;
            std::string _link = this->service->getTutorialPresenter(i).getLink();
            const char *url = _link.c_str();
            //I used the c._str() method to convert my link which is a string into a const char*
            ShellExecute(nullptr, "open", url, nullptr, nullptr, SW_SHOWNORMAL);
            std::cout << "Would you like to add this tutorial to your watch list?" << std::endl;
            std::cout << "1. YES" << std::endl;
            std::cout << "2. NO" << std::endl;
            std::cout << "Introduce your option here: >>>" << std::endl;
            std::string option_add_tutorial;
            getline(std::cin, option_add_tutorial);

            if (option_add_tutorial == "1") {
                std::string _title = this->service->getTutorialPresenter(i).getTitle();
                std::string _presenter = this->service->getTutorialPresenter(i).getPresenter();
                Duration _duration = this->service->getTutorialPresenter(i).getDuration();
                int _likes = this->service->getTutorialPresenter(i).getLikes();
                this->service->addTutorialWatchListService(_title, _presenter, _duration, _likes, _link);
                std::cout << "Tutorial added to watch list!" << std::endl;

            } else if (option_add_tutorial != "2")
                std::cout << "Invalid option chosen!";

            std::cout << std::endl;
            std::cout << "Type next for showing the next tutorial>>>" << std::endl;
            getline(std::cin, show_next);
            i++;
        }
    }
}

void UI::delete_from_watch_list()
{
    std::string tutorial_to_delete;

    std::cout<<"Enter the title of the tutorial to delete: "<<std::endl;
    std::cout<<">>>"<<std::endl;
    getline(std::cin, tutorial_to_delete);

    if (!validateString(tutorial_to_delete) || tutorial_to_delete.length() == 0)
        std::cout<<"Invalid title!"<<std::endl;
    else{
    this->service->deleteTutorialWatchListService(tutorial_to_delete);std::cout << "Tutorial deleted successfully!" << std::endl;
    std::cout<<"Rate the tutorial: "<<std::endl;
    std::cout<<"1. LIKE"<<std::endl;
    std::cout <<"2. Not the case"<<std::endl;

    std::cout << "Introduce your option here: >>>" << std::endl;
    std::string option_rate_tutorial;
    getline(std::cin, option_rate_tutorial);

    if (option_rate_tutorial == "1")
        this->service->increase_likes_service(tutorial_to_delete);
    else if (option_rate_tutorial != "2")
        std::cout<<"Invalid option!"<<std::endl;
    }
}

void UI::see_watch_list()
{
    if (this->service->getSizeWatchList() == 0)
        std::cout<<"There are no tutorials in the watch list!"<<std::endl;
    else {
        std::string filename = this->service->getFileName();
        ShellExecute(nullptr, "open", filename.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
    }
}
