#include "TestUSER.h"

void TestGetSizeWatchList()
{
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * dynamicVector2 = new std::vector<Tutorial>;
    auto * userRepository = new userRepo(dynamicVector1, dynamicVector2);

//adding 10 entries
    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};
    Tutorial tutorial4 = {"Learn Python", "freeCodeCamp", Duration{26, 52}, 3900, "https://www.youtube.com/watch?v=rfscVS0vtbw"};

    assert(userRepository->getSizeWatchList() == 0);

    userRepository->addTutorialWatchList(tutorial1);
    userRepository->addTutorialWatchList(tutorial2);
    assert(userRepository->getSizeWatchList() == 2);
    delete userRepository;
}

void TestAddTutorialWatchList()
{
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * dynamicVector2 = new std::vector<Tutorial>;
    auto * userRepository = new userRepo(dynamicVector1, dynamicVector2);

//adding 10 entries
    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};

    assert(userRepository->getSizeWatchList() == 0);

    userRepository->addTutorialWatchList(tutorial1);
    userRepository->addTutorialWatchList(tutorial2);
    assert(userRepository->getSizeWatchList() == 2);
    assert(userRepository->getTutorialWatchList(0).getTitle() == "C Programming Tutorial for Beginners");
    assert(userRepository->getTutorialWatchList(1).getTitle() == "ASP.NET Integration Testing");
    delete userRepository;
}

void TestDeleteTutorialWatchList()
{
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * dynamicVector2 = new std::vector<Tutorial>;
    auto * userRepository = new userRepo(dynamicVector1, dynamicVector2);

//adding 10 entries
    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};

    assert(userRepository->getSizeWatchList() == 0);

    userRepository->addTutorialWatchList(tutorial1);
    userRepository->addTutorialWatchList(tutorial2);
    assert(userRepository->getSizeWatchList() == 2);

    userRepository->deleteTutorialWatchList(0);
    assert(userRepository->getSizeWatchList() == 1);
    assert(userRepository->getTutorialWatchList(0).getTitle() == "ASP.NET Integration Testing");
    userRepository->deleteTutorialWatchList(0);
    assert(userRepository->getSizeWatchList() == 0);
    delete userRepository;
}

void TestFindWatchList()
{
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * dynamicVector2 = new std::vector<Tutorial>;
    auto * userRepository = new userRepo(dynamicVector1, dynamicVector2);

//adding 10 entries
    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};

    assert(userRepository->getSizeWatchList() == 0);

    userRepository->addTutorialWatchList(tutorial1);
    userRepository->addTutorialWatchList(tutorial2);
    assert(userRepository->getSizeWatchList() == 2);

    int index = userRepository->findTutorialWatchList("C Programming Tutorial for Beginners");
    assert(index == 0);
    index = userRepository->findTutorialWatchList("ASP.NET Integration Testing");
    assert(index == 1);
    index = userRepository->findTutorialWatchList("alalal");
    assert(index == -1);

    delete userRepository;
}

void TestAllRegardingPresenter()
{
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * dynamicVector2 = new std::vector<Tutorial>;
    auto * userRepository = new userRepo(dynamicVector1, dynamicVector2);

    Tutorial tutorial9 = {"Data structures", "freeCodeCamp", Duration{3, 7}, 50000, "https://www.youtube.com/watch?v=RBSGKlAvoiM"};
    Tutorial tutorial10 = {"Learn Javascript", "freeCodeCamp", Duration{26, 17}, 80000, "https://www.youtube.com/watch?v=PkZNo7MFNFg"};
    assert(userRepository->getSizePresenter() == 0);
    userRepository->addTutorialPresenter(tutorial10);
    userRepository->addTutorialPresenter(tutorial9);
    assert(userRepository->getSizePresenter() == 2);
    assert(userRepository->getTutorialPresenter(1).getTitle() == "Data structures");
    assert(userRepository->getTutorialPresenter(0).getTitle() == "Learn Javascript");

    userRepository->deleteTutorialPresenter(0);
    assert(userRepository->getSizePresenter() == 1);
    delete userRepository;
}