/**
 * A class meant to send a vector of Vectors to the client.
 */
#include "SendClassifiedVectors.h"
#include "mutex"
#include <thread>
#include "CLI.h"

std::mutex mtx;


void handle_client(Data *data, DefaultIO* defaultIo) {
    CLI cli = CLI(data, defaultIo);
    cli.start();
}

/**
 * Send all the vectors through a given defaultIO.
 * @param data - The data to send.
 * @param dio - The DefaultIo to send the info through.
 * @param createFile - Flag to decide whether the client needs to create a file out of the info.
 */
void SendClassifiedVectors::sendVectors(Data *data, DefaultIO *dio, bool createFile){
    // Not all info is valid
    if (data->classifiedFile.empty() or data->unclassifiedFile.empty()){
        dio->write("Upload the data please.");
        dio->read();
        return;
    }
    // Data still isn't classified
    if (data->classificationVector->empty()){
        dio->write("Classify the data please.");
        dio->read();
        return;
    }
    // Get path for file
    if (createFile) {
        //std::thread t(handle_client);
        //t.detach();
        //std::unique_lock<std::mutex> lock(mtx);
        dio->write("Enter path");
        dio->read();
        dio->write(dio->sendAnswer);
        std::string csvPathToWrite= dio->read();

        //dio->write("Sending data...");
        //dio->read();
        //dio->write(dio->sendAnswer);
        dio->write(csvPathToWrite);
        dio->read();
    }
/*
    int size = data->classificationVector->size();
    std::string classificationToSend;
    if (createFile) {
        std::vector<std::thread> threads;
        for (int i = 0; i < size; i++) {
            threads.emplace_back([dio, i, classification = data->classificationVector->at(i)](){
                dio->write(std::to_string(i + 1) + "  " + *classification);
                dio->read();
            });
        }
        for (std::thread& t : threads) {
            t.join();
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            dio->write(std::to_string(i + 1) + "  " + *(data->classificationVector->at(i)));
            dio->read();
        }
    }



*/
    // Send all the data
    int size=data->classificationVector->size();
    std::string classificationToSend;
    for (int i = 0; i < size - 1; i++){
        dio->write(std::to_string(i + 1)+"  "+ *(data->classificationVector->at(i)) + "\n");
        dio->read();
    }
    dio->write(std::to_string(size)+"  "+ *(data->classificationVector->at(size-1)));
    dio->read();

    // Let client know he needs to close the file.
    if (createFile) {
        dio->write(dio->sendAnswer);
        dio->read();
        //mtx.unlock();
    }
    dio->write("Done sending the vector Classifications.");
    dio->read();
}
