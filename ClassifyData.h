//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_CLASSIFYDATA_H
#define ASS4_CLASSIFYDATA_H

#include "Command.h"
#include "Data.h"

class ClassifyData:public Command {
public:
    ClassifyData(Data* data);
    void execute() override;

};


#endif //ASS4_CLASSIFYDATA_H
