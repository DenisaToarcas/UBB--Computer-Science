#include "ui_mainwindow.h"

class Test_prep: public QMainWindow
{
public:
    explicit Test_prep(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindow ui;
};

Test_prep::Test_prep(QWidget *parent): QMainWindow(parent) {
    ui.setupUi(this);
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Test_prep gui;
    gui.show();

    return QApplication::exec();
}
