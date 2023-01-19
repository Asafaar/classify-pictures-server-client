#include "DisplayResults.h"

DisplayResults::DisplayResults(Data *data,DefaultIO *defaultIo1) {
    this->description="display results";
    this->data=data;
    this->dio=defaultIo1;

}

void DisplayResults::execute() {
    if (data->classifiedFile.empty() or data->unclassifiedFile.empty()){
        this->dio->write("Upload the data please.");
        this->dio->read();
        return;
    }
    if (data->classificationVector->empty()){
        this->dio->write("Classify the data please.");
        this->dio->read();
        return;
    }

    int size=sizeof(data->classificationVector);
    std::string string1;
    for (int i = 0; i < size; i++){
        int j=i+1;
        string1+=std::to_string(j)+"  "+ *(data->classificationVector->at(i))+"\n";

    }
    this->dio->write(string1);
    this->dio->read();
}
