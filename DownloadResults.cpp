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
    if (data->classifiedFile->empty() or data->unclassifiedFile->empty()){
        this->dio.write("data upload please.");
        return;
    }
    if (data->classificationVector.empty()){
        this->dio.write("data the classify please.");
        return;
    }
    std::string csvPathToWrite= this->dio.read();
    InputFile inputFile;
    if (!inputFile.CanreadFile(csvPathToWrite)){
        this->dio.write("Invalid path");
        return;
    }
    std::ofstream file(csvPathToWrite);
    if (file.is_open()) {
        int size=sizeof(data->classificationVector);
        for (int i = 0; i < size; ++i){
            int j=i+1;
            string string1=j+"  "+ *(data->classificationVector.at(i));
            file << string1 << std::endl;}
    } else {
        this->dio.write("Failed to open file");
    }
    file.close();

}
