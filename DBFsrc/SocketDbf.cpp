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
    SocketFactory::getInstance().mKeepAliveableSocketsMutex.lock();
    if (SocketFactory::getInstance().openSockets.count(this) != 0) {
        SocketFactory::getInstance().openSockets.erase(this);
    }
    if (SocketFactory::getInstance().mKeepAliveableSockets.count(this) != 0) {
        SocketFactory::getInstance().mKeepAliveableSockets.erase(this);
    }
    SocketFactory::getInstance().mKeepAliveableSocketsMutex.unlock();
    SocketFactory::getInstance().mOpenSocketsMutex.unlock();
    ::close(mSocket);

}