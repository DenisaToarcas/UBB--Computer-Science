#include "GUI.h"

Gui::Gui(Service& service, QWidget *parent): QMainWindow(parent), service { service } {
    ui.setupUi(this);

    this->populateList();
}

void Gui::populateList() {
    this->ui.TESTlistWidget->clear();

    std::vector<std::shared_ptr<HospitalDepartments>> allHospitals;

    allHospitals = this->service.getAllDepartments();

    for (auto& h: allHospitals) {
        this->ui.TESTlistWidget->addItem(QString::fromStdString(h->toString()));
    }
}

int Gui::getSelectedIndexes() const {
     QList<QModelIndex> selectedIndexes = this->ui.TESTlistWidget->selectionModel()->selectedIndexes();

     if (selectedIndexes.empty())
     {
         this->ui.HospitalLine->clear();
         this->ui.DoctorsLine->clear();
         this->ui.PatientsLine->clear();
         return -1;
     }

     int selectedIndex = selectedIndexes.at(0).row();
     return selectedIndex;
}

void Gui::AddHospital() {
    std::string hospitalName = this->ui.HospitalLine->text().toStdString();
    int doctors = this->ui.DoctorsLine->text().toInt();
    int patients = this->ui.PatientsLine->text().toInt();

    this->service.addDepartment(std::make_shared<Surgery>(hospitalName, doctors, patients));
    this->populateList();

    int lastElement = this->service.getAllDepartments().size() - 1;
    this->ui.TESTlistWidget->setCurrentRow(lastElement);

    this->ui.HospitalLine->clear();
    this->ui.DoctorsLine->clear();
    this->ui.PatientsLine->clear();
}
