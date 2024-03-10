#pragma once
#include<vector>
#include<utility>
#include <math.h>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
class MultiMapIterator;

//I create a DynamicArray class for the second element of the pair
//The multimap stores a pair formed out of a key and a dynamic array
//of the values associated with that key

//and also the hashtable will be a dynamic array

class DynamicArray
{
private:
    int capacity;
    int size;
    TValue* values;

public:
    DynamicArray(){
        //constructor of the dynamic array
        this->capacity = 10;
        this->size = 0;
        this->values = new TValue[capacity];
    }

    DynamicArray(const DynamicArray& array_to_copy) {
        //copy constructor for the resizing part
        this->size = array_to_copy.size;
        this->capacity = array_to_copy.capacity;
        this->values = new TValue[this->capacity];

        for (int i = 0; i < this->size; i++) {
            this->values[i] = array_to_copy.values[i];
        }
    }


    int getSize() const {
        return this->size;
    }

    TValue getItem(int index) const{
        return this->values[index];
    }

    void addElement(const TValue& value){
        if (this->capacity == this->size)
            this->resize();
        this->values[this->size] = value;
        this->size++;
    }

    void removeElement(int index){
        for (int i=index; i<this->size-1; i++)
            this->values[i] = this->values[i+1];

        this->size--;
    }

    ~DynamicArray() {
        delete[] this->values;
    }

private:
    void resize(){
        this->capacity *= 2;
        auto* aux = new TValue[this->capacity];
        for (int i=0; i< this->size; i++)
            aux[i] = this->values[i];

        delete[] this->values;
        this->values = aux;
    }
};

//I created a new type of element:
//TPairs -> contains a key and a dynamic array of all the associated
//values to that key
typedef std::pair<TKey, DynamicArray> TPairs;


class Node
{
public:
    TPairs pair;
    Node* next;

    Node(TKey key, const DynamicArray& array){
        this->pair.first = key;
        this->pair.second = array;
        this->next = nullptr;
    }

    Node(const Node& node_to_copy){
        this->pair = node_to_copy.pair;
        this->next = node_to_copy.next;
    }

    ~Node() = default;
};

class SLL_of_nodes
{
private:
    Node* head;

public:
    SLL_of_nodes(){
        this->head = nullptr;
    }

    SLL_of_nodes(const SLL_of_nodes& sll_to_copy) {
        this->head = nullptr;

        if (sll_to_copy.head != nullptr) {
            this->head = new Node(sll_to_copy.head->pair.first, sll_to_copy.head->pair.second);

            Node* current_node = this->head;
            Node* current_node_to_copy = sll_to_copy.head->next;

            while (current_node_to_copy != nullptr) {
                Node* new_node = new Node(current_node_to_copy->pair.first, current_node_to_copy->pair.second);
                current_node->next = new_node;

                current_node = current_node->next;
                current_node_to_copy = current_node_to_copy->next;
            }
        }
    }

    ~SLL_of_nodes() {
        Node *current = this->head;
        while (current != nullptr) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    bool isEmpty() const{
        return this->head == nullptr;
    }

    //When wanting to add a new pair TKey key and TValue value to a sll
    //First we check if the sll is empty
    //If is empty, this means that this is the first node in the sll
    //Else, we check to see if there is a node having the same key as the one
    //we want to add
    //If so, we "append" the dynamic array
    //Otherwise, we have to add as head the new node created

    void add_to_sll(TKey key, TValue value){
        if (this->isEmpty())
        {
            auto* array = new DynamicArray();
            array->addElement(value);

            this->head = new Node(key, *array);
        }
        else
        {
            Node* current_node = this->head;

            bool found = false;

            while (current_node != nullptr and !found){
                if (key == current_node->pair.first) {
                    current_node->pair.second.addElement(value);
                    found = true;
                }

                else
                    current_node = current_node->next;
                }

            if (current_node == nullptr and found == false) {
                auto* array = new DynamicArray();
                array->addElement(value);

                Node* new_node = new Node(key, *array);

                new_node->next = this->head;
                this->head = new_node;
            }
        }
    }

    //When removing, we first check if the current sll is empty
    //If empty, return false -> no removing was done
    //Else, we check if there is a node having the same key as the
    //one of the pair we want to remove
    //If there is no node, we also return false
    //If we find a node having the same key, we search for the associated value
    //If found, we remove the pair

    bool remove_from_sll(TKey key, TValue value){
        if (this->isEmpty())
            return false;
        else
        {
            Node* current_node = this->head;

            while (current_node != nullptr and current_node->pair.first != key)
                current_node = current_node->next;

            if (current_node == nullptr)
                return false;
            else
            {
                bool removed = false;

                for (int i=0; i < current_node->pair.second.getSize(); i++)
                    if (current_node->pair.second.getItem(i) == value) {
                        current_node->pair.second.removeElement(i);
                        removed = true;
                        break;
                    }

                if (current_node->pair.second.getSize() == 0)
                {
                    //if we removed the last value from the dynamic array of values
                    //related to that key, we also have to remove this node
                    //node_after = is the next node after the current one
                    //node_before = is the previous node of the current one

                    Node* node_after = current_node->next;

                    Node* node_before = this->head;

                    while (node_before->next != current_node)
                        node_before = node_before->next;

                    node_before->next = node_after;
                }

                return removed;
            }
        }
    }

    vector<TValue> searchKey_in_sll(const TKey& key){
        vector<TValue> values_associated_with_key;

        if (this->head == nullptr) {
            return values_associated_with_key;
        }

        else
        {
            Node* current_node = this->head;

            while (current_node != nullptr and current_node->pair.first != key)
                current_node = current_node->next;

            if (current_node == nullptr)
                return values_associated_with_key;
            else
            {
                for (int i = 0; i < current_node->pair.second.getSize(); i++)
                    values_associated_with_key.push_back(current_node->pair.second.getItem(i));

                return  values_associated_with_key;
            }
        }
    }

   Node* get_head(){
        return this->head;
    }
};

class DynamicArray_of_slls {
private:
    int capacity;
    int size;
    SLL_of_nodes* slls;

public:
    DynamicArray_of_slls() {
        //constructor of the dynamic array
        this->capacity = 10;
        this->size = 0;
        this->slls = new SLL_of_nodes[capacity];
    }

    DynamicArray_of_slls(const DynamicArray_of_slls &sll_to_copy) {
        //copy constructor for the resizing part
        this->size = sll_to_copy.size;
        this->capacity = sll_to_copy.capacity;
        this->slls = new SLL_of_nodes[this->capacity];

        for (int i = 0; i < this->size; i++) {
            this->slls[i] = sll_to_copy.slls[i];
        }
    }

    ~DynamicArray_of_slls() {
        delete[] this->slls;
    }

    int getSize() const {
        return this->size;
    }

    int hash_function(const TKey& key) const{
        return abs(key) % this->capacity;
    }
    //add and remove a pair of key and value from the hashtable

    //RESIZE NOT NEDEED YET

    void addPair(const TKey& key, const TValue& value){
        int index = hash_function(key);

        this->slls[index].add_to_sll(key, value);
        this->size++;
    }

    bool removePair(const TKey& key, const TValue& value){
        int index = hash_function(key);

        bool removed = this->slls[index].remove_from_sll(key, value);

        if (removed)
            this->size--;

        return removed;
    }

    vector<TValue> searchKey(const TKey& key){
        int index = hash_function(key);

        return this->slls[index].searchKey_in_sll(key);
    }

    Node* get_head(int index){
        return this->slls[index].get_head();
    }

private:
    void resize() {
        this->capacity *= 2;
        auto *aux = new SLL_of_nodes[this->capacity];
        for (int i = 0; i < this->size; i++)
            aux[i] = this->slls[i];

        delete[] this->slls;
        this->slls = aux;
    }
};

class MultiMap
{
	friend class MultiMapIterator;

private:
    DynamicArray_of_slls* multimap;

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

