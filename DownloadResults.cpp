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
    this->dio->write(this->dio->sendAnswer);
    std::string csvPathToWrite= this->dio->read();

    int size=sizeof(data->classificationVector);
    std::string string1;
    for (int i = 0; i < size; i++){
        int j=i+1;
        string1+=std::to_string(j)+"  "+ *(data->classificationVector->at(i))+"\n";
    }
    //I send get data to enter the loop in the client,the csvPathToWrite is tha path that the user want to save the datas
    this->dio->write("get data");
    this->dio->read();
    this->dio->write(this->dio->sendAnswer);
    this->dio->write(csvPathToWrite);
    this->dio->read();
    std::istringstream buffer(string1);
    string temp;
    while (std::getline(buffer, temp,'\n')){
        this->dio->write(temp);
        this->dio->read();
    }
    this->dio->write(this->dio->sendAnswer);

}
