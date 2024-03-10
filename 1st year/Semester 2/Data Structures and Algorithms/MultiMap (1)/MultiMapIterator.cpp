#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	if (col.isEmpty())
    {
        this->currentBucket = 0;
        this->current_pos_in_values = 0;
        this->current_node = nullptr;
    }
    else
    {
        this->currentBucket = 0;
        this->current_node = col.buckets[this->currentBucket];
        this->current_pos_in_values = 0;

        while (this->current_node == nullptr)
            this->current_node = col.buckets[this->currentBucket++];
    }
}

TElem MultiMapIterator::getCurrent() const{
    if (valid())
        return make_pair(this->current_node->key, this->current_node->getItem(this->current_pos_in_values));
    return NULL_TELEM;
}

bool MultiMapIterator::valid() const {
	return this->current_node != nullptr and this->current_pos_in_values < col.buckets[this->currentBucket]->getSize();
}

void MultiMapIterator::next() {
    if (!valid())
        throw std::exception();
    else
    {
        //if there are more values in the dynamic array, we move downwards in the dynamic array
        if (this->current_pos_in_values < this->current_node->getSize() - 1)
            this->current_pos_in_values++;
        else
        {
            //we have to move to the next node in the current sll
            //OR to the next non-empty sll

            if (this->current_node->next != nullptr) {
                this->current_node = this->current_node->next;
                this->current_pos_in_values = 0;
            }
            else
            {
                this->currentBucket++;
                this->current_node = col.buckets[this->currentBucket];
                this->current_pos_in_values = 0;

                while (!valid() and this->currentBucket < this->col.size())
                {
                    this->currentBucket++;
                    this->current_node = col.buckets[this->currentBucket];
                }
            }
        }
    }
}

void MultiMapIterator::first() {
    if (col.isEmpty())
    {
        this->currentBucket = 0;
        this->current_pos_in_values = 0;
        this->current_node = nullptr;
    }
    else
    {
        this->currentBucket = 0;
        this->current_node = col.buckets[this->currentBucket];
        this->current_pos_in_values = 0;

        while (this->current_node == nullptr)
            this->current_node = col.buckets[this->currentBucket++];
    }
}

