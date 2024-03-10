#include "repository.h"
#include <stdlib.h>
#include <intrin.h>
#include <time.h>

repository* createRepository()
{
    repository* newRepo = malloc(sizeof (repository));
    newRepo->data = malloc(100 * sizeof (Medicine));
    newRepo->size = 0;
    return newRepo;
}

void destroyRepository(repository* repo)
{
    /*
    for (int i=0; i< repo->size; i++)
    {
        destroyMedicine(&repo->data[i]);
    }
     */
    free(repo->data);
    free(repo);
}

Medicine* getAll(repository* repo, int* size){
    *size = getSize(repo);
    return repo->data;
}

int getSize(const repository* repo){
    return repo->size;
}

int addMedicine(repository* repo, Medicine* newMedicine){
    int position;
    position = findMedicine(repo, newMedicine);
    if (position != -1){
        repo->data[position].quantity += newMedicine->quantity;
        return 1;
    }
    else
    {
        repo->data[repo->size] = *newMedicine;
        repo->size++;
    }

    return 0;
}

int findMedicine(repository* repo, Medicine* medicine){
    for (int i=0; i < repo->size; i++){
        if (strcmp(getName(medicine), getName(&repo->data[i])) == 0 && medicine->concentration == repo->data[i].concentration){
            return i;
        }
    }
    return -1;
}

int deleteMedicine(repository* repo, Medicine* medicine){
    int position = 0;
    position = findMedicine(repo, medicine);
    if (position == -1){
        return 1;
    }
    else{
        /*destroyMedicine(&repo->data[position]);*/
        repo->data[position] = repo->data[repo->size-1];
        /*destroyMedicine(&repo->data[repo->size-1]);*/
        repo->size--;
        return 0;
    }
}

int updateMedicine(repository* repo, Medicine* medicine, Medicine* updatedMedicine){
    int position = 0;
    position = findMedicine(repo, medicine);
    if (position == -1){
        return 1;
    }
    else{
        repo->data[position].name = getName(updatedMedicine);
        repo->data[position].concentration = get_concentration(updatedMedicine);
        repo->data[position].quantity = get_quantity(updatedMedicine);
        repo->data[position].price = get_price(updatedMedicine);
        return 0;
    }
}

Medicine* generateMedicines(repository* repo){
    char** vectorOfNames = malloc(sizeof (char*) * 10);
    for (int i=0; i< 10; i++){
        vectorOfNames[i] = malloc(sizeof (char) * 20);
    }
    strcpy(vectorOfNames[0], "algocalmin");
    strcpy(vectorOfNames[1], "paracetamol");
    strcpy(vectorOfNames[2], "coldrex");
    strcpy(vectorOfNames[3], "ventolin");
    strcpy(vectorOfNames[4], "nurofen");
    strcpy(vectorOfNames[5], "amoxicillin");
    strcpy(vectorOfNames[6], "atorvastatin");
    strcpy(vectorOfNames[7], "diclofenac");
    strcpy(vectorOfNames[8], "morphine");
    strcpy(vectorOfNames[9], "melatonin");

    int concentration;
    int quantity;
    float price;
    srand(time(NULL));

    for (int i=0; i< 10; i++){
        concentration = rand();
        quantity = rand();
        price = rand();

        Medicine* medicine = createMedicine(vectorOfNames[i], concentration, quantity, price);
        addMedicine(repo,medicine);
    }
    free(vectorOfNames);

}
