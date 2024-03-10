#include "UndoRedo_Repo.h"
#include <stdlib.h>

UndoRedoRepo* createUndoRedoRepo(int capacity){
    UndoRedoRepo *undo_redo_repo = malloc(sizeof (UndoRedoRepo));
    undo_redo_repo->undo = (repository*) malloc(capacity * sizeof(repository));
    undo_redo_repo->redo = (repository*) malloc(capacity * sizeof(repository));
    undo_redo_repo->undo_lenght = 0;
    undo_redo_repo->redo_lenght = 0;
    undo_redo_repo->undo_capacity = capacity;
    undo_redo_repo->redo_capacity = capacity;

    return undo_redo_repo;
}

void destroyUndoRedoRepo(UndoRedoRepo* undo_redo_repo){
    int i;
    for (i=0; i< undo_redo_repo->undo_lenght; i++){
        free(undo_redo_repo->undo[i].data);     //deallocate the arrays in the undo
    }
    free(undo_redo_repo->undo);

    for (i=0; i< undo_redo_repo->redo_lenght; i++){
        free(undo_redo_repo->redo[i].data);     //deallocate the arrays in the redo
    }
    free(undo_redo_repo->redo);

    free(undo_redo_repo);
}

void addUndoOperation(UndoRedoRepo* undo_redo_repo, repository* repo){
    if (undo_redo_repo->undo_lenght == undo_redo_repo->undo_capacity){
        resizeUndo(undo_redo_repo);     //if the undo list is full, then resize it
    }

    //we allocate space for the medicines we want to copy
    undo_redo_repo->undo[undo_redo_repo->undo_lenght].data = (Medicine*) malloc(repo->size * sizeof(Medicine));

    //copy the medicines from the repo to the undo_redo_repo
    for (int i=0; i< repo->size; i++){
        undo_redo_repo->undo[undo_redo_repo->undo_lenght].data[i] = repo->data[i];
    }

    undo_redo_repo->undo[undo_redo_repo->undo_lenght].size = repo->size;
    undo_redo_repo->undo_lenght++;
}

void addRedoOperation(UndoRedoRepo* undo_redo_repo, repository* repo){
    if (undo_redo_repo->redo_lenght == undo_redo_repo->redo_capacity){
        resizeRedo(undo_redo_repo);     //if the redo list is full, then we resize it
    }

    //we allocate space for the medicines we want to copy
    undo_redo_repo->redo[undo_redo_repo->redo_lenght].data = (Medicine*) malloc(repo->size * sizeof(Medicine));

    //copy the medicines from the repo to the undo_redo_repo
    for (int i=0; i< repo->size; i++){
        undo_redo_repo->redo[undo_redo_repo->redo_lenght].data[i] = repo->data[i];
    }

    undo_redo_repo->redo[undo_redo_repo->redo_lenght].size = repo->size;
    undo_redo_repo->redo_lenght++;
}

void popUndo(UndoRedoRepo* undo_redo_repo, repository* repo) {
    if (undo_redo_repo->undo_lenght > 0) {
        //This function REPLACES the actual repo with the last undo_redo_repo->undo
        free(repo->data);

        repo->data = undo_redo_repo->undo[undo_redo_repo->undo_lenght - 1].data;
        repo->size = undo_redo_repo->undo[undo_redo_repo->undo_lenght - 1].size;

        //delete the last saved repo from the undo list

        repository *auxiliary;
        auxiliary = (repository *) malloc(undo_redo_repo->undo_capacity * sizeof(repository));

        for (int i = 0; i < undo_redo_repo->undo_lenght - 1; i++) {
            auxiliary[i] = undo_redo_repo->undo[i];
        }
        free(undo_redo_repo->undo);
        undo_redo_repo->undo = auxiliary;
        undo_redo_repo->undo_lenght--;
    }
}

void popRedo(UndoRedoRepo* undo_redo_repo, repository* repo){
    if (undo_redo_repo->redo_lenght > 0) {
        //This function REPLACES the actual repo with the last undo_redo_repo->repo
        free(repo->data);

        repo->data = undo_redo_repo->redo[undo_redo_repo->redo_lenght - 1].data;
        repo->size = undo_redo_repo->redo[undo_redo_repo->redo_lenght - 1].size;

        //delete the last saved repo from the undo list

        repository *auxiliary;
        auxiliary = (repository *) malloc(undo_redo_repo->redo_capacity * sizeof(repository));

        for (int i = 0; i < undo_redo_repo->redo_lenght - 1; i++) {
            auxiliary[i] = undo_redo_repo->redo[i];
        }
        free(undo_redo_repo->redo);
        undo_redo_repo->redo = auxiliary;
        undo_redo_repo->redo_lenght--;
    }
}

void resizeUndo(UndoRedoRepo* undo_redo_repo){
    repository* auxiliary;
    auxiliary = (repository*) malloc(2* undo_redo_repo->undo_capacity * sizeof(repository));

    for (int i=0; i< undo_redo_repo->undo_lenght; i++){
        auxiliary[i] = undo_redo_repo->undo[i];
    }

    free(undo_redo_repo->undo);
    undo_redo_repo->undo = auxiliary;
    undo_redo_repo->undo_capacity = 2* undo_redo_repo->undo_capacity;
}

void resizeRedo(UndoRedoRepo* undo_redo_repo){
    repository* auxiliary;
    auxiliary = (repository*) malloc(2* undo_redo_repo->redo_capacity * sizeof(repository));

    for (int i=0; i< undo_redo_repo->redo_lenght; i++){
        auxiliary[i] = undo_redo_repo->redo[i];
    }

    free(undo_redo_repo->redo);
    undo_redo_repo->redo = auxiliary;
    undo_redo_repo->redo_capacity = 2* undo_redo_repo->redo_capacity;
}
