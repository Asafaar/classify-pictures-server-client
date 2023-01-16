//
// Created by asaf9 on 1/9/2023.
//
#include "Upload.h"
#include "Command.h"
#include "DownloadResults.h"
#include "ClassifyData.h"
#include <iostream>
#include "DisplayResults.h"
#include "AlgoSettings.h"
using std::cout;
int main(){
    Data data;
    Upload upload(&data);
    AlgoSettings algoSettings(&data);
    DisplayResults displayResults(&data);
    DownloadResults downloadResults(&data);
    ClassifyData classifyData(&data);
    Command command[5]={upload,algoSettings,classifyData,displayResults,downloadResults};
    upload.execute();
//    upload.changepath("asdf","asdfssss");
//    cout <<classifyData.pathsort+classifyData.path<<std::endl;


}