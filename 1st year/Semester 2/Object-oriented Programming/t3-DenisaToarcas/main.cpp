#include <QApplication>
#include "GUI.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Service service;
    service.read_from_file();

    GUI gui{service};
    gui.show();

    return QApplication::exec();
}