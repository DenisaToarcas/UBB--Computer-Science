#include "Service.h"

#include <utility>

Service::Service(std::shared_ptr<Repository> repository, std::shared_ptr<userRepo> userRepository, std::string& fileName, const std::shared_ptr<Validator>& validator) {
    this->repository = std::move(repository);
    this->userRepository = std::move(userRepository);
    this->fileName = fileName;
    this->validator = validator;
}

Service::~Service() = default;

unsigned long long Service::getSizeService() const {
    return this->repository->getSizeRepo();
}

Tutorial Service::getTutorialService(int index) {
    if (0 < index < this->repository->getSizeRepo())
        return this->repository->getTutorialRepo(index);
    else
    {
        std::string error = "Invalid index!";
        throw ServiceExceptions(error);
    }
}

bool Service::addTutorialService(std::string &title, std::string &presenter, Duration &duration, int likes,
                                 std::string &link) {
    Tutorial new_Tutorial = Tutorial(title, presenter, duration, likes, link);
    this->validator->validateTutorial(title, presenter, duration, likes, link);
    if (this->repository->findTutorial(title) != -1)
    {
        std::string error = "Tutorial already part of the list!";
        throw ServiceExceptions(error);
    }
    else
    {
        this->repository->addTutorial(new_Tutorial);
        this->writeTutorialsToFile();
        return true;
    }
}

bool Service::deleteTutorialService(std::string &title) {
    long long index;
    index = this->repository->findTutorial(title);
    if (index != -1){
        this->repository->deleteTutorial(index);
        this->writeTutorialsToFile();
        return true;
    }
    else
    {
        std::string error = "Tutorial is not part of the list!";
        throw ServiceExceptions(error);
    }
}

bool Service::updateTutorialService(std::string &title, std::string& new_presenter, Duration& new_duration, int likes, std::string& link) {
    long long index;
    Tutorial objectUpdated = Tutorial(title, new_presenter, new_duration, likes, link);
    this->validator->validateTutorial(title, new_presenter, new_duration, likes, link);
    index = this->repository->findTutorial(title);
    if (index != -1){
        this->repository->updateTutorial(index, objectUpdated);
        this->writeTutorialsToFile();
        return true;
    }
    else
    {
        std::string error = "Tutorial is not part of the list!";
        throw ServiceExceptions(error);
    }
}

long long Service::findTutorial(std::string &title) {
    return this->repository->findTutorial(title);
}

Tutorial *Service::getTutorials() {
    return this->repository->getTutorials();
}

bool Service::addTutorialWatchListService(std::string &title, std::string &presenter, Duration &duration, int likes, std::string &link) {
    Tutorial new_Tutorial = Tutorial(title, presenter, duration, likes, link);
    this->validator->validateTutorial(title, presenter, duration, likes, link);
    if (this->userRepository->findTutorialWatchList(title) != -1)
    {
        std::string error = "Tutorial is already part of the watch list!";
        throw ServiceExceptions(error);
    }
    else
    {
        this->userRepository->addTutorialWatchList(new_Tutorial);
        return true;
    }
}

bool Service::deleteTutorialWatchListService(std::string &title) {
    long long index;
    index = this->userRepository->findTutorialWatchList(title);
    if (index != -1){
        this->userRepository->deleteTutorialWatchList(index);
        return true;
    }
    else
    {
        std::string error = "Tutorial is not part of the watch list!";
        throw ServiceExceptions(error);
    }
}

void Service::Tutorials_with_presenter(std::string &presenter) {
    if (this->userRepository->getSizePresenter() != 0)
        while (this->userRepository->getSizePresenter() != 0)
            this->userRepository->deleteTutorialPresenter(0);

    if (presenter == "null")
        for (int i=0; i< this->repository->getSizeRepo(); i++)
            this->userRepository->addTutorialPresenter(this->repository->getTutorialRepo(i));
    else{
        for (int i=0; i< this->repository->getSizeRepo(); i++)
            if (this->repository->getTutorialRepo(i).getPresenter() == presenter)
                this->userRepository->addTutorialPresenter(this->repository->getTutorialRepo(i));
    }

   if (this->userRepository->getSizePresenter() == 0)
   {
       std::string error = "No tutorials with this presenter!";
       throw ServiceExceptions(error);
   }
}

unsigned long long Service::getSizeWatchList() const {
    return this->userRepository->getSizeWatchList();
}

unsigned long long Service::getSizePresenter() const {
    return this->userRepository->getSizePresenter();
}

Tutorial Service::getTutorialWatchList(int index) {
    if (0 < index < this->userRepository->getSizeWatchList())
        return this->userRepository->getTutorialWatchList(index);
    else
    {
        std::string error = "Invalid index!";
        throw ServiceExceptions(error);
    }
}

Tutorial Service::getTutorialPresenter(int index) {
    if (0 < this->userRepository->getSizePresenter())
        return this->userRepository->getTutorialPresenter(index);
    else
    {
        std::string error = "Invalid index!";
        throw ServiceExceptions(error);
    }
}

void Service::increase_likes_service(std::string &title) {
    long long index;
    index = this->repository->findTutorial(title);
    if (index != -1)
        this->repository->increase_likes(index);
}

void Service::loadTutorialsFromFile() {
    this->repository->loadTutorialsFromFile(this->fileName);
}

void Service::writeTutorialsToFile() {
    this->repository->writeTutorialsToFile(this->getFileName());
}

std::string &Service::getFileName() {
    return this->userRepository->getFileName();
}

std::vector<Tutorial> *Service::getAllTutorials() {
    return this->repository->getAllTutorials();
}

std::vector<Tutorial> *Service::getAll_watch_list() {
    return this->userRepository->getAll_watch_list();
}

std::vector<Tutorial> *Service::getAll_same_presenter() {
    return this->userRepository->getAll_same_presenter();
}

//void Service::verify_type_file() {
//    if (this->type_of_file == "CSV")
//    {
//        auto* csvRepo = new CSVRepository(this->userRepository->getTutorialsUSER(), this->userRepository->getTutorialsPresenter(), this->filenameUSER);
//        //(CSVRepository)* this->userRepository = csvRepo; ->this is practically what I want to do
//    }
//    else
//    {
//        if (this->type_of_file == "HTML")
//        {
//        }
//        else
//            throw ServiceExceptions((std::string&) "Invalid type pf file given!");
//    }
//}
