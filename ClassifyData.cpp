/**
 * This class classifies the data using algorithms in the knn class.
 * The params for classifications are defined in AlgoSettings.
 */
#include <fstream>
#include "InputFile.h"
#include "ClassifyData.h"
#include "Data.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <list>
#include "KnnClassification.h"

/**
 * Run the classification algorithm on every unclassified vector.
 */
void ClassifyData::execute() {
    // Some input wasn't received from the client
    if (data->classifiedFile.empty() || data->unclassifiedFile.empty()) {
        this->dio->write("Upload the data please");
        this->dio->read();
        return;
    } else {
        InputFile inputFile;
        auto *classifiedVector = new std::vector<VectorData *>;
        auto vectorToClassify = new std::vector<vector<long double> *>;
        inputFile.LoadDataFromString(this->data->classifiedFile, classifiedVector);
        char delimiter = ',';
        std::istringstream buffer(this->data->unclassifiedFile);
        std::string token;
        // split the csv file by \n
        while (std::getline(buffer, token, '\r')) {
            string temp;
            std::stringstream ss(token);
            auto *singleUnclassifiedVector = new std::vector<long double>;
            std::list<string> listTemp;
            // split row by  "," and enter one the temp list
            while (std::getline(ss, temp, delimiter)) {
                listTemp.push_back(temp);

            }
            // make for loop,enter the num in the list to vectorV and the name in the
            // end loop to name field
            int sizeofl = listTemp.size();
            for (int i = 0; i < sizeofl; i++) {
                long double temp2 = std::stod(listTemp.front());
                listTemp.pop_front();
                singleUnclassifiedVector->push_back(temp2);
            }
            vectorToClassify->push_back(singleUnclassifiedVector);
        }
        this->data->classificationVector = new std::vector<std::string * >;
        bool test=TestUnit(stoi(this->data->Knum),classifiedVector,vectorToClassify);
        if(test){
        int d=vectorToClassify->size();
        for (int i = 0; i <d ; i++) {

            this->data->classificationVector->push_back(knn(classifiedVector, *vectorToClassify->at(i), this->data->dis, stoi(this->data->Knum)));
        }
    } else{
        this->dio->write("The vectors are not of the same size or knum is too big");
        this->dio->read();
        return;}
    }
}
bool ClassifyData::TestUnit(int knum,vector<VectorData*> *classifiedVec,   std::vector<vector<long double> *> *unclassifiedVec){
    InputFile inputFile;
    int sizeofclassifed=classifiedVec->size();
    int SizeOfTheClassifiedVector=classifiedVec->at(0)->vectorV.size();

    bool TheKnumIsValid1=inputFile.kCheckIfBiggerFromLengthOfData(sizeofclassifed,knum);
    int sizeVectorToClassify=unclassifiedVec->size();
    bool TheVectorsValid= true;
    for (int i = 0; i < sizeVectorToClassify; ++i) {
        if (unclassifiedVec->at(i)->size()!=SizeOfTheClassifiedVector){
            TheVectorsValid= false;
        }
    }
    if (!TheKnumIsValid1 && TheVectorsValid){
        return true;
    } else return false;



}
/**
 * Constructor for the class.
 * @param data - Basic data class.
 * @param defaultIo1 - A *defaultIo to send and receive input.
 */
ClassifyData::ClassifyData(Data *data,DefaultIO *defaultIo1) {
    this->description = "classify data";
    this->data = data;
    this->dio=defaultIo1;
}
