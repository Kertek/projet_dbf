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
    void write(TypeError type,const std::string &msg);

private:
    std::ofstream mFile;
    int mSocketNumber;
    string mFileName = "../DBFsrc/Monitoring/dbf.log";

    LoggerSocket(int socketNumber) {
        this->mSocketNumber = socketNumber;
    }

    ~LoggerSocket() {
    }

    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    const std::string currentDateTime();

    std::string linkTypeErrorString(TypeError type);
};


#endif //PROJET_DBF_LOGGERSOCKETT_H
