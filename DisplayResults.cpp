//
// Created by asaf9 on 1/9/2023.
//

#include "DisplayResults.h"

DisplayResults::DisplayResults(Data *data) {
    this->description="display results";
    this->data=data;

}

void DisplayResults::execute() {
    if (data->classifiedFile->empty() or data->unclassifiedFile->empty()){
        this->dio.write("data upload please.");
        exit(1);
    }
    if (data->classificationVector.empty()){
        this->dio.write("data the classify please.");
        exit(1);
    }

    int size=sizeof(data->classificationVector);
    for (int i = 0; i < size; ++i){
        int j=i+1;
        std::string string1=j+"  "+ *(data->classificationVector.at(i))+"\n";
        this->dio.write(string1);
    }
    this->dio.write("Done.");

}
