//
// Created by baptiste on 25/04/17.
//

#ifndef PROJET_DBF_PROCESSCONNECTION_H
#define PROJET_DBF_PROCESSCONNECTION_H


#include "LogManager.h"

class processLogger {
    friend class LogManager;
private:
    LogManager * mLogManager;

public:
    processLogger(LogManager * logManager);
    void operator()();

};


#endif //PROJET_DBF_PROCESSCONNECTION_H
