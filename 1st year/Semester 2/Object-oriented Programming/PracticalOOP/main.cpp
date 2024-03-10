#include <QApplication>
#include "ChatWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::string file_drivers = "D:/PracticalOOP/Drivers";
    std::string file_reports = "D:/PracticalOOP/Reports";
    ReportSession reportSession;
    reportSession.readDriversFromFile(file_drivers);
    reportSession.readReportsFromFile(file_reports);

    for (auto* driver: reportSession.getDrivers())
    {
        auto* window = new ChatWindow(driver, reportSession);
        window->setWindowTitle(QString::fromStdString(driver->toString()));
        window->show();
    }
    return QApplication::exec();
}
