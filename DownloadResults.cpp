//
// Created by asaf9 on 1/9/2023.
//

#include <fstream>
#include "DownloadResults.h"
#include "InputFile.h"
DownloadResults::DownloadResults(Data* data,DefaultIO *defaultIo1) {
    this->description="download results";
    this->data=data;
    this->dio=defaultIo1;

}

void DownloadResults::execute() {
    if (data->classifiedFile.empty() or data->unclassifiedFile.empty()){
        this->dio->write("Upload the data please.");
        this->dio->read();
        return;
    }
    if (data->classificationVector->empty()){
        this->dio->write("Classify the data please.");
        this->dio->read();
        return;
    }
    std::string csvPathToWrite= this->dio->read();
    InputFile inputFile;
    if (!inputFile.CanReadFile(csvPathToWrite)){
        this->dio->write("Invalid path");
        this->dio->read();
        return;
    }
    std::ofstream file(csvPathToWrite);
    if (file.is_open()) {
        int size=sizeof(data->classificationVector);
        for (int i = 0; i < size; ++i){
            int j=i+1;
            string string1=j+"  "+ *(data->classificationVector->at(i));
            file << string1 << std::endl;}
    } else {
        this->dio->write("Failed to open file");
        this->dio->read();
    }
    file.close();

}
