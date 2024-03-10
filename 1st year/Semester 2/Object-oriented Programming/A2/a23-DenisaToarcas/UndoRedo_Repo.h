#pragma once
#include "repository.h"

typedef struct {
    repository *undo;
    repository *redo;
    int undo_lenght;
    int redo_lenght;
    int undo_capacity;
    int redo_capacity;
}UndoRedoRepo;

UndoRedoRepo* createUndoRedoRepo(int);

void destroyUndoRedoRepo(UndoRedoRepo*);

void addUndoOperation(UndoRedoRepo*, repository*);

void addRedoOperation(UndoRedoRepo*, repository*);

void popUndo(UndoRedoRepo*, repository*);

void popRedo(UndoRedoRepo*, repository*);

void resizeUndo(UndoRedoRepo*);

void resizeRedo(UndoRedoRepo*);