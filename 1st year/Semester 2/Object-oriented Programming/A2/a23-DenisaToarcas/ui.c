#include "ui.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

UI* createUI(service* service, UndoRedoRepo* undoRedoRepo){
    UI* newUi = malloc(sizeof (UI));
    newUi->service = service;
    newUi->undoRedoRepo = undoRedoRepo;
    return newUi;
}

void destroyUI(UI* ui){
    destroyService(ui->service);
    destroyUndoRedoRepo(ui->undoRedoRepo);
    free(ui);
}

void printMenu(){
    printf("\nMenu:\n");
    printf("\t1. Add a new medicine\n");
    printf("\t2. Display medicines with given string\n");
    printf("\t3. Delete a medicine\n");
    printf("\t4. Update medicine\n");
    printf("\t5. List all medicines\n");
    printf("\t6. Medicines in short supply\n");
    printf("\t7. UNDO\n");
    printf("\t8. REDO\n");
    printf("\t0. Exit\n");
}

void StartMenu(UI* ui){
    while(1){
        if (getSize(ui->service->repo) == 0){
            generateMedicines_service(ui->service);
        }
        printMenu();
        char option[2];
        printf("\nIntroduce your option here:");
        scanf("%s", option);

        if (strstr("012345678", option) == NULL || strlen(option) > 1)
        {
            while (strstr("01234578", option) == NULL){
                printf("Invalid option given!");
                printMenu();
            }
        }
        if (strcmp(option, "0") == 0){
            break;
        }
        switch (option[0]-48) {
            case 1:
            {
                char name[20];
                int concentration;
                int quantity;
                float price;
                printf("\nGive the info about the medicine:\n");
                scanf("%s %d %d %f", name, &concentration, &quantity, &price);

                int result = addMedicine_service(ui->service, ui->undoRedoRepo, name, concentration, quantity, price);
                if (result == 0){
                    printf("\nNew medicine added\n");
                }
                else
                    printf("\nQuantity of medicine %s increased by %d\n", name, quantity);
                break;
            }
            case 2: {
                char string[100];
                int size;
                printf("\nGive the string you want to match the medicines with or null to show all of them:\n");
                scanf("%s", string);
                Medicine *medicines = medicineWithStringIncluded(ui->service, string, &size);

                if (size == 0) {
                    printf("There were no medicines matching the %s string.", string);
                    break;
                } else {

                    for (int i = 0; i < size; i++) {
                        printf("%s\n", toString(&medicines[i]));
                    }
                    break;
                }
            }
            case 3:
            {
                char name[20];
                int concentration;
                int quantity = 0;
                float price = 0;

                printf("\nGive the name and concentration of the medicine:\n");
                scanf("%s %d", name, &concentration);

                int result = deleteMedicine_service(ui->service, ui->undoRedoRepo, name, concentration, quantity, price);
                if (result == 0){
                    printf("\nThe deletion was successful\n");
                }
                else
                    printf("\nThere was no medicine with given name and quantity\n");
                break;
            }
            case 4:
            {
                char initial_name[20];
                int initial_concentration;

                printf("\nGive the name and concentration of the medicine:\n");
                scanf("%s %d", initial_name, &initial_concentration);

                char name[20];
                int concentration;
                int quantity;
                float price;
                printf("\nGive the new info about the medicine:\n");
                scanf("%s %d %d %f", name, &concentration, &quantity, &price);

                int result;
                result = updateMedicine_service(ui->service, ui->undoRedoRepo, initial_name, initial_concentration, 0, 0, name,
                                                concentration, quantity, price);
                if (result == 0){
                    printf("\nThe update was successful\n");
                }
                else
                    printf("\nThere is no such medicine\n");
            }
            case 5:
            {
                int size;
                Medicine* medicines = getAll_service(ui->service, &size);
                if (size != 0) {
                    printf("\nThere are %d medicines stored\n", size);
                    printf("\nAll medicines are:\n");
                    for (int i = 0; i < size; i++)
                        printf("%s\n", toString(&medicines[i]));
                    break;
                }
                else {
                    printf("\nNo medicine added\n");
                    break;
                }
            }
            case 6:
            {
                /*char nr_items[10];*/
                int quantity = 0;
                printf("\nGive the minimum quantity for short supply:\n");
                /*scanf("%s", nr_items);
                if (strstr("0123456789", nr_items) == NULL || nr_items[0] == '0')
                {
                    while (strstr("0123456789", nr_items) == NULL)
                    {
                        printf("\nInvalid quantity given!\n");
                        printf("\nGive the minimum quantity for short supply:\n");
                        scanf("%s", nr_items);
                    }
                }

                int i = 0;
                while (i != strlen(nr_items)){
                    quantity = quantity * 10 + (nr_items[i] - 48);
                }
                printf("%d", quantity);
                 */
                scanf("%d", &quantity);

                int size = 0;

                Medicine* medicines = medicineShortSupply(ui->service, quantity, &size);

                if (size == 0) {
                    printf("\nThere were no medicines on short supply.\n");
                    break;
                } else {
                    int i;

                    for (i = 0; i < size; i++) {
                        printf("%s\n", toString(&medicines[i]));
                    }
                    break;
                }
                case 7:{
                    int valid;
                    valid = ServiceUNDO(ui->undoRedoRepo, ui->service->repo);
                    if (valid == 1){
                        printf("\nNo UNDO available!\n");
                        break;
                    }
                    else{
                        printf("\nUndo successful!\n");
                        break;
                    }
                }
                case 8:{
                    int valid;
                    valid = ServiceREDO(ui->undoRedoRepo, ui->service->repo);
                    if (valid == 1){
                        printf("\nNo REDO available!\n");
                        break;
                    }
                    else{
                        printf("\nRedo successful!\n");
                        break;
                    }
                }
            }
            default:
                break;
        }
    }
}