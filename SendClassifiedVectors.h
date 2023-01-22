#ifndef ASS4_SENDCLASSIFIEDVECTORS_H
#define ASS4_SENDCLASSIFIEDVECTORS_H
#include "DefaultIO.h"
#include "Data.h"

class SendClassifiedVectors {
public:
    void sendVectors(Data *data, DefaultIO *dio, bool createFile);
    int sendfilesocket(int port);
};


#endif //ASS4_SENDCLASSIFIEDVECTORS_H
