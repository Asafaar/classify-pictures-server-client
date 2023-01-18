//
// Created by asaf9 on 1/9/2023.
//
#include <string.h>
#include <utility>
#include <iostream>
#include "Upload.h"
#include "InputFile.h"

using namespace std;

void Upload::execute() {
    this->dio->write("Please upload your local train CSV file");
    this->dio->read();
    this->dio->write("done");

    string temp, newLine = "";
    while (newLine != "done") {
        newLine = this->dio->read();
        temp += newLine;
        this->dio->write("got");
    }
    this->data->classifiedFile = temp;

    this->dio->write("Upload complete\nPlease upload your local test CSV file");
    this->dio->read();
    this->dio->write("done");
    temp = "", newLine = "";
    while (newLine != "done") {
        newLine = this->dio->read();
        temp += newLine;
        this->dio->write("got");
    }
    this->data->unclassifiedFile = temp;
    this->dio->write("Upload complete");
    this->dio->read();
}


Upload::Upload(Data *data, DefaultIO *defaultIo1) {
    this->description = "upload an unclassified csv data file";
    this->data = data;
    this->dio = defaultIo1;

}

void Upload::changepath(std::string path, std::string pathsort) {
//    this->data.path= static_cast<std::string *>(malloc(sizeof(path)));
//    this->data->path=&path;
//    this->data->pathsort=&pathsort;


}
