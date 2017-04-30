//
// Created by baptiste on 03/04/17.
//

#ifndef PROJET_DBF_LOGGER_H
#define PROJET_DBF_LOGGER_H

#include <string>
#include <mutex>
#include <map>
#include <fstream>
#include <vector>
#include "TypeError.h"

class LogManager {
    friend class processLogger;

private:
    LogManager();

    ~LogManager();

    bool isRunning;

    std::ofstream mFile;
    std::string mFileName = "../DBFsrc/Monitoring/dbf.log";

    std::vector<std::string> mBuffer;
public:
    static LogManager &getInstance() {
        static LogManager instance;
        return instance;
    }

    void run();

    void stop();

    bool isItRunning() const;

    void write(const std::string &msg);

    void addLogMessage(TypeError type,const std::string &msg);

    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    const std::string currentDateTime();

    std::string linkTypeErrorString(TypeError type);
};


#endif //PROJET_DBF_LOGGER_H
