/**
 * A command class in charge of sending the vector classifications
 * to the client so he can create a file out of them.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "DownloadResults.h"
#include "InputFile.h"
#include "SendClassifiedVectors.h"

#include <string>

/**
 * Constructor for the class.
 * @param data - Basic data class.
 * @param defaultIo1 - A *defaultIo to send and receive input.
 */
DownloadResults::DownloadResults(Data* data,DefaultIO *defaultIo1) {
    this->description="download results";
    this->data=data;
    this->dio=defaultIo1;

}

/**
 * Send the data to the client.
 */
void DownloadResults::execute() {
    SendClassifiedVectors sendClassifiedVectors;
    sendClassifiedVectors.sendVectors(this->data, this->dio, true);
}
