//
// Created by baptiste on 25/04/17.
//

#ifndef PROJET_DBF_LOGGERSOCKETT_H
#define PROJET_DBF_LOGGERSOCKETT_H

#include <string>
#include <fstream>
#include <iostream>
#include "../SocketDbf.h"
#include "TypeError.h"

class LoggerSocket {
    friend class LogManager;

public:


private:
    std::ofstream mFile;
    int mSocketNumber;
    string mFileName = "../DBFsrc/Monitoring/dbf.log";

    LoggerSocket(int socketNumber) {
        this->mSocketNumber = socketNumber;
    }

    ~LoggerSocket() {
    }


};


#endif //PROJET_DBF_LOGGERSOCKETT_H
