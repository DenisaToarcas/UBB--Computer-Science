#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& col;
	int currentBucket;
    Node* current_node;
    int current_pos_in_values;

	//DO NOT CHANGE THIS PART
	MultiMapIterator(const MultiMap& c);

public:
	TElem getCurrent()const;
	bool valid() const;
	void next();
	void first();
};

