/**
 * Send the classified vectors to the user.
 */
#include "DisplayResults.h"
#include "SendClassifiedVectors.h"

DisplayResults::DisplayResults(Data *data,DefaultIO *defaultIo1) {
    this->description="display results";
    this->data=data;
    this->dio=defaultIo1;
}

void DisplayResults::execute() {
    SendClassifiedVectors sendClassifiedVectors;
    sendClassifiedVectors.sendVectors(this->data, this->dio, false);
}
