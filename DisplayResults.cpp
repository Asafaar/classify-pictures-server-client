//
// Created by asaf9 on 1/9/2023.
//

#include "DisplayResults.h"

DisplayResults::DisplayResults(Data *data,DefaultIO *defaultIo1) {
    this->description="display results";
    this->data=data;
    this->dio=defaultIo1;

}

void DisplayResults::execute() {
    if (data->classifiedFile.empty() or data->unclassifiedFile.empty()){
        this->dio->write("Upload the data please.");
        return;
    }
    if (data->classificationVector->empty()){
        this->dio->write("Classify the data please.");
        return;
    }

    int size=sizeof(data->classificationVector);
    for (int i = 0; i < size; i++){
        int j=i+1;
        std::string string1=j+"  "+ *(data->classificationVector->at(i));
        this->dio->write(string1);
    }
    this->dio->write("Done.");

}
