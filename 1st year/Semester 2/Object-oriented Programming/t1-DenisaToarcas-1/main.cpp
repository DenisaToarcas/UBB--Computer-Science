#include "UI.h"
#include "Service.h"
#include "Repository.h"
#include "Domain.h"
#include <vector>

int main()
{
    std::vector<Woman>* women = new std::vector<Woman>(10);
    auto * repository = new Repository(women);
    auto * service = new Service(repository);
    auto * ui = new UI(service);

    ui->menu();
}