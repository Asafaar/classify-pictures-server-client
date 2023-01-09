//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_UPLOAD_H
#define ASS4_UPLOAD_H

#include "Command.h"
#include "Data.h"

class Upload :public virtual Command {
public:
     Upload(Data* data);
     void changepath(std::string path, std::string pathsort);
};


#endif //ASS4_UPLOAD_H
