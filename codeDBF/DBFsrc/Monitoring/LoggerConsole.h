//
// Created by baptiste on 03/04/17.
//

#ifndef PROJET_DBF_LOGGERCONSOLE_H
#define PROJET_DBF_LOGGERCONSOLE_H


#include <string>
#include <iostream>
#include "Logger.h"

class LoggerConsole : public Logger
{
public:
    virtual void write( const std::string& msg )
    {
        std::cout << msg << std::endl;
    }
};

#endif //PROJET_DBF_LOGGERCONSOLE_H
