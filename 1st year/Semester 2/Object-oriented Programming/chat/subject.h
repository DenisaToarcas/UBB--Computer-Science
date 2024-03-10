#pragma once

#include <vector>
#include "observer.h"

class Subject
{
private:
	std::vector<Observer*> observers; 

public:
	Subject() {};
	~Subject() {};
	void addObserver(Observer* observer) 
	{
		observers.push_back(observer);
	}
	void deleteObserver(Observer* observer) 
	{
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}
	void notify()
	{
		for (auto observer : observers)
		{
			observer->update();
		}
	}
};