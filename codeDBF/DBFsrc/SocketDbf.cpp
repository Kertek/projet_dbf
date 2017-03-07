//
// Created by baptiste on 07/02/17.
//

#include <zconf.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include "SocketDbf.h"
#include "SocketFactory.h"

SocketDbf::SocketDbf() {
    this->mSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->mSocket < 0) {
        this->isClosed = true;
    } else {
        this->isClosed = false;
    }
}


void SocketDbf::closeSocketMulti() {
    this->isClosed = true;
    SocketFactory::getInstance().mOpenSocketsMutex.lock();
    if (SocketFactory::getInstance().openSockets.count(this) != 0) {
        SocketFactory::getInstance().openSockets.erase(this);
    }
    SocketFactory::getInstance().mOpenSocketsMutex.unlock();
    ::close(mSocket);

}

string SocketDbf::receiveMessage()
{
    int n;
    //while there is not a DELIMITER in the buffer there is not an entire message so we stock into mBuffer what we read
    char * buffer = (char*) malloc(sizeof(char)*1024);

    n = recv(mSocket,buffer,1024,NULL);
    cout << "errno = " << errno << endl;
    cout << "buffer = " << buffer << endl;
    string retour(buffer);
    free(buffer);
    return retour;
}