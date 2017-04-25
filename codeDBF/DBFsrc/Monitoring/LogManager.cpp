//
// Created by baptiste on 25/04/17.
//
#include "LogManager.h"



LoggerSocket *LogManager::get(int i) {
    if (openLoggerSocket.count(i) == 0) {
        LoggerSocket *loggerSocket = new LoggerSocket(i);
        openLoggerSocket.insert(std::pair<int, LoggerSocket *>(i, loggerSocket));
        return loggerSocket;
    } else {
        return openLoggerSocket[i];
    }
}

void LogManager::run() {
    this->isRunning = true;
}

void LogManager::stop() {
    this->isRunning = false;
}

LogManager::LogManager() {
    this->isRunning = false;
}

LogManager::~LogManager() {

}

void LogManager::doneWithSocketLogger(int i) {

}
