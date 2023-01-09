#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include "InputFile.h"
#include "KnnClassification.h"
#include "ass1/Geometry.h"
#include <regex>
using namespace std;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ostringstream;
using std::istringstream;

/** readfile
 *  check if can open the file to string, if can't find the file print error and exit from the program.
 *
 *  @param-const string &path-the path of the file
 *  @return-the string after check
 */
string InputFile::readFile(const string &path) {
    ifstream myFile(path);
    string line;
    string data;
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            data += line + "\n";
        }
        myFile.close();
    }
    return data;
}

bool InputFile::IfKnumAndDistaneGood (const string &path,Data data){

}

bool InputFile::CanreadFile(const string &path) {
    ifstream myFile(path);
    string line;
    string data;
    if (myFile.is_open()) {
        myFile.close();
        return true;
    } else return false;
}

/**kNumIsValid
 * check if the k num if input user is bigger than 0.
 *
 * @param- k-num the user enter in commend line.
 * @return-if the knNum is smaller from knum return false else return true.
 */
bool InputFile::kNumIsValid(int knNum) {
    if (knNum <= 0) {
        return false;
    } else { return true; }

}

/** nameFileIsValid
 * Check if the input name of the file that need to load is valid.
 *
 * @param-nameFile-the name file the user enter in commend line.
 * @return-if the nameFile in options return true else return false.
 */
bool InputFile::nameFileIsValid(const string &nameFile) {
    list<string> distanceOption;
    distanceOption.emplace_back("beans_Classified.csv");
    distanceOption.emplace_back("iris_classified.csv");
    distanceOption.emplace_back("wine_Classified.csv");
    bool valid_d = false;
    while (!distanceOption.empty()) {
        string temp = distanceOption.front();
        if (temp == nameFile) {
            valid_d = true;
        }
        distanceOption.pop_front();

    }
    return valid_d;


}

/**distanceIsValid
 *  check if the user enter valid distance function
 *
 *  @param-distance-the name file the user enter in commend line.
 *  @return-if the distance in options return true else return false.
 */
bool InputFile::distanceIsValid(const string &distance) {
    list<string> distanceOption;
    distanceOption.emplace_back("AUC");
    distanceOption.emplace_back("MAN");
    distanceOption.emplace_back("CHB");
    distanceOption.emplace_back("CAN");
    distanceOption.emplace_back("MIN");
    bool valid_d = false;
    while (!distanceOption.empty()) {
        if (distanceOption.front() == distance) {
            valid_d = true;
        }
        distanceOption.pop_front();
    }
    return valid_d;


}

/** LoadData
 * get the file path and enter each row on csv file to data structure named VectorData:
 *
 * struct VectorData:
 *   @param-vector<long double> vectorV;--> enter the vector in the data file
 *   @param-string name;--> enter the classified of the vector
 *   @param-long double Length=0; -->Default value
 */
void InputFile::LoadData(const string &filePath, std::vector<VectorData *> *data) {
    string file_contents;
    char delimiter = ',';
    ifstream ifs(filePath);
    file_contents = readFile(filePath);
    std::istringstream buffer(file_contents);
    std::string token;
    // split the csv file by \n
    while (std::getline(buffer, token, '\n')) {
        string temp;
        std::stringstream ss(token);
        auto *NewVactorData = new VectorData;
        std::list<string> listTemp;
        // split row by  "," and enter one the temp list
        while (std::getline(ss, temp, delimiter)) {
            listTemp.push_back(temp);

        }
        // make for loop,enter the num in the list to vectorV and the name in the
        // end loop to name field
        int sizeofl = listTemp.size();
        for (int i = 0; i < sizeofl; ++i) {
            if (sizeofl - 1 > i) {
                long double temp2 = std::stod(listTemp.front());
                listTemp.pop_front();
                NewVactorData->vectorV.push_back(temp2);
            } else {
                NewVactorData->name = listTemp.front();
            }
        }
        // enter to the main data
        data->push_back(NewVactorData);
    }
}

/** kCheckIfBiggerFromLengthOfData
 * check if the number of vectors from the csv file is smaller than k-num, if k-num is bigger
 * than return true, else, false.
 *
 * @param-Length-number of vectors from the csv file
 * @param-knNum-the k-num from commend line
 * @return if the knum is bigger return true else return false
 */
bool InputFile::kCheckIfBiggerFromLengthOfData(int Length, int knNum) {
    if (knNum > Length) {
        return true;
    } else return false;
}

/**dataMainInputFromFile
 * check if the input is valid make the path to the file location and load the file to data.
 *
 * @param std::vector<VectorData*> *data-pointer to the main data of the program
 * @param argc-the num of params input of the commend line
 * @param *argv[]-the params from commend line
 * @param-*knNumm-pointer to where knum will save after the checks
 * @param-*distance-pointer to where distancee will save after the checks
 */
bool InputFile::dataMainInputFromFile(std::vector<VectorData *> *data, int argc, string *argv[], int *knNumm,string *distancee) {
    try {
    if (argc == 4) {
        int knNum = stoi(*argv[0]);
        string nameFile = *argv[1];
        string distance = *argv[2];
        bool kCheck = kNumIsValid(knNum);
        bool nameFileCheck = nameFileIsValid(nameFile);
        bool distanceCheck = distanceIsValid(distance);
        if (kCheck and nameFileCheck and distanceCheck) {
            string namePath = "files/" + nameFile;
            // for debug in clion need ..//files//
            LoadData(namePath, data);
            *knNumm = knNum;
            *distancee = distance;
            return true;
        } else {
            cout << "Invalid input" << endl;
            return false;
        }


    } else {
        cout << "Invalid input" << endl;
        return false;
    }}
    catch(exception &err){
        cout << "Invalid input" << endl;
        return false;
    }
}

/**LoadWithoutUserInput
 * load the user input without user input,this function for developers.
 *
 * @param-namePath- the file you want to upload
 * @param-knNum- the k in the input
 * @param-distance- the  function distance
 *
 */
void InputFile::LoadWithoutUserInput(std::vector<VectorData *> *data, int *knNum, string *distance) {
    string name_file1 = "iris_classified.csv";
    string name_file2 = "wine_Classified.csv";
    string name_file3 = "beans_Classified.csv";
    string namePath = "..//" + name_file1;
    LoadData(namePath, data);
    *knNum = 5;
    *distance = "MAN";

}
/**
 * fromStringVectorToLongDouble-take the vectors from string format fo long double format
 * @param stringVector the input vector
 * @return if the vector is good return the vector in long double format other return empty vector
 */
vector<long double> InputFile::fromStringVectorToLongDouble(vector<string> stringVector) {
    vector<long double> vector;
    if (stringVector[0]==" "){
        return vector = {0};
    }
    int size = stringVector.size();
    Geometry geometry;
    for (int i = 0; i < size; ++i) {
        if (geometry.stringIsANumber(stringVector[i]))
            vector.push_back(std::stod(stringVector[i]));
        else {
            return vector = {0};
        }
    }
    return vector;
}




string *InputFile::clientInputWork(char clientInput[], string fileName, int clientInputSize) {
    //add the suffixes of the file in server run
    fileName = fileName + ".csv";
   //the min  chars  needed for the program---1
    if (clientInputSize > 6) {
    //vectorInput save the input
        vector<string> vectorInput;
        string stringTemp;
        bool startOfTheString= true;
        for (int i = 0; i <= clientInputSize; ++i) {
            // if the char not space or null\0
            if (clientInput[i] != 32 and clientInput[i] != 0) {
                stringTemp += clientInput[i];
                startOfTheString= false;
            }
            // when see space or 0 add the string to the vactor
            if (clientInput[i] == 32 or clientInput[i] == 0 and !startOfTheString) {
                vectorInput.push_back(stringTemp);
                stringTemp.clear();

            }
        }
        // check if the vector bigger from 3,we need one for vector,one for distance,one for k-num---2
        int size = vectorInput.size();
        if (size >= 3) {
            string *dataToInputFile[3];
            // to fix the problem in Mobax I need make temp var from k-num and distance
            auto* knumSave=new string;
            auto* distanceSave= new string;
            *knumSave=vectorInput[size - 1];
            *distanceSave=vectorInput[size - 2];
            string a=vectorInput[size - 1];
            string b=vectorInput[size - 2];
            dataToInputFile[0] = &a;//k-num
            dataToInputFile[1] = &fileName;
            dataToInputFile[2] = &b;//distance
            //remove k-num and distance
            vectorInput.pop_back();
            vectorInput.pop_back();
            // from string vector to long double vector
            vector<long double> vectorLong = fromStringVectorToLongDouble(vectorInput);
            //this the part from main in ass2
            std::vector<VectorData *> data;
            int *knNum = new int;
            auto *distance = new string;
            Geometry geometry;
            string* result;
            InputFile inputFile;
            //if return true then the data is good
            bool invalid = inputFile.dataMainInputFromFile(&data, 4, dataToInputFile, knNum, distance);
            //check if the data is ok and the vectorLong not empty and The size of the vectors is equal--3
            if (invalid and !vectorLong.empty() and
                geometry.vectorsAreOfSameLengthbool(data.at(0)->vectorV, vectorLong)) {
                //result the input from the user
                result = knn(&data, vectorLong, *distance, *knNum);
                return result;
            } else {
             //if 3 isn't true
                return InvalidInputString();
            }

        }
            //if 2 isn't true
        else {
            return InvalidInputString();
        }

    } //if 1 isn't true
    else {
        return InvalidInputString();
    }
}



/**
 * InvalidInputString
 * @return when invalid input return string
 */
string *InputFile::InvalidInputString(){
    auto *stringTemp = new string;
    *stringTemp = "invalid input";
    return stringTemp;
}



