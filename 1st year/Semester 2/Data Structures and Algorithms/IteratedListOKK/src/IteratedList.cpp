#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList()
{
    this->cap = 2;
    this->head = -1;        //index of the first element in the list
    this->size_iterated_list = 0;       //no of elements
    this->firstFREE = 0;                //index of the first free
    this->nodes = new SLLANode[cap];

    for (int i = 0; i < cap - 1; i++)
        this->nodes[i].next = i + 1;

    this->nodes[cap - 1].next = -1;
    //-1 represent an invalid index
}

int IteratedList::size() const
{
    return this->size_iterated_list;
}

bool IteratedList::isEmpty() const
{
    return this->size_iterated_list == 0;
}

ListIterator IteratedList::first() const
{
    return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const
{
    if (!pos.valid())
        throw std::exception();

    return pos.getCurrent();
}

TElem IteratedList::remove(ListIterator &pos)
{
    //check if the iterator is valid
    //otherwise, this means that we are at the end fo our list OR
    //the list is empty

    if (pos.valid())
    {
        TElem removed_value = pos.getCurrent();
        this->nodes[pos.index].elem = NULL_TELEM;
        //we mark the element at the current position to know it is removed

        if (pos.index == this->head)
        {
            this->head = this->nodes[this->head].next;
            this->nodes[pos.index].next = this->firstFREE;
            this->firstFREE = pos.index;
            pos.index = this->head;
        }
        else
        {
            ListIterator pos1 = ListIterator(*this);
            ListIterator pos2 = ListIterator(*this);
            while (pos1.valid() && pos1.index != pos.index)
            {
                if (pos1.index != this->head)
                    pos2.next(); // 1 step before pos1
                pos1.next();
            }
            pos1.next();

            if (this->nodes[pos.index].next == -1)
            {
                this->nodes[pos2.index].next = -1;
            }
            else
            {
                this->nodes[pos2.index].next = this->nodes[pos.index].next;
            }

            this->nodes[pos.index].next = this->firstFREE;
            this->firstFREE = pos.index;

            pos.index = pos1.index;
        }

        this->size_iterated_list--;
        return removed_value;
    }
    else
    {
        throw std::exception();
    }
}
//Complexity:
// BC = O(1), when removing the head of the list
// AND
// WC = O(n), when removing the last node of the list
//n = no of nodes of the list

ListIterator IteratedList::search(TElem e) const
{
    ListIterator pos = ListIterator(*this);
    while (pos.valid() && pos.getCurrent() != e)
        pos.next();
    return pos;
}
//Complexity:
// BC = O(1), when e is stored in the head of the list
// AND
// WC = O(n), when e is stored in the last node of the list
//n = no of nodes of the list

TElem IteratedList::setElement(ListIterator pos, TElem e)
{
    if (!pos.valid())
        throw std::exception();

    TElem value_unchanged = pos.getCurrent();
    this->nodes[pos.index].elem = e;
    return value_unchanged;
}

void IteratedList::addToPosition(ListIterator &pos, TElem e)
{

    if (!pos.valid())
        throw std::exception();
    else
    {
        if (this->firstFREE == -1)
            resize();

        int newFirstEmpty = this->nodes[this->firstFREE].next;
        ListIterator initial_pos(*this);
        while (initial_pos.valid() && initial_pos.index != pos.index)
            initial_pos.next();

        initial_pos.next();

        this->size_iterated_list++;

        this->nodes[this->firstFREE].elem = e;
        this->nodes[pos.index].next = this->firstFREE;
        this->nodes[this->firstFREE].next = initial_pos.index;

        this->firstFREE = newFirstEmpty;

        pos.next();
    }
}
//Complexity:
// BC = O(1), when we want to add after the head of the list
// AND
// WC = O(n), when we want to add at firstFREE
//n = no of nodes of the list

void IteratedList::addToEnd(TElem e)
{
    if (this->firstFREE == -1)
        resize();
    int position = this->firstFREE;
    this->firstFREE = this->nodes[this->firstFREE].next;
    this->nodes[position].elem = e;
    this->nodes[position].next = -1;

    if (this->size_iterated_list == 0)
        this->head = position;
    else
    {
        ListIterator pos = ListIterator(*this);
        for (int i = 0; i < this->size_iterated_list - 1; i++)
            pos.next();
        this->nodes[pos.index].next = position;
    }
    this->size_iterated_list++;
}
//Complexity: theta(n), where n = no of nodes of the list

IteratedList::~IteratedList()
{
    delete[] this->nodes;
}

void IteratedList::addToBeginning(TElem e)
{
    if (this->firstFREE == -1)
        resize();
    int position = this->firstFREE;
    this->firstFREE = this->nodes[position].next;
    this->nodes[position].elem = e;
    if (this->size_iterated_list == 0)
        this->nodes[position].next = -1;
    else
        this->nodes[position].next = this->head;

    this->head = position;
    this->size_iterated_list++;
}
//Complexity: theta(1)

void IteratedList::resize()
{
    this->cap = 2 * this->cap;
    SLLANode *nodes_storage = new SLLANode[this->cap];

    for (int i = 0; i < this->cap / 2; i++)
        nodes_storage[i] = this->nodes[i];

    for (int i = this->cap / 2; i < this->cap - 1; i++)
        nodes_storage[i].next = i + 1;

    nodes_storage[this->cap - 1].next = -1;

    this->firstFREE = this->cap / 2;

    delete[] this->nodes;
    this->nodes = nodes_storage;
}

int IteratedList::removeAll(IteratedList &list)
{
    int removed_elements = 0;
    ListIterator it = ListIterator(list);
    it.first();
    while (it.valid())
    {
        removed_elements++;
        remove(it);
        it.first();
    }

    return removed_elements;
}
