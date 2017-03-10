

#include <string.h>
#include <netinet/in.h>
#include <iostream>
#include<arpa/inet.h>
#include <fcntl.h>
#include "SocketFactory.h"
#include "SocketDbf.h"




bool SocketFactory::startServer(int nPort) {
    mOpenServersMutex.lock();
    if (openServers.count(nPort) != 0) {   // if the server already exist: ERROR on starting
        mOpenServersMutex.unlock();
        return false;
    }
    SocketDbf *mSocketDbf = new SocketDbf();
    openServers.insert(pair<int, SocketDbf *>(nPort, mSocketDbf));

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(nPort);
    if (bind(openServers.at(nPort)->mSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0) { // if we can't bind:ERROR on starting
        openServers.erase(nPort);
        mOpenServersMutex.unlock();
        return false;
    } else {
        if (listen(openServers.at(nPort)->mSocket,
                   PEOPLE_AT_SAME_TIME) < 0) {//open the port where we will wait for client incoming
            openServers.erase(nPort);
            mOpenServersMutex.unlock();
            return false;
        }
    }
    mOpenServersMutex.unlock();
    return true;
}

SocketDbf *SocketFactory::accept(int nPort) {
    mOpenServersMutex.lock();
    if (openServers.count(nPort) == 0) {   //if the server doesn't exist, we create it
        bool isGoodConnection = startServer(nPort);
        if (!isGoodConnection) {  //if the creation isn't done error
            return nullptr;
        }
    }
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof((struct sockaddr *) &cli_addr);

    SocketDbf *newSocket = new SocketDbf();
    newSocket->mSocket = ::accept(openServers[nPort]->mSocket, (struct sockaddr *) &cli_addr,
                                  &clilen);
    mOpenServersMutex.unlock();
    if (newSocket->mSocket < 0) {//wait for a newsocket
        cout << "socket < 0 ""errno " << errno << endl;
        return nullptr;
    }
    fcntl(newSocket->mSocket, F_SETFL, O_NONBLOCK); //socket to deal with client so not a blocked one

    mOpenSocketsMutex.lock();
    openSockets.insert(newSocket);
    mOpenSocketsMutex.unlock();

    return newSocket;
}

SocketDbf *SocketFactory::clientConnect(string serverAddress, int nPort) {
    SocketDbf *mSocketMulti = new SocketDbf();

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serverAddress.c_str());
    serv_addr.sin_port = htons(nPort);
    if (connect(mSocketMulti->mSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
        0)// if problem to connect
    {
        return nullptr;
    } else {
        fcntl(mSocketMulti->mSocket, F_SETFL, O_NONBLOCK);//socket to deal with client so not a blocked one
        mOpenSocketsMutex.lock();
        openSockets.insert(mSocketMulti);
        mOpenSocketsMutex.unlock();
        cout << "Hello your Socket have been created, have a nice exchange." << endl;
        return mSocketMulti;
    }
}

void SocketFactory::initSocketFactory() {

}










