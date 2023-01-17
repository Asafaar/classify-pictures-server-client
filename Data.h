//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_DATA_H
#define ASS4_DATA_H

#include <vector>
#include "string"

class Data {
public:
    std::string classifiedFile;
    std::string unclassifiedFile;
    std::string Knum = "15";
    std::string dis = "AUC";
    std::vector<std::string *>* classificationVector=new std::vector<std::string * >;
};


#endif //ASS4_DATA_H
