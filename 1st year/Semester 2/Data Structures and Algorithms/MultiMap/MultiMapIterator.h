#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& col;
    int currentSLLIndex;        //index of the current SLL
	Node* current_node;         //pointer to the current node in the SLL
    int currentDynamicArrayIndex; //index of the current element in the dynamic array

	//DO NOT CHANGE THIS PART
	MultiMapIterator(const MultiMap& c);

public:
	TElem getCurrent()const;
	bool valid() const;
	void next();
	void first();
};

