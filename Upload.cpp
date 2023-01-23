#include "Upload.h"

using namespace std;

void Upload::execute() {
    this->dio->write("Please upload your local train CSV file");
    this->dio->read();
    this->dio->write(this->dio->sendAnswer);
    string temp, newLine;
    newLine = this->dio->read();
    while (newLine != this->dio->sendAnswer) {
        temp += newLine;
        this->dio->write(this->dio->gotMessage);
        newLine = this->dio->read();
    }
    //this->dio->write(this->dio->gotMessage);
    this->data->classifiedFile = temp;
    this->dio->write("Upload complete\nPlease upload your local test CSV file");
    this->dio->read();
    this->dio->write(this->dio->sendAnswer);
    temp = "";
    newLine = this->dio->read();
    while (newLine != this->dio->sendAnswer) {
        temp += newLine;
        this->dio->write(this->dio->gotMessage);
        newLine = this->dio->read();
    }
    //this->dio->write(this->dio->gotMessage);
    this->data->unclassifiedFile = temp;
    this->dio->write("Upload complete");
    this->dio->read();
}

Upload::Upload(Data *data, DefaultIO *defaultIo1) {
    this->description = "upload an unclassified csv data file";
    this->data = data;
    this->dio = defaultIo1;

}
