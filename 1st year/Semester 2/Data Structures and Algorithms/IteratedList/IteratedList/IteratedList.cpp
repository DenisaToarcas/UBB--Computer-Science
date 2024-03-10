
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"
#include <iostream>

IteratedList::IteratedList() {
	this->cap = 10;
    this->head = -1;
    this->size_iterated_list = 0;
    this->firstFREE = 0;
    this->nodes = new SLLANode[cap];

    for (int i=0; i< cap -1; i++)
        this->nodes[i].next = i+1;

    this->nodes[cap-1].next = -1;
}

int IteratedList::size() const {
    return this->size_iterated_list;
}

bool IteratedList::isEmpty() const {
	return this->size_iterated_list == 0;
}

ListIterator IteratedList::first() const {
	return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const {
//    try {
        if (!pos.valid())
            throw std::exception();

        return pos.getCurrent();
    //}
//    catch(std::exception&) {
//        throw std::exception();
//    }
}

TElem IteratedList::remove(ListIterator& pos) {
    if (pos.valid()) {
        TElem removed_value = pos.getCurrent();
        if (pos.index == this->head)
            this->head = this->nodes[this->head].next;
        else{
            ListIterator pos1 = ListIterator(*this);
            ListIterator pos2 = ListIterator(*this);
            while (pos1.valid() and pos1.index != pos.index)
            {
                if (pos.index != this->head)
                    pos2.next();        //1 step before pos1
                pos1.next();
            }
            pos.next();
            this->nodes[pos2.index].next = pos.index;
        }
        this->size_iterated_list--;
        return removed_value;
    } else {
        throw std::exception();
    }
}

ListIterator IteratedList::search(TElem e) const{
    ListIterator pos = ListIterator(*this);
    while (pos.getCurrent() != e and pos.valid())
        pos.next();
    return pos;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    if (!pos.valid())
        throw std::exception();

    TElem value_unchanged = pos.getCurrent();
    this->nodes[pos.index].elem = e;
    return value_unchanged;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {

    if (!pos.valid())
        throw std::exception();
    else{
        if (this->firstFREE == -1)
            resize();

//        if (pos.index == this->head)
//            addToBeginning(e);
//        else
//        {
            ListIterator initial_pos = ListIterator(*this);
            while (initial_pos.valid() and initial_pos.index != pos.index)
                initial_pos.next();
            initial_pos.next();

//            if (initial_pos.index == this->firstFREE)
//                addToEnd(e);
//            else {
                this->size_iterated_list++;
                this->nodes[pos.index].next = this->firstFREE;
                this->nodes[firstFREE].elem = e;
                int position = this->nodes[this->firstFREE].next;

                this->nodes[this->firstFREE].next = initial_pos.index;
                this->firstFREE = position;
                pos.next();
    }
}

void IteratedList::addToEnd(TElem e) {
    if (this->firstFREE == -1)
        resize();
    int position = this->firstFREE;
    this->firstFREE = this->nodes[this->firstFREE].next;
    this->nodes[position].elem = e;
    this->nodes[position].next = -1;

    this->size_iterated_list++;
    if (this->size_iterated_list == 1)
        this->head = position;

    else
    {
        ListIterator pos = ListIterator(*this);
        for (int i=0; i< this->size_iterated_list - 2; i++)
            pos.next();
        this->nodes[pos.index].next = position;
    }
}

IteratedList::~IteratedList() {
	delete[] this->nodes;
}

void IteratedList::addToBeginning(TElem e) {
    if (this->firstFREE == -1)
        resize();
    int position = this->firstFREE;
    this->firstFREE = this->nodes[position].next;
    this->nodes[position].elem = e;
    this->nodes[position].next = this->head;
    this->head = position;
    this->size_iterated_list++;
}

void IteratedList::resize() {
    this->cap = 2* this->cap;
    SLLANode* nodes_storage;

    nodes_storage = new SLLANode[cap];

    for (int i=0; i< this->cap/2; i++)
        nodes_storage[i] = this->nodes[i];

    for (int i=cap/2 - 1; i< cap - 1; i++)
        this->nodes[i].next = i+1;

    this->nodes[cap-1].next = -1;

    delete[] this->nodes;
    this->nodes = nodes_storage;
}

int IteratedList::removeAll(IteratedList &list) {
    int removed_elements = 0;
    ListIterator it = ListIterator(list);
    while (it.valid())
    {
        if (search(this->nodes[it.index].elem).valid())
        {
            removed_elements++;
            ListIterator pos = search(this->nodes[it.index].elem);
            remove(pos);
        }
        it.next();
    }

    return removed_elements;
}
