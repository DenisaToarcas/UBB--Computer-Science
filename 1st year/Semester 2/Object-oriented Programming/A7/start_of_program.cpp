#include <crtdbg.h>
#include "UI/UI.h"
#include <iostream>

int main(){
    //testAddTutorial();
    //testDeleteTutorial();
    //testUpdateTutorial();
    //testFindTutorial();

    std::cout<<"Choose between CSV or HTML files for the watch list:"<<std::endl;
    std::string option_of_file;
    getline(std::cin, option_of_file);

    if (option_of_file == "CSV" or option_of_file == "csv")
    {
        std::cout<<"Give the filename:"<<std::endl;
        std::string filename;
        std::string type_of_file;
        getline(std::cin, filename);
        type_of_file = "CSV";

        auto * dynamicVector = new std::vector<Tutorial>;
        auto * dynamicVector1 = new std::vector<Tutorial>;
        auto * dynamicVector2 = new std::vector<Tutorial>;
        auto * repository = new Repository(dynamicVector);

        auto * userRepository = new CSVRepository(dynamicVector1, dynamicVector2, filename);
        std::cout<<"Introduce the name of the file from where to read the data:"<<std::endl;
        std::string fileNameREPO;
        getline(std::cin, fileNameREPO);

        //The tutorials for the repository
        //D:\@SEM 2\OOP\a7-DenisaToarcas-1\test.txt

        //CSV filename
        //D:\@SEM 2\OOP\a7-DenisaToarcas-1\CSVfile.txt

        auto * validator = new Validator();
        auto * service = new Service(repository, userRepository, fileNameREPO, validator, type_of_file, filename);
        auto * ui = new UI(service);
        try{
            service->loadTutorialsFromFile();
            //service->verify_type_file();
        }
        catch (RepositoryException& error){
            std::cout<< error.what() << std::endl;
        }
        catch (ServiceExceptions& error)
        {
            std::cout<< error.what() << std::endl;
        }
        catch(UserException& error)
        {
            std::cout<< error.what() << std::endl;
        }catch (const std::exception &exc) {
            std::cerr << exc.what();
            std::cout << std::endl;
        }

        ui->start_up();

    }
    else {
        if (option_of_file == "HTML" or option_of_file == "html") {

            std::cout<<"Give the filename:"<<std::endl;
            std::string filename;
            std::string type_of_file;
            getline(std::cin, filename);
            type_of_file = "CSV";

            auto * dynamicVector = new std::vector<Tutorial>;
            auto * dynamicVector1 = new std::vector<Tutorial>;
            auto * dynamicVector2 = new std::vector<Tutorial>;
            auto * repository = new Repository(dynamicVector);

            auto * userRepository = new HTMLRepository(dynamicVector1, dynamicVector2, filename);
            std::cout<<"Introduce the name of the file from where to read the data:"<<std::endl;
            std::string fileNameREPO;
            getline(std::cin, fileNameREPO);

            //The tutorials for the repository
            //D:\@SEM 2\OOP\a7-DenisaToarcas-1\test.txt

            //HTML filename
            //D:\@SEM 2\OOP\a7-DenisaToarcas-1\HTMLfile.html

            auto * validator = new Validator();
            auto * service = new Service(repository, userRepository, fileNameREPO, validator, type_of_file, filename);
            auto * ui = new UI(service);
            try{
                service->loadTutorialsFromFile();
                //service->verify_type_file();
            }
            catch (RepositoryException& error){
                std::cout<< error.what() << std::endl;
            }
            catch (ServiceExceptions& error)
            {
                std::cout<< error.what() << std::endl;
            }
            catch(UserException& error)
            {
                std::cout<< error.what() << std::endl;
            }catch (const std::exception &exc) {
                std::cerr << exc.what();
                std::cout << std::endl;
            }

            ui->start_up();
        }
        else
        {
            std::cout << "The option of file is invalid! Bye bye!";
        }
    }

    _CrtDumpMemoryLeaks();
    return 0;
}
