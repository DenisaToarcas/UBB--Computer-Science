#include "GUI.h"

Gui::Gui(Service& service, QWidget *parent): QMainWindow(parent), service{ service } {
    ui.setupUi(this);
}

void Gui::AdministratorMode() {
    Administrator administrator(this->service);
    administrator.exec();
}

void Gui::UserMode() {
    User user(this->service);
    user.exec();
}

Gui::~Gui() = default;
