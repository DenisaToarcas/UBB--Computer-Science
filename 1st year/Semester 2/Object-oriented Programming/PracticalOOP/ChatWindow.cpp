#include "ChatWindow.h"
#include <QMessageBox>

ChatWindow::ChatWindow(Driver *driver1, ReportSession &reportSession1, QWidget *parent): QWidget(parent), driver(driver1), reportSession(reportSession1)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(driver->toString()));
    this->reportSession.AddObserver(this);
    this->update();
}

ChatWindow::~ChatWindow() {
    this->reportSession.WriteToFile();
    this->reportSession.DeleteObserver(this);
}

void ChatWindow::update() {
    this->ui.ReportListWidget->clear();

    int lat_driver=0;
    std::string latitude_driver = this->driver->getLatitude();
    for (int i = 0; i< latitude_driver.size(); i++)
        lat_driver=lat_driver*10+ (latitude_driver[i]-48);

    int lon_driver=0;
    std::string longitude_driver = this->driver->getLongitude();
    for (int i=0; i< longitude_driver.size(); i++)
        lon_driver=lon_driver*10+ (longitude_driver[i]-48);

    for (auto report: this->reportSession.getReports())
    {
        int lat=0;
        std::string latitude = report->getLatitude();
        for (int i = 0; i< latitude.size(); i++)
            lat=lat*10+ (latitude[i]-48);
        int lon=0;
        std::string longitude = report->getLongitude();
        for (int i=0; i< longitude.size(); i++)
            lon=lon*10+ (longitude[i]-48);

        if (lat <lat_driver + 10 and lon < lon_driver + 10)
        {
            auto* item= new QListWidgetItem(QString::fromStdString(report->toString()));
//            if (report->getStatus() == "true" || report->getStatus() == "True")
//                item->setFont(QFont::Bold);
            this->ui.ReportListWidget->addItem(item);
        }

        if (this->reportSession.getMessages().size() != 0)
        {
            for (auto msg: this->reportSession.getMessages())
            {
                auto* msgItem = new QListWidgetItem(QString::fromStdString(msg));
                this->ui.ReportListWidget->addItem(msgItem);
            }
        }
    }
}


void ChatWindow::SendMessage() {
    std::string message = this->ui.MessageLIneEdit->text().toStdString();
    std::string sender_name = this->driver->getName();
    message = message + " " + sender_name;

    this->reportSession.AddMessage(message);
    this->ui.MessageLIneEdit->clear();
}

void ChatWindow::AddReport() {
    std::string description = this->ui.DescriptionLineEdit->text().toStdString();
    std::string latitude = this->ui.LatitudeLineEdit->text().toStdString();
    std::string longitude = this->ui.LongitudeLineEdit->text().toStdString();
    std::string reporter = this->driver->getName();
    auto pair = std::pair<std::string, std::string>(latitude, longitude);
    std::string status = "true";

    int lat_driver=0;
    std::string latitude_driver = this->driver->getLatitude();
    for (int i = 0; i< latitude_driver.size(); i++)
        lat_driver=lat_driver*10+ (latitude_driver[i]-48);

    int lon_driver=0;
    std::string longitude_driver = this->driver->getLongitude();
    for (int i=0; i< longitude_driver.size(); i++)
        lon_driver=lon_driver*10+ (longitude_driver[i]-48);

    int lat=0;
    for (int i = 0; i< latitude.size(); i++)
        lat=lat*10+ (latitude[i]-48);
    int lon=0;
    for (int i=0; i< longitude.size(); i++)
        lon=lon*10+ (longitude[i]-48);

    if (description.empty() || lat > lat_driver + 20 || lon > lon_driver + 20)
    {
        QMessageBox::critical(nullptr, "Exception", "Cannot add this report!");
    }
    else
    {
        auto* report = new Report(description, reporter, pair, status);
        this->reportSession.AddReport(report);
    }

    this->ui.DescriptionLineEdit->clear();
    this->ui.LatitudeLineEdit->clear();
    this->ui.LongitudeLineEdit->clear();
}
