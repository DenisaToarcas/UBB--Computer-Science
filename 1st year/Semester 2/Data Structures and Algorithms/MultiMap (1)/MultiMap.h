#pragma once
#include<vector>
#include<utility>
#include <cmath>
#include <iostream>

//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
class MultiMapIterator;

struct Node
{
    TKey key;
    TValue* values;
    int capacity_node;
    int size_node;
    Node* next;

    explicit Node(const TKey& key){
        this->key = key;
        this->capacity_node = 10;
        this->size_node = 0;
        this->values = new TValue[capacity_node];
        this->next = nullptr;
    }

    Node(const Node& node_to_copy){
        this->key = node_to_copy.key;
        this->capacity_node = node_to_copy.capacity_node;
        this->size_node = node_to_copy.size_node;
        this->values = node_to_copy.values;
        this->next = node_to_copy.next;
    }

    ~Node(){
        delete[] this->values;
    }

    int getSize() const{
        return this->size_node;
    }

    TValue getItem(int index) const{
        return this->values[index];
    }

    void addElement(const TValue& value){
        if (this->capacity_node == this->size_node)
            this->resize();
        this->values[this->size_node] = value;
        this->size_node++;
    }

    void removeElement(int index){
        for (int i=index; i<this->size_node-1; i++)
            this->values[i] = this->values[i+1];

        this->size_node--;
    }

    void resize(){
        this->capacity_node *= 2;
        auto* aux = new TValue[this->capacity_node];
        for (int i=0; i< this->size_node; i++)
            aux[i] = this->values[i];

        delete[] this->values;
        this->values = aux;
    }
};

class MultiMap
{
	friend class MultiMapIterator;

private:
	int capacity;
    int size_multimap;
    Node** buckets;

    int hash_function(const TKey& key) const{
        return abs(key) % this->capacity;
    }

    void resize_multimap(){
        this->capacity = 2*this->capacity;
        Node** new_data = new Node*[this->capacity];
        for (int j=0; j<this->capacity; j++)
            new_data[j] = nullptr;

        for (int i=0; i < this->capacity / 2; i++)
        {
            while(this->buckets[i] != nullptr) {
                //here I parse the current sll until the last valid node
                //this->buckets[i]->next is a pointer to the current node from my sll at index i

                int new_index = hash_function(this->buckets[i]->key);
                std::cout<<new_index<<" "<<this->buckets[i]->key<<std::endl;

                if (new_data[new_index] == nullptr) {
                    std::cout<<this->buckets[i]->key<<std::endl;
                    //here I add the first node in the new sll
                    new_data[new_index] = this->buckets[i];
                    new_data[new_index]->next = nullptr;
                }
                else
                {
                    std::cout<<"upsie "<<this->buckets[i]->key<<std::endl;
                    //here I already have some nodes at the index new_index in the new_data (the new sll created)
                    //previous node is the last valid node from new_data
                    Node* previous_node = new_data[new_index];
                    while (previous_node->next != nullptr)
                        previous_node = previous_node->next;

                    //I link the next of the last valid node added in new_data to the current_node in the sll
                    //then I link the new added node with nullptr
                    previous_node->next = this->buckets[i];
                    previous_node = previous_node->next;
                    previous_node->next = nullptr;
                }

                this->buckets[i] = this->buckets[i]->next;
            }
        }

        delete[] this->buckets;
        this->buckets = new_data;
    }

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//destructor
	~MultiMap();


};

