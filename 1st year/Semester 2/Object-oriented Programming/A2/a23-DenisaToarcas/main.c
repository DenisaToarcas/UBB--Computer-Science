#include "repository.h"
#include "service.h"
#include "ui.h"
#include "UndoRedo_Repo.h"
#include <crtdbg.h>
#include "Tests.h"

int main()
{
    test_addMedicine();
    test_findMedicine();
    test_deleteMedicine();
    test_updateMedicine();
    repository* repo = createRepository();
    service* service = createService(repo);
    UndoRedoRepo* undoRedoRepo = createUndoRedoRepo(10);
    UI* ui = createUI(service, undoRedoRepo);

    StartMenu(ui);

    destroyUI(ui);

    _CrtDumpMemoryLeaks();
    return 0;
}