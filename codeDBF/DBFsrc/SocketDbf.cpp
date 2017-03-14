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

int SocketDbf::sendMessage(unsigned char *message) {
    //if the message is so much long, it can't be send

    int octetNecessaireLength = 3;

    if (!isClosed) {
        unsigned int size = (unsigned int) message[2];
        size = size * 256 + (unsigned int) message[1];
        size = size * 256 + (unsigned int) message[0];

        int n = write(mSocket, message, size + 1 + octetNecessaireLength);

        if (n < 0) {
            this->closeSocketMulti();
            cout << "message aborted: problem to sendMessage / socket close" << endl;
            abort();
        }

        return 0;
    } else {
        cout << "socket already closed" << endl;
    }

}

int SocketDbf::receiveMessage(vector<char> &msg) {


    msg.resize(3, 0);
    int n = 0;
    unsigned int size = 0;
    unsigned char header[3];
    while (n < 3) {
        int m = read(mSocket, header + n, 3 - n);
        if (m >= 0) {
            n += m;
        }

    }
    size = (unsigned int) header[2];
    size = size * 256 + (unsigned int) header[1];
    size = size * 256 + (unsigned int) header[0];

    unsigned char buffer[size];
    n = 0;

    while (n < size + 1) {
        int m = read(mSocket, buffer + n, size - n + 1);
        if (m >= 0) {
            n += m;
        }
    }



    msg.resize(size + 3 + 1, 0);
    for (int i = 0; i < 3; ++i)msg[i] = header[i];
    for (int i = 0; i < size + 1; ++i)msg[i + 3] = buffer[i];

    //affichage debug
    cout << "je reçois: ";
    for (int i = 0; i < size + 3; ++i) {
        cout << msg[i];
    }
    cout << endl;

    return 0;
}

