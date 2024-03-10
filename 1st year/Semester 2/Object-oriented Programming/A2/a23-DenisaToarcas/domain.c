#include "domain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Medicine* createMedicine(char* name, int concentration, int quantity, float price)
{
    Medicine* new_medicine = malloc(sizeof(Medicine));
    if (new_medicine == NULL)
        return NULL;

    new_medicine->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(new_medicine->name, name);
    new_medicine->concentration = concentration;
    new_medicine->quantity = quantity;
    new_medicine->price = price;

    return new_medicine;
}

void destroyMedicine(Medicine* medicine)
{
    if (medicine == NULL)
        return;
    free(medicine->name);
    free(medicine);
}

char* getName(Medicine* medicine)
{
    return medicine->name;
}

int get_concentration(Medicine* medicine)
{
    return medicine->concentration;
}

int get_quantity(Medicine* medicine)
{
    return medicine->quantity;
}

float get_price(Medicine* medicine)
{
    return medicine->price;
}

char* toString(Medicine* medicine)
{
    char* str = (char*) malloc(100 * sizeof(char));
    sprintf(str, "%s %d %d %f", medicine->name, medicine->concentration, medicine->quantity, medicine->price);
    return str;
}

