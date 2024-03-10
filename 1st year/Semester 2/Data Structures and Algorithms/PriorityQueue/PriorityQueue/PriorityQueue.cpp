#include "PriorityQueue.h"
#include <exception>
using namespace std;


PriorityQueue::PriorityQueue(Relation r) {
	this->r = r;
	this->head = nullptr;
	this->tail = nullptr;

}


void PriorityQueue::push(TElem e, TPriority p) {
    Node* new_node = new Node(e, p);

    if (this->isEmpty()) {
        this->head = new_node;
        this->tail = new_node;
    }
    else {
        Node* current_node = this->tail;

        while (current_node != nullptr && !this->r(current_node->element.second, p)) {
            current_node = current_node->prev;
        }

        if (current_node == nullptr) {
            new_node->next = this->head;
            this->head->prev = new_node;
            this->head = new_node;
        }
        else {
            new_node->next = current_node->next;

            if (current_node->next != nullptr) {
                current_node->next->prev = new_node;
            }
            else {
                this->tail = new_node;
            }

            current_node->next = new_node;
            new_node->prev = current_node;
        }
    }
}
//complexity push()= O(size)

//throws exception if the queue is empty
Element PriorityQueue::top() const {
	if (this->isEmpty())
		throw std::exception();
	else
		return this->head->element;
}
//complexity top()= theta(1)

Element PriorityQueue::pop() {
	if (this->isEmpty())
		throw std::exception();
	else {
		Node* node = head;
		Element data = head->element;

		head = head->next;

		if (head != nullptr) {
			//we have not removed the last element
			head->prev = nullptr;
			//we create a new head for the queue
		}
		else
			this->tail = nullptr;

		delete node;
		return data;
	}
}
//complexity pop()= theta(1)

bool PriorityQueue::isEmpty() const {
	return this->head == nullptr;
}
//complexity isEmpty()= theta(1)

PriorityQueue::~PriorityQueue() {
    Node* current_node = this->head;

    while (current_node != nullptr) {
        current_node = current_node->next;
        delete this->head;
        //current_node->prev = nullptr;
        this->head = current_node;
    }
}

TPriority PriorityQueue::priorityOf(TElem elem) const {
    Node* current_node = this->head;

    while (current_node != nullptr)
    {
        if (current_node->element.first == elem)
            return current_node->element.second;
        current_node = current_node->next;
    }
    return -1;
};
//complexity O(size)
//best case = elem is the head of the priority queue => O(1)
//worst case = elem is not part of the list OR elem is the tail of the list => O(size)