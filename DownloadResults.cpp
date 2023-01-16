//
// Created by asaf9 on 1/9/2023.
//

#include <fstream>
#include "DownloadResults.h"
#include "InputFile.h"
DownloadResults::DownloadResults(Data* data) {
    this->description="download results";
    this->data=data;

}

void DownloadResults::execute() {
    if (data->path->empty() or data->pathsort->empty()){
        this->dio.write("data upload please.");
        exit(1);
    }
    if (data.sortvectrs.empty){
        this->dio.write("data the classify please.");
        exit(1);
    }
    std::string csvPathToWrite= this->dio.read();
    InputFile inputFile;
    if (!inputFile.CanreadFile(csvPathToWrite)){
        this->dio.write("Invalid path");
        exit(1);
    }
    std::ofstream file(csvPathToWrite);
    if (file.is_open()) {
        for (int i = 0; i < sizeof(data.sortvecotr); ++i)
            file << "enter the vlaue" << std::endl;
    } else {
        this->dio.write("Failed to open file");
    }
    file.close();

}
