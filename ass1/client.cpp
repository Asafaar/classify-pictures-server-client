#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        const char *ip_address = argv [0];
        const int port_no = stoi(argv [1]);
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) { perror("error creating socket"); }
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr(ip_address);
        sin.sin_port = htons(port_no);
        if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { perror("error connecting to server"); }
        while (true) {
            string inputline;
            getline(cin, inputline);
            char* data_addr;
            string str_obj(inputline);
            data_addr = &str_obj[0];
            int data_len = inputline.size();
            int sent_bytes = send(sock, data_addr, data_len, 0);
            if (sent_bytes < 0) {// error
            }
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {// connection is closed
            } else if (read_bytes < 0) {
                //error
            } else if (buffer[0] == -1) {
                close(sock);
                return 0;
            } else { cout << buffer; }
        }
    } else {
        cout << "invalid input";
        return -1;
    }
}

