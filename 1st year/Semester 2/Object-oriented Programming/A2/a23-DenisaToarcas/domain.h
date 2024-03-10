#pragma once

typedef struct {
    char* name;
    int concentration;
    int quantity;
    float price;
}Medicine;

Medicine* createMedicine(char* name, int concentration, int quantity, float price);

void destroyMedicine(Medicine* medicine);

char* getName(Medicine*);

int get_concentration(Medicine*);

int get_quantity(Medicine*);

float get_price(Medicine*);

char* toString(Medicine*);