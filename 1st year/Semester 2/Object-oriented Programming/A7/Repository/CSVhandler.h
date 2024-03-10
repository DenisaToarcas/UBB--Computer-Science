#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "userRepo.h"

class CSVRepository: public userRepo
{
//private:
    //std::string fileName;
public:
    explicit CSVRepository(std::vector<Tutorial>* watchList, std::vector<Tutorial>* tutorials_same_presenter, const std::string& userFilename);
    ~CSVRepository();

    unsigned long long getSizeWatchList() const override;
    void addTutorialWatchList(const Tutorial& tutorial) override;
    void deleteTutorialWatchList(long long index) override;
    long long findTutorialWatchList(std::string& title) override;
    Tutorial getTutorialWatchList(long long index) override;
    std::vector<Tutorial>* getTutorialsUSER() override;

    void addTutorialPresenter(const Tutorial& tutorial) override;
    unsigned long long getSizePresenter() override;
    void deleteTutorialPresenter(long long index) override;
    Tutorial getTutorialPresenter(long long index) override;
    std::vector<Tutorial>* getTutorialsPresenter() override;
    void writeWatchListToFile() override;
    std::string& getFileName() override;
};