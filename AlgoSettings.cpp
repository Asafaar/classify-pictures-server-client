//
// Created by asaf9 on 1/9/2023.
//
#include "InputFile.h"
#include "AlgoSettings.h"
void Command::execute(){
    this->write("The current KNN parameters are:" + *(this->data->Knum)+ "distance mertic =" +*(this->data->dis) );
    std::string string=this->read();
    if (string.empty()){
        exit(1);
    }
    else{
        InputFile inputfile;

    }
}


AlgoSettings::AlgoSettings(Data *data) {
    this->description="algorithm settings";
    this->data=data;
}
