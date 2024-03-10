#pragma once
#include "domain.h"

typedef struct {
    Medicine* data;
    int size;
}repository;

repository* createRepository();

void destroyRepository(repository*);

Medicine* getAll(repository*, int*);

int getSize(const repository*);

int addMedicine(repository*, Medicine*);

int findMedicine(repository*, Medicine*);

int deleteMedicine(repository*, Medicine*);

int updateMedicine(repository*, Medicine*, Medicine*);

Medicine* generateMedicines(repository*);