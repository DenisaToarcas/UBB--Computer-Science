#include "Duration.h"

Duration::Duration():minutes{0}, seconds{0} {

}

Duration::Duration(int minutes, int seconds) {
    this->minutes = minutes;
    this->seconds = seconds;
}

int Duration::getMinutes() const {
    return this->minutes;
}

int Duration::getSeconds() const {
    return this->seconds;
}
