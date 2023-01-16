//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_DISPLAYRESULTS_H
#define ASS4_DISPLAYRESULTS_H

#include "Command.h"
class DisplayResults: public Command {
public:
    DisplayResults(Data* data);
    void execute() override;

};


#endif //ASS4_DISPLAYRESULTS_H
