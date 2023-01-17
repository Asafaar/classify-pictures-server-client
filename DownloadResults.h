//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_DOWNLOADRESULTS_H
#define ASS4_DOWNLOADRESULTS_H

#include "Command.h"
class DownloadResults: public Command {
public:
    DownloadResults(Data* data,DefaultIO *defaultIo1);
    void execute() override;

};


#endif //ASS4_DOWNLOADRESULTS_H
