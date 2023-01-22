//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_CLASSIFYDATA_H
#define ASS4_CLASSIFYDATA_H

#include "Command.h"
#include "Data.h"
#include <vector>
#include "InputFile.h"
class ClassifyData:public Command {
public:
    ClassifyData(Data* data,DefaultIO *defaultIo1);
    void execute() override;
    bool TestUnit(int knum,vector<VectorData*> *classifiedVec, vector<vector<long double> *> *unclassifiedVec);
};


#endif //ASS4_CLASSIFYDATA_H
