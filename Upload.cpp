//
// Created by asaf9 on 1/9/2023.
//
#include <string>
#include <utility>

#include "Upload.h"
#include "InputFile.h"

using namespace std;

void Upload::execute() {
    this->dio->write("Please upload your local train CSV file");
    this->dio->read();
    this->dio->write("done");
    std::string string = this->dio->read();
    InputFile inputfile;
    this->dio->write("Upload complete\nPlease upload your local test CSV file");
    this->dio->read();
    this->dio->write("done");
    this->data->classifiedFile = string;
    std::string string2 = this->dio->read();
    this->dio->write("Upload complete");
    this->dio->read();
    this->dio->write("done");
    this->data->unclassifiedFile = string2;

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
