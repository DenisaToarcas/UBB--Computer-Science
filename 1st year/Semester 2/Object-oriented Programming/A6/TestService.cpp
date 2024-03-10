#include "TestService.h"

void TestAllService()
{
    auto * dynamicVector = new std::vector<Tutorial>;
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * dynamicVector2 = new std::vector<Tutorial>;
    auto * repository = new Repository(dynamicVector);
    auto * userRepository = new userRepo(dynamicVector1, dynamicVector2);

    //adding 10 entries
    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};
    Tutorial tutorial4 = {"Learn Python", "freeCodeCamp", Duration{26, 52}, 3900, "https://www.youtube.com/watch?v=rfscVS0vtbw"};

    auto * service = new Service(repository, userRepository);
    assert(service->getSizeService() == 0);

    service->addTutorialService(tutorial1.getTitle(), tutorial1.getPresenter(), tutorial1.getDuration(), tutorial1.getLikes(), tutorial1.getLink());
    assert(service->getSizeService() == 1);

    service->addTutorialService(tutorial2.getTitle(), tutorial2.getPresenter(), tutorial2. getDuration(), tutorial2.getLikes(), tutorial2.getLink());
    assert(service->getSizeService() == 2);

    assert(service->addTutorialService(tutorial2.getTitle(), tutorial2.getPresenter(), tutorial2. getDuration(), tutorial2.getLikes(), tutorial2.getLink()) ==
                   false);
    assert(service->getSizeService() == 2);

    assert(service->getTutorialService(0).getTitle() == "C Programming Tutorial for Beginners");
    assert(service->getTutorialService(1).getTitle() == "ASP.NET Integration Testing");

    service->deleteTutorialService("C Programming Tutorial for Beginners");
    assert(service->getSizeService() == 1);

    assert(service->deleteTutorialService("C Programming Tutorial for Beginners") == false);
    service->addTutorialService(tutorial1.getTitle(), tutorial1.getPresenter(), tutorial1.getDuration(), tutorial1.getLikes(), tutorial1.getLink());
    service->updateTutorialService(tutorial1.getTitle(), tutorial3.getPresenter(), tutorial3.getDuration(), tutorial3.getLikes(), tutorial3.getLink());
    assert(service->getTutorialService(1).getPresenter() == tutorial3.getPresenter());

    assert(service->updateTutorialService(tutorial3.getTitle(), tutorial3.getPresenter(), tutorial3.getDuration(), tutorial3.getLikes(), tutorial3.getLink()) ==
                   false);
    delete service;
}