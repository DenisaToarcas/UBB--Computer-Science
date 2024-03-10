#include <crtdbg.h>
#include "Tutorial.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include "TestsRepo.h"
#include "TestTutorial.h"
#include "TestUSER.h"
#include "TestService.h"

int main(){
    testAddTutorial();
    testDeleteTutorial();
    testUpdateTutorial();
    testFindTutorial();
    testIncreaseLikes();
    TestGetterSetter();
    testGetTutorial();
    TestAddTutorialWatchList();
    TestDeleteTutorialWatchList();
    TestGetSizeWatchList();
    TestFindWatchList();
    TestAllRegardingPresenter();
    TestAllService();

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
    Tutorial tutorial5 = {"Python for Beginners", "Mosh", Duration{60, 6}, 10000, "https://www.youtube.com/watch?v=kqtD5dpn9C8"};
    Tutorial tutorial6 = {"C++ full course", "Bro Code", Duration{60, 0}, 23000, "https://www.youtube.com/watch?v=-TkoO8Z07hI"};
    Tutorial tutorial7 = {"Jumping Game", "scratch team", Duration{5, 4}, 450001, "https://www.youtube.com/watch?v=1jHvXakt1qw"};
    Tutorial tutorial8 = {"Pong Game", "scratch team", Duration{10, 55}, 8700001, "https://www.youtube.com/watch?v=BlmBDrnhd2I"};
    Tutorial tutorial9 = {"Data structures", "freeCodeCamp", Duration{3, 7}, 50000, "https://www.youtube.com/watch?v=RBSGKlAvoiM"};
    Tutorial tutorial10 = {"Learn Javascript", "freeCodeCamp", Duration{26, 17}, 80000, "https://www.youtube.com/watch?v=PkZNo7MFNFg"};

    repository->addTutorial(tutorial1);
    repository->addTutorial(tutorial2);
    repository->addTutorial(tutorial3);
    repository->addTutorial(tutorial4);
    repository->addTutorial(tutorial5);
    repository->addTutorial(tutorial6);
    repository->addTutorial(tutorial7);
    repository->addTutorial(tutorial8);
    repository->addTutorial(tutorial9);
    repository->addTutorial(tutorial10);

    auto * service = new Service(repository, userRepository);
    auto * ui = new UI(service);



    ui->start_up();

    _CrtDumpMemoryLeaks();
    return 0;
}
