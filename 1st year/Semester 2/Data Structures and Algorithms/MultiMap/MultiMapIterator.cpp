#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    if (col.isEmpty()) {
        this->currentSLLIndex = 0;
        this->current_node = nullptr;
        this->currentDynamicArrayIndex = 0;
    } else {
        this->currentSLLIndex = 0;
        this->currentDynamicArrayIndex = 0;
        this->current_node = col.multimap->get_head(this->currentSLLIndex);

        while (!valid()) {
            this->currentSLLIndex++;
            this->current_node = col.multimap->get_head(this->currentSLLIndex);
            this->currentDynamicArrayIndex = 0;
        }
    }
}

TElem MultiMapIterator::getCurrent() const{
	if (valid())
        return make_pair(current_node->pair.first, current_node->pair.second.getItem(currentDynamicArrayIndex));
    return NULL_TELEM;
}

bool MultiMapIterator::valid() const {
    //the iterator is valid if the node it is pointing to is not null
    //and also if the index in the dynamic array (the ones stored as part of the pairs in the nodes) is not out of range
	return this->current_node != nullptr and this->currentDynamicArrayIndex < current_node->pair.second.getSize() and this->currentSLLIndex < 10;
}

void MultiMapIterator::next() {
    if (!valid())
        throw exception();

    if (this->currentDynamicArrayIndex < current_node->pair.second.getSize())
        //if there are more values in the dynamic array, we move downwards in the dynamic array
        this->currentDynamicArrayIndex++;
    else
    {
        //we have to move to the next node in the current sll
        //OR to the next non-empty sll
        if (this->current_node->next != nullptr) {
            this->current_node = this->current_node->next;
            this->currentDynamicArrayIndex = 0;
        }
        else
        {
            this->currentSLLIndex++;
            this->current_node = col.multimap->get_head(this->currentSLLIndex);
            this->currentDynamicArrayIndex = 0;

            while (!valid())
            {
                this->currentSLLIndex++;
                this->current_node = col.multimap->get_head(this->currentSLLIndex);
                this->currentDynamicArrayIndex = 0;
            }

            if (this->currentSLLIndex == 9) {
                this->current_node = nullptr;
                this->currentDynamicArrayIndex = 0;
            }
        }
    }
}

void MultiMapIterator::first() {
    if (col.isEmpty()) {
        this->currentSLLIndex = 0;
        this->current_node = nullptr;
        this->currentDynamicArrayIndex = 0;
    } else {
        this->currentSLLIndex = 0;
        this->currentDynamicArrayIndex = 0;
        this->current_node = col.multimap->get_head(this->currentSLLIndex);

        while (!valid()) {
            this->currentSLLIndex++;
            this->current_node = col.multimap->get_head(this->currentSLLIndex);
            this->currentDynamicArrayIndex = 0;
        }
    }
}


