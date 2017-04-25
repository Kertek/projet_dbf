//
// Created by baptiste on 03/04/17.
//

#ifndef PROJET_DBF_LOGGER_H
#define PROJET_DBF_LOGGER_H

#include <string>
#include <mutex>
#include <map>
#include "LoggerSocket.h"

class LogManager {
    friend class LoggerSocket;

private:
    LogManager();

    ~LogManager();

    bool isRunning;
    std::map<int, LoggerSocket *> openLoggerSocket;

public:
    static LogManager &getInstance() {
        static LogManager instance;
        return instance;
    }

    void run();

    void stop();

    LoggerSocket *get(int i);

    void doneWithSocketLogger(int i);



};



#endif //PROJET_DBF_LOGGER_H
