#include "Tutorial.h"
#include "TestTutorial.h"
#include <cassert>
#include <string.h>

void TestGetterSetter() {
    Tutorial tutorial1;
    assert(tutorial1.getTitle() == "");
    assert(tutorial1.getPresenter() == "");
    assert(tutorial1.getLink() == "");
    assert(tutorial1.getDuration().getMinutes() == 0);
    assert(tutorial1.getDuration().getSeconds() == 0);
    assert(tutorial1.getLikes() == 0);

    Tutorial tutorial2 = {"C Programming Tutorial for Beginners", "freeCodeCamp", Duration{46, 13}, 7000,
                          "https://www.youtube.com/watch?v=KJgsSFOSQv0"};
    assert(tutorial2.getTitle() == "C Programming Tutorial for Beginners");
    assert(tutorial2.getPresenter() == "freeCodeCamp");
    assert(tutorial2.getDuration().getMinutes() == 46);
    assert(tutorial2.getDuration().getSeconds() == 13);
    assert(tutorial2.getLink() == "https://www.youtube.com/watch?v=KJgsSFOSQv0");
    assert(tutorial2.getLikes() == 7000);

    Tutorial tutorial3(tutorial2);
    assert(tutorial3.getTitle() == "C Programming Tutorial for Beginners");
    assert(tutorial3.getPresenter() == "freeCodeCamp");
    assert(tutorial3.getDuration().getMinutes() == 46);
    assert(tutorial3.getDuration().getSeconds() == 13);
    assert(tutorial3.getLink() == "https://www.youtube.com/watch?v=KJgsSFOSQv0");
    assert(tutorial3.getLikes() == 7000);

    assert(tutorial2.toString() == "TITLE: C Programming Tutorial for Beginners, Presenter: freeCodeCamp, Duration: 46:13 , No. of likes: 7000, and Link: https://www.youtube.com/watch?v=KJgsSFOSQv0");
    tutorial2.LikesSetter(7000);
    assert(tutorial2.getLikes() == 7000);
}