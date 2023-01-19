//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_DEFAULTIO_H
#define ASS4_DEFAULTIO_H

#include <string>

class DefaultIO {
public:
    std::string gotMessage = "ack";
    std::string sendAnswer = "done";
    std::string terminateClient = "terminate";

    virtual std::string read();

    virtual void write(std::string string);
};


#endif //ASS4_DEFAULTIO_H
