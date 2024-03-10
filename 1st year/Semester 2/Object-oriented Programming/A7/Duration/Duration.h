#pragma once

class Duration
{
private:
    int minutes;
    int seconds;

public:
    Duration();
    Duration(int minutes, int seconds);

    int getMinutes() const;
    int getSeconds() const;
};