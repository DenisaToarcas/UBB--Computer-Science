#pragma once
#include "Tutorial.h"

typedef Tutorial TElem;
template <typename TElem>

class DynamicVector
{
private:
    int capacity;
    int size;
    TElem* data;

public:
    explicit DynamicVector(int capacity = 10);
    DynamicVector(const DynamicVector&);
    ~DynamicVector();
    int getSize() const;
    TElem getItem(int index) const;
    void addItem(const TElem& element);
    void removeItem(int index);
    void updateItem(int index, TElem& element);
    TElem* getItems();
    DynamicVector& operator=(const DynamicVector&);

private:
    void resize();
};