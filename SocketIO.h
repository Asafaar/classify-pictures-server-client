//
// Created by asaf9 on 1/9/2023.
//

#ifndef ASS4_SOCKETIO_H
#define ASS4_SOCKETIO_H

#include "DefaultIO.h"

class SocketIO : public DefaultIO {
public:
    explicit SocketIO(int sockNum);

    std::string read() override;

    void write(std::string string) override;

private:
    int client_sock;
};


#endif //ASS4_SOCKETIO_H
