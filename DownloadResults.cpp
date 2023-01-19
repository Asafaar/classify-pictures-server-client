/**
 * A command class in charge of sending the vector classifications
 * to the client so he can create a file out of them.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "DownloadResults.h"
#include "InputFile.h"

#include <string>

/**
 * Constructor for the class.
 * @param data - Basic data class.
 * @param defaultIo1 - A *defaultIo to send and receive input.
 */
DownloadResults::DownloadResults(Data* data,DefaultIO *defaultIo1) {
    this->description="download results";
    this->data=data;
    this->dio=defaultIo1;

}

/**
 * Send the data to the client.
 */
void DownloadResults::execute() {
    // Client didn't upload files yet
    if (data->classifiedFile.empty() or data->unclassifiedFile.empty()){
        this->dio->write("Upload the data please.");
        this->dio->read();
        return;
    }
    // Client didn't classify the data yet
    if (data->classificationVector->empty()){
        this->dio->write("Classify the data please.");
        this->dio->read();
        return;
    }
    // Get the file path
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
