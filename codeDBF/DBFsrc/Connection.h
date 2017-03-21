//
// Created by baptiste on 20/03/17.
//

#ifndef PROJET_DBF_CONNECTION_H
#define PROJET_DBF_CONNECTION_H

#include "SocketDbf.h"

/**
 * This class represent a connection.
 *
 * This object is use when you want to manage a connection.
 */
class Connection {

private:
    SocketDbf *mSocketApplication;
    SocketDbf *mSocketBdd;

public:
    /**
     * Constructor
     */
    Connection(SocketDbf *socketApplication);

    /**
     * Free the connection
     */
    ~Connection();

    SocketDbf *getSocketApplication() const;

    SocketDbf *getSocketBdd() const;
};


#endif //PROJET_DBF_CONNECTION_H
