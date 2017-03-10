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

int SocketDbf::sendMessage(char *message, unsigned int messageLength) {
    //if the message is so much long, it can't be send

    if (!isClosed) {


        int n = write(mSocket, message , message[0]+3+1);

        if (n < 0) {
            this->closeSocketMulti();
            cout << "message aborted" <<endl;
            abort();
        } else {
            cout << "j'envoi  " << message << endl;
        }
        return 0;
    }

}

int SocketDbf::receiveMessage(vector<char> &msg) {

    msg.resize(3, 0);
    int n = 0;
    int size = 0;
    unsigned char header[3];
    while (n < 3) {
        int m= read(mSocket, header + n, 3 - n);
        if (m >= 0 ){
            n += m;
        }
        cout << "n: " << n << endl;
    }
    size = (int) header[2];
    size = size * 256 + (int) header[1];
    size = size * 256 + (int) header[0];

    cout << "header0" << (int) header[0] << endl;
    cout << "header1" << (int) header[1] << endl;
    cout << "header2" << (int) header[2] << endl;

    cout << "size: " << size << endl;

    unsigned char buffer[size];

    n=0;

    while (n < size) {
        int m= read(mSocket, buffer+n, size-n);
        if (m >= 0 ){
            n += m;
        }
        cout << "n2: " << n << endl;
    }


    msg.resize(size+3,0);
    for (int i = 0; i < 3; ++i)msg[i] = header[i];
    for (int i = 0; i < size; ++i)msg[i+3] = buffer[i];
    for (int i = 0 ; i < size + 3; ++i){
        cout << msg[i];
    }
    cout << endl;

    return 0;
}

