//
// Created by asaf9 on 1/9/2023.
//
#include <fstream>
#include "InputFile.h"
#include "ClassifyData.h"
#include "Data.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <list>
#include "KnnClassification.h"

void ClassifyData::execute() {
    if (data->classifiedFile.empty() || data->unclassifiedFile.empty()) {
        this->dio.write("Upload the data please");
        return;
    } else {
        InputFile inputFile;
        auto *classifiedVector = new std::vector<VectorData *>;
        auto vectorToClassify = new std::vector<vector<long double> *>;
        inputFile.LoadData(this->data->classifiedFile, classifiedVector);
        string file_contents;
        char delimiter = ',';
        ifstream ifs(this->data->unclassifiedFile);
        file_contents = inputFile.readFile(this->data->unclassifiedFile);
        std::istringstream buffer(file_contents);
        std::string token;
        // split the csv file by \n
        while (std::getline(buffer, token, '\n')) {
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
            for (int i = 0; i < sizeofl; ++i) {
                long double temp2 = std::stod(listTemp.front());
                listTemp.pop_front();
                singleUnclassifiedVector->push_back(temp2);
            }
            vectorToClassify->push_back(singleUnclassifiedVector);
        }
        for (vector<long double> *vec: *vectorToClassify) {
            this->data->classificationVector.push_back(knn(classifiedVector, *vec, this->data->dis, stoi(this->data->Knum)));
        }

    }
}


ClassifyData::ClassifyData(Data *data) {
    this->description = "classify data";
    this->data = data;
}
