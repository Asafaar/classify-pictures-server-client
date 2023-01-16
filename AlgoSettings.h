//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_ALGOSETTINGS_H
#define ASS4_ALGOSETTINGS_H

#include "Command.h"
class AlgoSettings :public Command {
public:
    AlgoSettings(Data* data);
    void execute() override;
};


#endif //ASS4_ALGOSETTINGS_H
