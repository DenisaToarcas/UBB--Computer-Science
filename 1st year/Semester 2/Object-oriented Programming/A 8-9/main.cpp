#include <QApplication>
#include "Service/Service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto * dynamicVector = new std::vector<Tutorial>;
    auto * dynamicVector1 = new std::vector<Tutorial>;
    auto * dynamicVector2 = new std::vector<Tutorial>;
    Repository repo(dynamicVector);

    auto repository = std::make_shared<Repository>(repo);
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Message", "Do you want to work with CSV?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        CSVRepository CSV_repo(dynamicVector1, dynamicVector2, "D:/@SEM 2/OOP/a89-DenisaToarcas/CSVfile.csv");
        auto user_repo = std::make_shared<CSVRepository>(CSV_repo);

        auto validator = std::make_shared<Validator>();

        std::string filename = "D:/@SEM 2/OOP/a89-DenisaToarcas/test.txt";
        auto service = new Service(repository, user_repo, filename, validator);
        service->loadTutorialsFromFile();

        QUrl link_url = QUrl::fromUserInput(QString::fromStdString("D:/@SEM 2/OOP/a89-DenisaToarcas/CSVfile.csv"));
        QDesktopServices::openUrl(link_url);

        Gui gui(*service);
        gui.show();

        return QApplication::exec();
    }
    else {
        HTMLRepository HTML_repo(dynamicVector1, dynamicVector2, "D:/@SEM 2/OOP/a89-DenisaToarcas/HTMLfile.html");
        auto user_repo = std::make_shared<HTMLRepository>(HTML_repo);

        auto validator = std::make_shared<Validator>();

        std::string filename = "D:/@SEM 2/OOP/a89-DenisaToarcas/test.txt";
        auto service = new Service(repository, user_repo, filename, validator);
        service->loadTutorialsFromFile();

        QUrl link_url = QUrl::fromUserInput(QString::fromStdString("D:/@SEM 2/OOP/a89-DenisaToarcas/HTMLfile.html"));
        QDesktopServices::openUrl(link_url);

        Gui gui(*service);
        gui.show();

        return QApplication::exec();
    }
}
