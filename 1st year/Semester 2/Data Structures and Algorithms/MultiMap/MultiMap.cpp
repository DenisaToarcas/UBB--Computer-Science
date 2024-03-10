#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
    this->multimap = new DynamicArray_of_slls();
}


void MultiMap::add(TKey c, TValue v) {
    this->multimap->addPair(c, v);
}


bool MultiMap::remove(TKey c, TValue v) {
	return this->multimap->removePair(c, v);
}


vector<TValue> MultiMap::search(TKey c) const {
	return this->multimap->searchKey(c);
}


int MultiMap::size() const {
	return this->multimap->getSize();
}


bool MultiMap::isEmpty() const {
	return this->multimap->getSize() == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	delete this->multimap;
}

