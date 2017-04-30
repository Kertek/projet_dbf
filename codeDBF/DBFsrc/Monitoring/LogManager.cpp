//
// Created by baptiste on 25/04/17.
//
#include <thread>
#include "LogManager.h"
#include "processLogger.h"


void LogManager::run() {

    processLogger * newProcessLogger = new processLogger(&this->getInstance());
    std::thread threadLogger(*newProcessLogger);
    threadLogger.detach();
    this->isRunning = true;
}

void LogManager::stop() {
    this->isRunning = false;
}

bool LogManager::isItRunning() const {
    return isRunning;
}

LogManager::LogManager() {
    this->isRunning = false;
}

LogManager::~LogManager() {

}

void LogManager::write(const std::string &msg) {
    mFile.open(this->mFileName, std::ios::app);
    mFile.seekp(std::ios::end);
    if (!mFile.good()) return;
    mFile << msg
          << std::endl;
    mFile.flush();
    mFile.close();
}


const std::string LogManager::currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


std::string LogManager::linkTypeErrorString(TypeError type) {
    if (type==TypeError::INFO){
        return "INFO";
    }else if(type==TypeError::ERROR){
        return "ERROR";
    }else if(type==TypeError::WARNING){
        return "WARNING";
    }else if(type==TypeError::DANGER){
        return "DANGER";
    }else{
        return "UNKNOWN";
    }
}

void LogManager::addLogMessage(TypeError type, const std::string &msg) {
    std::string fullMessage = currentDateTime() + ':' + linkTypeErrorString(type) + ':' + msg + '\0';
    mBuffer.push_back(fullMessage);
}
