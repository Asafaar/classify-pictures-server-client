//
// Created by asaf9 on 1/9/2023.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "DownloadResults.h"
#include "InputFile.h"

#include <string>

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
    this->dio->write("Enter path");
    this->dio->read();
    this->dio->write("done");
    std::string csvPathToWrite= this->dio->read();
//    InputFile inputFile;
//    if (!inputFile.CanReadFile(csvPathToWrite)){
//        this->dio->write("Invalid path");
//        this->dio->read();
//        return;
//    }
//    std::ofstream file(csvPathToWrite);
    int size=sizeof(data->classificationVector);
    std::string string1;
    for (int i = 0; i < size; i++){
        int j=i+1;
        string1+=std::to_string(j)+"  "+ *(data->classificationVector->at(i))+"\n";
    }
    //I send get data to enter the loop in the client,the csvPathToWrite is tha path that the user want to save the datas
    this->dio->write("get data");
    this->dio->write(csvPathToWrite);
    std::istringstream buffer(string1);
    string temp;
    while (std::getline(buffer, temp,'\n')){
        this->dio->write(string1);
        this->dio->read();
    }

}
