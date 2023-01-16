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
    std::string Knum = "5";
    std::string dis = "EUC";
    std::vector<std::string *> classificationVector;
};


#endif //ASS4_DATA_H
