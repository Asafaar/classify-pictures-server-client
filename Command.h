//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_COMMAND_H
#define ASS4_COMMAND_H

#include "DefaultIO.h"
#include "Data.h"

class Command :DefaultIO {
public:
        std::string  description;
        DefaultIO dio;
        Data* data;
       virtual void execute();

};


#endif //ASS4_COMMAND_H
