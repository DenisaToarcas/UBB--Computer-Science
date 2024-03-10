#include "TestsRepo.h"

void testAddTutorial(){
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector1);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    repo->addTutorial(tutorial1);

    assert(repo->getSizeRepo() == 1);

    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};
    Tutorial tutorial4 = {"Learn Python", "freeCodeCamp", Duration{26, 52}, 3900, "https://www.youtube.com/watch?v=rfscVS0vtbw"};

    repo->addTutorial(tutorial2);
    assert(repo->getSizeRepo() == 2);

    repo->addTutorial(tutorial3);
    assert(repo->getSizeRepo() == 3);
    delete repo;
}

void testDeleteTutorial(){
    auto * dynamicVector2 = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector2);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};
    Tutorial tutorial4 = {"Learn Python", "freeCodeCamp", Duration{26, 52}, 3900, "https://www.youtube.com/watch?v=rfscVS0vtbw"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);
    repo->addTutorial(tutorial4);
    assert(repo->getSizeRepo() == 4);

    repo->deleteTutorial(0);
    assert(repo->getSizeRepo() == 3);

    repo->deleteTutorial(0);
    assert(repo->getSizeRepo() == 2);
    delete repo;
}

void testUpdateTutorial(){
    auto * dynamicVector3 = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector3);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};
    Tutorial tutorial4 = {"Learn Python", "freeCodeCamp", Duration{26, 52}, 3900, "https://www.youtube.com/watch?v=rfscVS0vtbw"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);

    repo->updateTutorial(0, tutorial4);
    long int index = repo->findTutorial((std::string &) "C Programming Tutorial for Beginners");
    assert(index == -1);
    assert(repo->getTutorialRepo(2).getTitle() == tutorial4.getTitle());
    delete repo;
}

void testFindTutorial(){
    auto * dynamicVector4 = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector4);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);

    long int index = repo->findTutorial("How to start coding");
    assert(index == 2);

    long int index1 = repo->findTutorial("alala");
    assert(index1 == -1);
    delete repo;
}

void testIncreaseLikes()
{
    auto * dynamicVector4 = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector4);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);

    repo->increase_likes(0);
    assert(repo->getTutorialRepo(0).getLikes() == 7001);
    delete repo;
}

void testGetTutorial()
{
    auto * dynamicVector5 = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector5);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);

    assert(repo->getTutorialRepo(0).getTitle() == "C Programming Tutorial for Beginners");
    assert(repo->getTutorialRepo(1).getTitle() == "ASP.NET Integration Testing");
    delete repo;
}
