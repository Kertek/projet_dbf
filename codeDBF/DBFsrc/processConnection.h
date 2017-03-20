//
// Created by baptiste on 20/03/17.
//

#ifndef PROJET_DBF_PROCESSCONNECTION_H
#define PROJET_DBF_PROCESSCONNECTION_H


#include "Connection.h"

class processConnection {

private:
    Connection * mConnection;

public:
    processConnection(Connection * connection);
    void operator()();

};


#endif //PROJET_DBF_PROCESSCONNECTION_H
