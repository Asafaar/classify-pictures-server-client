#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include "Server.h"
#include "InputFile.h"
#include "Command.h"
#include "CLI.h"
#include "SocketIO.h"
#include "DefaultIO.h"
#include "DisplayResults.h"
const string tempPort = "12346";
void handle_client(int client_socket){
    char clientInput[4096];
    int expected_data_len = sizeof(clientInput);
        memset(clientInput, '\0', 4096);
        Data data;
        SocketIO socketIO(client_socket);
        CLI cli = CLI(&data, &socketIO);
        cli.start();
    close(client_socket);
    }

using namespace std;
/**
 * The main func of the server.
 * Responsible for checking input, processing the clients requests and sending the
 * right classifications back to them.
 *
 * @param argc - the number of cmd args.
 * @param argv - the cmd args. Expected - file name & port number.
 * @return -1 if argv not right, otherwise continues to run.
 */
int main(int argc, char *argv[]) {
    //if (InputFromCommandIsInvalid(argc, argv)) {
    //get port number
    const int server_port = std::stoi(tempPort);
    InputFile inputFile;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Error while creating socket!");
    }

    //Create the socket struct
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);


    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    while (true) {
        if (listen(sock, 5) < 0) {
            perror("Error while listening to a socket");
        }
        // Allow new client connection
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("Invalid client socket number!");
        }
        std::thread t(handle_client, client_sock);
        t.detach();

    }
    // Infinite loop
    /*
    while (true) {
        if (listen(sock, 5) < 0) {
            perror("Error while listening to a socket");
        }
        // Allow new client connection
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("Invalid client socket number!");
        }
        char clientInput[4096];
        int expected_data_len = sizeof(clientInput);
        while (true) {
            memset(clientInput, '\0', 4096);
            //Get info from client
            int clientInputSize = recv(client_sock, clientInput, expected_data_len, 0);
            if (clientInputSize <= 0) {
                if (clientInputSize < 0) {
                    perror("Error - Negative input!");
                    continue;
                }
            }
            //Client wishes to disconnect
            if (strcmp(clientInput, "-1") == 0) {
                break;
            }
            //call function to check the input
            //return to client
            string *classification = inputFile.clientInputWork(clientInput, file, clientInputSize);
            string strObj(*classification);
            char *classificationToSend = &strObj[0];
            int dataLen = classification->size();
            //Send the classification to the client
            send(client_sock, classificationToSend, dataLen, 0);
        }

    }
     */

}

/**
 * InputFromCommandIsInvalid-check if the input in command line when start the server is ok
 *
 * @param argc need be 3, 1 default,1 for the address of the file,1 for the port
 * @param argv the input from the command line
 * @return if the argc is ok and the name of the file in the list then return true,else false
 */
bool InputFromCommandIsInvalid(int argc, char *argv[]) {
    if (argc == 3) {
        InputFile inputFile;
        char *file = argv[1];
        string stringTemp = file;
        stringTemp = stringTemp + ".csv";
        if (inputFile.nameFileIsValid(stringTemp)) {
            return true;
        }
    }
    return false;
}