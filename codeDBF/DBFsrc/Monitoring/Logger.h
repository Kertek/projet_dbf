//
// Created by baptiste on 03/04/17.
//

#ifndef PROJET_DBF_LOGGER_H
#define PROJET_DBF_LOGGER_H

#include <string>

class Logger
{
public:
    virtual ~Logger   ( void ) {}
    virtual void write( const std::string& ) = 0;
};

#endif //PROJET_DBF_LOGGER_H
