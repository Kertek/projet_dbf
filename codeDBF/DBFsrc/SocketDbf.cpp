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

int SocketDbf::sendMessage(vector<char> *message) {
    //if the message is so much long, it can't be send


    int octetNecessaireLength = 3;

//    if (!isClosed) {
//        unsigned int size = (unsigned int) message[2];
//        size = size * 256 + (unsigned int) message[1];
//        size = size * 256 + (unsigned int) message[0];
//
//        int n = write(mSocket, message, size + 1 + octetNecessaireLength);
//
//        if (n < 0) {
//            this->closeSocketMulti();
//            cout << "message aborted: problem to sendMessage / socket close" << endl;
//            abort();
//        }
//
//        return 0;
//    } else {
//        cout << "socket already closed" << endl;
//    }

    write(mSocket, message->data(), message->size());

}

int SocketDbf::receiveMessage(vector<char> &msg) {

    int sizeGlobal = 0;
    int octetNecessaireLength = 3;
    int n = 0;

    unsigned int size = 0;
    unsigned char bufferLength[octetNecessaireLength];
    while (n < octetNecessaireLength) {
        int m = read(mSocket, bufferLength + n, octetNecessaireLength - n);
        if (m >= 0) {
            n += m;
        }
    }
    for (int i = octetNecessaireLength; i > 0; i--) {
        size = size * 256 + (unsigned int) bufferLength[i - 1];
    }
    cout << "size: " << size << endl;
    unsigned char bufferPacket[1];
    while (read(mSocket, bufferPacket, 1) != 1) {}
    int numberOfPacket = (unsigned int) bufferPacket[0];

    unsigned char bufferData[size];
    n = 0;
    while (n < size) {

        int m = read(mSocket, bufferData + n, size - n);
        if (m >= 0) {
            n += m;
        }
    }
    sizeGlobal = sizeGlobal + size + octetNecessaireLength + 1;
    msg.resize(sizeGlobal, 0);
    for (int i = 0; i < 3; ++i)msg[i] = bufferLength[i];
    msg[3] = bufferPacket[0];
    for (int i = 0; i < size; ++i)msg[i + octetNecessaireLength + 1] = bufferData[i];

    while (1) {


        unsigned char bufferLength[octetNecessaireLength];
        if (read(mSocket, bufferLength, 1) == 1) {
            cout << "je rentre car c'est une complexe" << endl;
            n = 1;
            size = 0;

            while (n < octetNecessaireLength) {
                int m = read(mSocket, bufferLength + n, octetNecessaireLength - n);
                if (m >= 0) {
                    n += m;
                }

            }
            for (int i = octetNecessaireLength; i > 0; i--) {
                size = size * 256 + (unsigned int) bufferLength[i - 1];
                cout << "size: " << size << "bufferLength[" << i - 1 << "]" << (int) bufferLength[i - 1] << endl;
            }


            cout << "on passe ici avec size : " << size << endl;

            unsigned char bufferPacket[1];
            while (read(mSocket, bufferPacket, 1) != 1) {}
            int numberOfPacket = (unsigned int) bufferPacket[0];

            unsigned char bufferData[size];
            n = 0;
            while (n < size) {
                int m = read(mSocket, bufferData + n, size - n);
                if (m >= 0) {
                    n += m;
                }
            }

            cout << "on est débloqué" << endl;
            int previousSizeGlobal = sizeGlobal;
            sizeGlobal = sizeGlobal + size + octetNecessaireLength + 1;

            msg.resize(sizeGlobal);
            for (int i = 0; i < 3; ++i)msg[i + previousSizeGlobal] = bufferLength[i];
            msg[3 + previousSizeGlobal] = bufferPacket[0];
            for (int i = 0; i < size; ++i)msg[i + previousSizeGlobal + octetNecessaireLength + 1] = bufferData[i];
            cout << "on passe là" << endl;
        } else {

            for (int i = 0; i < sizeGlobal + 1; i++) {
                cout << msg[i];
            }
            cout << endl;


            return 0;
        }

    }

}

