#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	int current;
	//the position of the current element
	SortedBagIterator(const SortedBag& b);


public:
	TComp getCurrent();
	bool valid();
	void next();
	void first();
};

