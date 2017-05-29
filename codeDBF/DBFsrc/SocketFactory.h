//
// Created by baptiste on 07/02/17.
//

#ifndef PROJET_DBF_SOCKETFACTORY_H
#define PROJET_DBF_SOCKETFACTORY_H

using namespace std;

#include <set>
#include <map>
#include <mutex>
#include "SocketDbf.h"
/**
 * This class is the access privileged for users to the network part.
 * It permits to startServer or Client and give access to socket launch.
 */
class SocketFactory {
    friend class SocketDbf;

private:
    const int PEOPLE_AT_SAME_TIME = 1000;

    SocketFactory() { initSocketFactory(); }

    set<SocketDbf *> openSockets;
    map<int, SocketDbf *> openServers;
    mutex mOpenSocketsMutex;
    mutex mOpenServersMutex;

    void initSocketFactory();

public:
    static SocketFactory &getInstance() {
        static SocketFactory instance;
        return instance;
    }

    /**
     * Creates a server on the specified port
     * @return false if the server could not be created (already existing, unable to bind socket, etc.), true if everything went OK
     */
    bool startServer(int nPort);

    /**
     * Waits until a client connects to the specified port.
     * Creates the corresponding server by calling #startServer if it does not exists yet
     * \return the socket to the connection established with the client, NULL if the connection could not be established
     */
    SocketDbf *accept(int nPort);

    /**
     * connects to a server and returns the corresponding socket.
     * \return NULL if the connection could not be established
     */
    SocketDbf *clientConnect(string serverAddress, int nPort);

};


#endif //PROJET_DBF_SOCKETFACTORY_H
