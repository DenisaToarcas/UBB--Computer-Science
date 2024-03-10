#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>

using namespace std;

SortedBag::SortedBag(Relation r) {
	this->relation = r;
	this->capacity = 10;
	this->nrElements = 0;
	this->elements = new TElem[this->capacity];
}

void SortedBag::add(TComp e) {
	if (this->nrElements == this->capacity) {
		//I have to resize my bag
		this->capacity *= 2;
		TElem* aux;
		aux = new TElem[this->capacity];
		for (int i = 0; i < this->nrElements; i++)
			aux[i] = this->elements[i];

		delete[] this->elements;
		this->elements = aux;
	}
	//have to add the element in the right place
	//while the relation is respected, we parse over the array
	// && this->relation(this->elements[i], elem) == true
	int i = 0;
	while (i < this->nrElements && this->relation(this->elements[i], e) == true) 
		i++;

	if (i == this->nrElements)
	{
		this->elements[i] = e;
		this-> nrElements++;
	}
	else {
		TComp previous = e;
		TComp next;
		this->nrElements++;
		for (int j = i; j <this->nrElements; j++)
		{
			next = this->elements[j];
			this->elements[j] = previous;
			previous = next;
		}
	}
}


bool SortedBag::remove(TComp e) {
	int position = -1;

	for (int i = 0; i < this->nrElements; i++) {
		if (this->elements[i] == e) {
			position = i;
			break;
		}
	}
	if (position == -1) {
		return false;
	}
	else {
		for (int i = position; i < this->nrElements - 1; i++) {
			this->elements[i] = this->elements[i + 1];
		}
		this->nrElements--;
		return true;
	}
}


bool SortedBag::search(TComp elem) const {
	bool found = false;
	int i = 0;
	while (i < this->nrElements && found == false) {
		if (this->elements[i] == elem) {
			found = true;
		}
		i++;
	}
	return found;
}

int SortedBag::nrOccurrences(TComp elem) const {
	int count = 0;
	int i = 0;
	while (i < this->nrElements) {
		if (this->elements[i] == elem) {
			count++;
		}
		i++;
	}
	return count;
}



int SortedBag::size() const {
	return this->nrElements;
}


bool SortedBag::isEmpty() const {
	if (this->nrElements == 0) {
		return true;
	}
	else {
		return false;
	}
}

void SortedBag::addOccurrences(int nr, TComp elem)
{
	//adds nr occurences of elem into the SortedBag -> if elem was not part of the bag, it will be added
	//throws an exception if nr is negative
	if (nr < 0)
		throw (nr);
	else {
		if (this->nrOccurrences(elem) == 0)
		{
			this->add(elem);
			nr--;
		}

		while (nr > 0)
		{
			this->add(elem);
			nr--;
		}
	}
}
//Best case: if nr is negative -> complexity = Theta(1);
//Worst case: elem should be added at the "end" of the sorted bad -> complexity = Theta(nr*nrElements);
//Total complexity = O(nr*nrEelements);

SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	delete[] this->elements;
}
