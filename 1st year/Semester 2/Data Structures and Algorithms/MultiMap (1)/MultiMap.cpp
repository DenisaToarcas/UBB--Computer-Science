#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
    this->capacity = 10000;
    this->size_multimap = 0;
    this->buckets = new Node*[capacity];

    for (int i=0; i< this->capacity; i++)
        this->buckets[i] = nullptr;
}


void MultiMap::add(TKey c, TValue v) {
    int index = hash_function(c);
    Node* node_to_add = new Node(c);
    node_to_add->addElement(v);

    int i;

    for (i=0; i< this->capacity; i++)
    {
        if (this->buckets[i] == nullptr)
            break;
    }

    if (i == this->capacity)
        this->resize_multimap();

    if (this->buckets[index] == nullptr)
    {
        //here I add the first value associated with the key c
        buckets[index] = node_to_add;
    }
    else
    {
        Node* current_node = buckets[index];

        while (current_node != nullptr and current_node->key != c)
            current_node = current_node->next;

        if (current_node == nullptr)
        {
            //here I add a new node to the sll
            Node* previous_node = buckets[index];

            while (previous_node->next != current_node)
                previous_node = previous_node->next;

            previous_node->next = node_to_add;
        }
        else
            buckets[index]->addElement(v);
    }

    this->size_multimap++;
}


bool MultiMap::remove(TKey c, TValue v) {
	int index = hash_function(c);

    if (this->buckets[index] == nullptr)
        return false;
    else
    {
        Node* current_node = buckets[index];

        while (current_node != nullptr and current_node->key != c)
            current_node = current_node->next;

        if (current_node == nullptr)
            return false;
        else
        {
            for (int i=0; i < current_node->getSize(); i++)
                if (current_node->getItem(i) == v)
                {
                    current_node->removeElement(i);
                    this->size_multimap--;
                    return true;
                }

            return false;
        }
    }
}


vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> values_associated_with_key;

    int index = hash_function(c);

    if (this->buckets[index] == nullptr)
        return values_associated_with_key;

    else
    {
        Node* current_node = buckets[index];

        while (current_node != nullptr and current_node->key != c)
            current_node = current_node->next;

        if (current_node == nullptr)
            return values_associated_with_key;
        else
            if (current_node->key == c)
                {
                    for (int i=0; i < current_node->getSize(); i++)
                        values_associated_with_key.push_back(current_node->getItem(i));

                    return values_associated_with_key;
                }
    }
}


int MultiMap::size() const {
	return this->size_multimap;
}


bool MultiMap::isEmpty() const {
	return this->size() == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
    for (int i = 0; i < capacity; i++) {
        Node* current = buckets[i];
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    delete[] buckets;
}

