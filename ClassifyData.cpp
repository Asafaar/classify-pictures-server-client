//
// Created by asaf9 on 1/9/2023.
//
#include "InputFile.h"
#include "ClassifyData.h"
#include "Data.h"
void Command::execute(){
    if (data->path->empty()){
        this->write("data upload please");
        exit(0);
    } else {
        InputFile inputFile;
        //need make 3
    }
}
ClassifyData::ClassifyData(Data* data) {
    this->description="classify data";
    this->data=data;
}
