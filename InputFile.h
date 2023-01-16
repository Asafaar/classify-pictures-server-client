//
// Created by asaf9 on 12/3/2022.
//

#ifndef ASS2_KNN_INPUTFILE_H
#define ASS2_KNN_INPUTFILE_H
#include "string"
#include "Data.h"
#include <vector>
#include <list>
using namespace std;
struct VectorData {
    vector<long double> vectorV;
    string name;
    long double Length=0;
};
class InputFile {
public:
        bool kNumIsValid(int kNum);
        bool nameFileIsValid(const string& name_file);
        bool distanceIsValid(const string& distance);
        void LoadData(const string& filename,std::vector<VectorData*> *data);
        bool dataMainInputFromFile(std::vector<VectorData *> *data, int argc, string *argv[], int *knNumm,string *distancee);
        bool kCheckIfBiggerFromLengthOfData(int Length,int knNum);
        bool vectorsAreOfSameLengthBool(vector<long double> v1, vector<long double> v2);
        string readFile(const string &path);
        void LoadWithoutUserInput(vector<VectorData *> *data, int *knNum, string *distance);
         string* clientInputWork(char clientInput[], string filename, int clientInputSize);
         vector<long double> fromStringVectorToLongDouble(vector<string> stringvactor);
         string * InvalidInputString();
         bool CanreadFile(const string &path);
         bool IfKnumAndDistaneGood (const string &path,Data data);
         bool IfCsvPathToMakeValid(const string &path);
};

#endif //ASS2_KNN_INPUTFILE_H
