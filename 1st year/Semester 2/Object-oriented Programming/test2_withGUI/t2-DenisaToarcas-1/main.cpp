#include <QApplication>
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Service service;
    std::shared_ptr<Surgery> surgery1;
    std::string HospitalName = "Hospital1";
    int noDoctors1 = 10;
    int noPatients1 = 12;
    surgery1 = std::make_shared<Surgery>(HospitalName, noDoctors1, noPatients1);

    std::shared_ptr<Surgery> surgery2;
    int noDoctors2 = 11;
    int noPatients2 = 2;
    surgery2 = std::make_shared<Surgery>(HospitalName, noDoctors2, noPatients2);

    std::shared_ptr<Surgery> surgery3;
    int noDoctors3 = 13;
    int noPatients3 = 21;
    surgery3 = std::make_shared<Surgery>(HospitalName, noDoctors3, noPatients3);

    service.addDepartment(surgery1);
    service.addDepartment(surgery2);
    service.addDepartment(surgery3);

    Gui gui{service};
    gui.show();

    return QApplication::exec();
}
