#include "Service.h"

Service::Service(Repository *repository, userRepo *userRepository) {
    this->repository = repository;
    this->userRepository = userRepository;
}

Service::~Service() {
    delete this->repository;
    delete this->userRepository;
}

unsigned long long Service::getSizeService() const {
    return this->repository->getSizeRepo();
}

Tutorial Service::getTutorialService(int index) {
    if (0 < index < this->repository->getSizeRepo())
        return this->repository->getTutorialRepo(index);
    else
        throw "Invalid index!";
}

bool Service::addTutorialService(const std::string &title, const std::string &presenter, const Duration &duration, int likes,
                                 const std::string &link) {
    Tutorial new_Tutorial = Tutorial(title, presenter, duration, likes, link);
    if (this->repository->findTutorial(title) != -1)
        return false;       //this means that this Tutorial is already part of the list
    else
    {
        this->repository->addTutorial(new_Tutorial);
        return true;
    }
}

bool Service::deleteTutorialService(const std::string &title) {
    long long index;
    index = this->repository->findTutorial(title);
    if (index != -1){
        this->repository->deleteTutorial(index);
        return true;
    }
    else
        return false;
}

bool Service::updateTutorialService(const std::string &title, const std::string &new_presenter, const Duration &new_duration, int likes,
                                    const std::string &link)
{
    long long index;
    Tutorial objectUpdated = Tutorial(title, new_presenter, new_duration, likes, link);
    index = this->repository->findTutorial(title);
    if (index != -1){
        this->repository->updateTutorial(index, objectUpdated);
        return true;
    }
    return false;
}

long long Service::findTutorial(std::string &title) {
    return this->repository->findTutorial(title);
}

//std::vector<Tutorial>* Service::getTutorials() {
//    return this->repository->getTutorials();
//}

bool Service::addTutorialWatchListService(std::string &title, std::string &presenter, Duration &duration, int likes, std::string &link) {
    Tutorial new_Tutorial = Tutorial(title, presenter, duration, likes, link);
    if (this->userRepository->findTutorialWatchList(title) != -1)
        return false;       //this means that this Tutorial is already part of the list
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
        return false;
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
       throw "No tutorials with this presenter!";
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
        throw "Invalid index!";
}

Tutorial Service::getTutorialPresenter(int index) {
    if (0 < this->userRepository->getSizePresenter())
        return this->userRepository->getTutorialPresenter(index);
    else
        throw "Invalid index!";
}

void Service::increase_likes_service(std::string &title) {
    long long index;
    index = this->repository->findTutorial(title);
    if (index != -1)
        this->repository->increase_likes(index);
}
