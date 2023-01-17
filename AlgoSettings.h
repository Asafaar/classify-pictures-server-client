//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_ALGOSETTINGS_H
#define ASS4_ALGOSETTINGS_H
#include "string.h"
#include "Command.h"
class AlgoSettings :public Command {
public:
    AlgoSettings(Data *data,DefaultIO *defaultIo1);
    void execute() override;
    bool IsAPositiveNumber(std::string* s);
    void stringToArray(std::string *arr[2], std::string s);
};


#endif //ASS4_ALGOSETTINGS_H
