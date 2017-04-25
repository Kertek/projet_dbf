//
// Created by baptiste on 25/04/17.
//

#include "LoggerSocket.h"

void LoggerSocket::write(TypeError type, const std::string &msg) {
    mFile.open(this->mFileName, std::ios::app);
    mFile.seekp(std::ios::end);
    if (!mFile.good()) return;
    mFile << currentDateTime()
          << ":"
          << linkTypeErrorString(type)
          << ":"
          << msg
          << std::endl;
    mFile.flush();
    mFile.close();
}

const std::string LoggerSocket::currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


std::string LoggerSocket::linkTypeErrorString(TypeError type) {
    if (type==TypeError::INFO){
        return "INFO";
    }else if(type==TypeError::ERROR){
        return "ERROR";
    }else if(type==TypeError::WARNING){
        return "WARNING";
    }else{
        return "UNKNOWN";
    }
}