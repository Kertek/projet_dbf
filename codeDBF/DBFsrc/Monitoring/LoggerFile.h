//
// Created by baptiste on 03/04/17.
//

#ifndef PROJET_DBF_LOGGERFILE_H
#define PROJET_DBF_LOGGERFILE_H

#include <string>
#include <fstream>
#include <iostream>

#include "Logger.h"
#include "../SocketDbf.h"

class LoggerFile : public Logger {
public:
    LoggerFile() {
        mFile.open(mFileName, std::ios::app);
        mFile.seekp(std::ios::end);

        if (!mFile.good()) return;
        mFile << "  ===============================================\n"
              << "    Begin Output log ( "
              << currentDateTime()
              << " ): "
              << "\n  ===============================================\n\n";
        mFile.flush();
    }

    virtual ~LoggerFile() {
        if (!mFile.good()) return;
        mFile << "\n  ===============================================\n"
              << "    End   Output log ( "
              << currentDateTime()
              << " ): "
              << "\n  ===============================================\n\n";
        mFile.flush();
        mFile.close();
    }

    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    const std::string currentDateTime() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

        return buf;
    }

    virtual void write(const std::string &msg) {
        mFile << msg
              << std::endl;
        mFile.flush();
    }

private:
    std::ofstream mFile;
    std::string mFileName = "../DBFsrc/Monitoring/dbf.log";
};

#endif //PROJET_DBF_LOGGERFILE_H
