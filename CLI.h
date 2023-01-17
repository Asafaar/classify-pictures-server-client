//
// Created by asaf9 on 1/17/2023.
//

#ifndef ASS4_CLI_H
#define ASS4_CLI_H
#include "Command.h"
#include "Data.h"
class CLI {
public:
    Data* data;
    Command *command[5]{};
    DefaultIO* defaultIo;
    CLI(Data* data, DefaultIO* defaultIo1);
    void start();
};


#endif //ASS4_CLI_H
