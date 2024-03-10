#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	this->index = list.head;
}

void ListIterator::first() {
	this->index = list.head;
}

void ListIterator::next() {
    if (valid())
        this->index = list.nodes[this->index].next;
    else {
        throw exception();
    }
}

bool ListIterator::valid() const {
	return this->index != -1;
}

TElem ListIterator::getCurrent() const {
    if (this->valid())
        return list.nodes[this->index].elem;
    else
        return NULL_TELEM;
}



