#include "service.h"
#include <string.h>
#include <stdlib.h>

service* createService(repository* repo){
    service* newService = malloc(sizeof (service));
    newService->repo = repo;
    return newService;
}

void destroyService(service* service){
    destroyRepository(service->repo);
    free(service);
}

int addMedicine_service(service* service, UndoRedoRepo* undoRedoRepo, char* name, int concentration, int quantity, float price){
    Medicine* newMedicine = createMedicine(name, concentration, quantity, price);
    addUndoOperation(undoRedoRepo, service->repo);
    return addMedicine(service->repo, newMedicine);
}

int deleteMedicine_service(service* service, UndoRedoRepo* undoRedoRepo, char* name, int concentration, int quantity, float price){
    Medicine* MedToDelete = createMedicine(name, concentration, quantity, price);
    addUndoOperation(undoRedoRepo, service->repo);
    return deleteMedicine(service->repo, MedToDelete);
}

int updateMedicine_service(service* service, UndoRedoRepo* undoRedoRepo, char* name, int concentration, int quantity, float price, char* new_name, int new_concentration, int new_quantity, float new_price){
    Medicine* medicine = createMedicine(name, concentration, quantity, price);
    Medicine* updatedMedicine = createMedicine(new_name, new_concentration, new_quantity, new_price);
    addUndoOperation(undoRedoRepo, service->repo);
    return updateMedicine(service->repo, medicine, updatedMedicine);
}

Medicine* medicineWithStringIncluded(service* service, char* string, int* size){
    if (strcmp(string, "null") == 0){
        *size = getSize(service->repo);
        return service->repo->data;
    }
    /*char *strstr(const char *haystack, const char *needle);
    * The strstr() function finds the first occurrence of the substring needle in the string haystack.
    * The terminating null bytes are not compared.
    * Return Value:
    These functions return a pointer to the beginning of the substring, or NULL if the substring is not found.*/

    Medicine* medicines = malloc(sizeof (Medicine) * 100);
    *size = 0;
    for (int i=0; i< getSize(service->repo); i++){
        if (strstr(getName(&service->repo->data[i]), string) !=NULL) {
            medicines[(*size)++] = service->repo->data[i];
        }
    }
    Medicine* aux = malloc(sizeof (Medicine));

    for (int i = 0; i< *size; i++)
        for (int j = i+1; j< *size; j++)
            if (strcmp(getName(&medicines[i]), getName(&medicines[j])) > 0) {
                *aux = medicines[i];
                medicines[i] = medicines[j];
                medicines[j] = *aux;
            }
    free(aux);

    return medicines;
}

Medicine* getAll_service(service* service, int* size){
    return getAll(service->repo, size);
}

Medicine* medicineShortSupply(service* service, int quantity, int* size){
    Medicine* medicines = malloc(sizeof (Medicine) * 100);
    for (int i=0; i< getSize(service->repo); i++){
        if (get_quantity(&service->repo->data[i]) < quantity){
            medicines[(*size)++] = service->repo->data[i];
        }
    }
    return medicines;
}

Medicine* generateMedicines_service(service* service){
    generateMedicines(service->repo);
}

int ServiceUNDO(UndoRedoRepo* undoRedoRepo, repository* repo){
    if (undoRedoRepo->undo_lenght == 0)
        return 1;
    addRedoOperation(undoRedoRepo, repo);
    popUndo(undoRedoRepo, repo);
    return 0;
}

int ServiceREDO(UndoRedoRepo* undoRedoRepo, repository* repo){
    if (undoRedoRepo->redo_lenght == 0)
        return 1;
    addUndoOperation(undoRedoRepo, repo);
    popRedo(undoRedoRepo, repo);
    return 0;
}