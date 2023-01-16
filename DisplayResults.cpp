//
// Created by asaf9 on 1/9/2023.
//

#include "DisplayResults.h"

DisplayResults::DisplayResults(Data *data) {
    this->description="display results";
    this->data=data;

}

void DisplayResults::execute() {
    if (data->path->empty() or data->pathsort->empty()){
        this->dio.write("data upload please.");
        exit(1);
    }
    if (data.sortvectrs.empty){
        this->dio.write("data the classify please.");
        exit(1);
    }

    //sizeof struct
    for (int i = 0; i < sizeof(data.sortvecotr); ++i) {
        this->dio.write(i+" "+data.sortvecotr[i].sort+"\n");
    }
    this->dio.write("Done.");

}
