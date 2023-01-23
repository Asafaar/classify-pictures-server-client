/**
 * A class meant to send a vector of Vectors to the client.
 */
#include "SendClassifiedVectors.h"
#include "CLI.h"
#include <cstdio>
#include <unistd.h>
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>

/**
 * Send all the vectors through a given defaultIO.
 * @param data - The data to send.
 * @param dio - The DefaultIo to send the info through.
 * @param createFile - Flag to decide whether the client needs to create a file out of the info.
 */
void SendClassifiedVectors::sendVectors(Data *data, DefaultIO *dio, bool createFile) {
    // Not all info is valid
    if (data->classifiedFile.empty() or data->unclassifiedFile.empty()) {
        dio->write("Upload the data please.");
        dio->read();
        return;
    }
    // Data still isn't classified
    if (data->classificationVector->empty()) {
        dio->write("Classify the data please.");
        dio->read();
        return;
    }

    DefaultIO *currentDio = dio;
    // Get path for file
    if (createFile) {
        dio->write("Enter path");
        dio->read();
        dio->write(dio->sendAnswer);
        int d = functionsocket(12360);
        DefaultIO *dio2 = new SocketIO(d);
        currentDio = dio2;
    }
    // Send all the data
    int size = data->classificationVector->size();
    std::string classificationToSend;
    for (int i = 0; i < size - 1; i++) {
        currentDio->write(std::to_string(i + 1) + "  " + *(data->classificationVector->at(i)));
        currentDio->read();
        if (createFile) {
            currentDio->write("\n");
            currentDio->read();
        }
    }
    currentDio->write(std::to_string(size) + "  " + *(data->classificationVector->at(size - 1)));
    currentDio->read();

    // Let client know he needs to close the file.
    if (createFile) {
        currentDio->write(dio->sendAnswer);
        currentDio->read();
    }
}

int SendClassifiedVectors::functionsocket(int port) {
    if (listen(sockSendfile, 5) < 0) {
        perror("Error while listening to a socket");
    }
    // Allow new client connection
    struct sockaddr_in client_sin{};
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sockSendfile, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        perror("Invalid client socket number!");
    }
    return client_sock;
}