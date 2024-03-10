#pragma once
#include "service.h"
#include "UndoRedo_Repo.h"

typedef struct {
    service* service;
    UndoRedoRepo* undoRedoRepo;
}UI;

UI* createUI(service*, UndoRedoRepo*);

void destroyUI(UI*);

void StartMenu(UI*);