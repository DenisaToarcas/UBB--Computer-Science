#include "TestsRepo.h"
#include "Repository.h"
#include <vector>
#include <cassert>

void testAddTutorial(){
    auto * dynamicVector = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector);

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
}

void testDeleteTutorial(){
    auto * dynamicVector = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};
    Tutorial tutorial4 = {"Learn Python", "freeCodeCamp", Duration{26, 52}, 3900, "https://www.youtube.com/watch?v=rfscVS0vtbw"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);
    repo->addTutorial(tutorial4);

    repo->deleteTutorial(0);
    assert(repo->getSizeRepo() == 3);

    repo->deleteTutorial(0);
    assert(repo->getSizeRepo() == 2);
}

void testUpdateTutorial(){
    auto * dynamicVector = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};
    Tutorial tutorial4 = {"Learn Python", "freeCodeCamp", Duration{26, 52}, 3900, "https://www.youtube.com/watch?v=rfscVS0vtbw"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);

    repo->updateTutorial(0, tutorial4);
    int index = repo->findTutorial((std::string &) "C Programming Tutorial for Beginners");
    assert(index == -1);
}

void testFindTutorial(){
    auto * dynamicVector = new std::vector<Tutorial>;
    auto * repo = new Repository(dynamicVector);

    Tutorial tutorial1 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000, "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    Tutorial tutorial2 = {"ASP.NET Integration Testing", "Coding Tutorials", Duration{25, 6}, 3000, "https://www.youtube.com/watch?v=Hmp2ctGacIo"};
    Tutorial tutorial3 = {"How to start coding", "Intellipaat", Duration{33, 8}, 5000, "https://www.youtube.com/watch?v=HIj8wU_rGIU"};

    repo->addTutorial(tutorial1);
    repo->addTutorial(tutorial2);
    repo->addTutorial(tutorial3);

    int index = repo->findTutorial((std::string &)"C Programming Tutorial for Beginners");
    assert(index == -1);
}
