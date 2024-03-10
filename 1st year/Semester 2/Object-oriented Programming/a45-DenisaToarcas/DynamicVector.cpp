#include "DynamicVector.h"

template <typename TElem>
DynamicVector<TElem>::DynamicVector(int capacity) {
    //parameter constructor
    //params - capacity -> the capacity of the DynamicVector
    this->capacity = capacity;
    this->size = 0;
    this->data = new TElem[capacity];
}

template <typename TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector &VectorToCopy) {
    //copy constructor
    this->size = VectorToCopy.size;
    this->capacity = VectorToCopy.capacity;
    this->data = new TElem[this->capacity];

    for (int i = 0; i< this->size; i++){
        this->data[i] = VectorToCopy.data[i];
    }
}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector() {
    delete[] this->data;
}

template <typename TElem>
int DynamicVector<TElem>::getSize() const {
    return this->size;
}

template <typename TElem>
TElem DynamicVector<TElem>::getItem(int index) const {
    return this->data[index];
}

template <typename TElem>
void DynamicVector<TElem>::addItem(const TElem &element) {
    if (this->capacity == this->size)
        this->resize();
    this->data[this->size] = element;
    this->size++;
}

template <typename TElem>
void DynamicVector<TElem>::removeItem(int index) {
    for (int i=index; i<this->size-1; i++)
        this->data[i] = this->data[i+1];

    this->size--;
}

template <typename TElem>
void DynamicVector<TElem>::updateItem(int index, TElem &element) {
    this->data[index] = element;
}

template <typename TElem>
TElem *DynamicVector<TElem>::getItems() {
    return this->data;
}

template <typename TElem>
DynamicVector<TElem> &DynamicVector<TElem>::operator=(const DynamicVector & DynamicVector) {
    if(&DynamicVector == this)
        return *this;

    this->size = DynamicVector.size;
    this->capacity =DynamicVector.capacity;

    delete[] this->data;

    this->data = new TElem[this->capacity];
    for (int i=0; i< this->size; i++){
        this->data[i] = DynamicVector.data[i];
    }
    return *this;
}

template <typename TElem>
void DynamicVector<TElem>::resize() {
    this->capacity *= 2;
    auto* aux = new TElem[this->capacity];
    for (int i=0; i< this->size; i++)
        aux[i] = this->data[i];

    delete[] this->data;
    this->data = aux;
}

template class DynamicVector<Tutorial>;
