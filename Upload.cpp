//
// Created by asaf9 on 1/9/2023.
//
#include <string>
#include <utility>

#include "Upload.h"
#include "InputFile.h"
using namespace std;
 void Upload::execute()   {
     this->dio.write("Please upload your local train CSV file");
     std::string string=this->dio.read();
     InputFile inputfile;
     /*
     if (!inputfile.CanreadFile(string)){
         this->dio.write("input invalid");
         return;
     }
      */
     this->dio.write("Upload complete");
     this->data->classifiedFile=string;

     this->dio.write("Please upload your local test CSV file");
     std::string string2=this->dio.read();
     /*
     if (!inputfile.CanreadFile(string2)){
         this->dio.write("input invalid");
         return;
     }
      */
     this->dio.write("Upload complete");
     this->data->unclassifiedFile=string2;

}



Upload::Upload(Data* data) {
    this->description="upload an unclassified csv data file";
    this->data=data;

}
void Upload::changepath(std::string path, std::string pathsort) {
//    this->data.path= static_cast<std::string *>(malloc(sizeof(path)));
//    this->data->path=&path;
//    this->data->pathsort=&pathsort;


}
