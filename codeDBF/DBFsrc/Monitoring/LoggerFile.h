//
// Created by baptiste on 03/04/17.
//

#ifndef PROJET_DBF_LOGGERFILE_H
#define PROJET_DBF_LOGGERFILE_H

#include <string>
#include <fstream>

#include "Logger.h"

class LoggerFile : public Logger
{
public:
    LoggerFile()
    {
        mFile.open( mFileName, std::ios::app );
        mFile.seekp( std::ios::beg );

        if (!mFile.good()) return;
        mFile << "  ===============================================\n"
              << "    Begin Output log ( "
              << time(0)
              << "\n  ===============================================\n\n";
        mFile.flush();
    }

    virtual ~LoggerFile()
    {
        if (!mFile.good()) return;
        mFile << "\n  ===============================================\n"
              << "    End   Output log ( "
              << time(0)
              << " ): "
              << "\n  ===============================================\n\n";
        mFile.flush();
        mFile.close();
    }

    virtual void write( const std::string& msg )
    {
        mFile << msg;
        mFile.flush();
    }

private:
    std::ofstream mFile;
    static std::string mFileName = "dbf.log";
};

#endif //PROJET_DBF_LOGGERFILE_H
