#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>

using namespace std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
	//constructor
	if (capacity <= 0) {
		throw exception();
	}
	this->capacity = capacity;
	this->nrPairs = 0;
	this->elements = new TElem[capacity];
}

FixedCapBiMap::~FixedCapBiMap() {
	//destructor
	delete[] this->elements; 
}

bool FixedCapBiMap::add(TKey c, TValue v){
	if (this->capacity == this->nrPairs) {
		throw exception();
	}
	int index = 0;
	int count = 0;
	while (count < 2 && index < this->nrPairs) {
		if (this->elements[index].first == c) {
			count++;
		}
		index++;
	}
	if (count == 2) {
		return false;
	}
	else {
		this->elements[this->nrPairs].first = c;
		this->elements[this->nrPairs].second = v;
		this->nrPairs++;
		return true;
	}
}

ValuePair FixedCapBiMap::search(TKey c) const{
	int index = 0;
	int count = 0;

	ValuePair returnValue;
	returnValue.first = NULL_TVALUE;
	returnValue.second = NULL_TVALUE;

	while (count < 2 && index < this->nrPairs) {
		if (this->elements[index].first == c)
		{
			if (count == 0)
			{
				returnValue.first = this->elements[index].second;
			}
			else {
				returnValue.second = this->elements[index].second;
			}
			count++;
		}
		index++;
	}
	return returnValue;
}

bool FixedCapBiMap::remove(TKey c, TValue v){
	int index = 0;
	bool removed = false;

	while (index < this->nrPairs && removed != true) {
		if (this->elements[index].first == c && this->elements[index].second == v) {
			removed = true;
		}
		else {
			index++;
		}
	}

	if (removed == true) {
		this->elements[index] = this->elements[nrPairs - 1];
		this->nrPairs--;
		return true;
	}
	else {
		return false;
	}
}


int FixedCapBiMap::size() const {
	return this->nrPairs;
	//if we have a function called size() -> WE CANNOT HAVE A VARIABLE (an atribute) CALLED this->size
}

bool FixedCapBiMap::isEmpty() const{
	if (this->nrPairs == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool FixedCapBiMap::isFull() const {
	if (this->capacity == this->nrPairs) {
		return true;
	}
	else {
		return false;
	}
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}



