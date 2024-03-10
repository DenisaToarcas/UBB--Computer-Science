#pragma once
#include "repository.h"
#include "UndoRedo_Repo.h"

typedef struct {
    repository* repo;
}service;

service* createService(repository*);

void destroyService(service*);

int addMedicine_service(service*, UndoRedoRepo*, char*, int, int, float);

int deleteMedicine_service(service*, UndoRedoRepo*, char*, int, int, float);

int updateMedicine_service(service*, UndoRedoRepo*, char*, int, int, float, char*, int, int, float);

Medicine* medicineWithStringIncluded(service*, char*, int*);

Medicine* getAll_service(service*, int*);

Medicine* medicineShortSupply(service*, int, int*);

Medicine* generateMedicines_service(service*);

int ServiceUNDO(UndoRedoRepo*, repository*);

int ServiceREDO(UndoRedoRepo*, repository*);