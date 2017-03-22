//
// Created by baptiste on 07/02/17.
//

#include <zconf.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include "SocketDbf.h"
#include "SocketFactory.h"
#include "errno_dbf.h"

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

int SocketDbf::sendMessage(Message *message) {
    int result;
    result = write(mSocket, message->getContent()->data(), message->getContent()->size());

    if (result <= 0) {
        return ERRNO_DBF_ERROR_TO_SEND_MESSAGE - 3;
    } else {
        return ERRNO_DBF_OK;
    }


}

int SocketDbf::receiveMessage(Message *msg, bool isFromApplication) {

    msg->initMessage();

    int sizeGlobal = 0;
    int octetNecessaireLength = 3;
    int result = 0;

    unsigned int size = 0;
    unsigned char bufferLength[octetNecessaireLength];
    while (result < octetNecessaireLength) {
        int m = read(mSocket, bufferLength + result, octetNecessaireLength - result);
        if (m >= 0) {
            result += m;
        }
    }
    for (int i = octetNecessaireLength; i > 0; i--) {
        size = size * 256 + (unsigned int) bufferLength[i - 1];
    }
    unsigned char bufferSeqId[1];
    while (read(mSocket, bufferSeqId, 1) != 1) {}
    unsigned int sequenceid = (unsigned int) bufferSeqId[0];

    unsigned char bufferHeader[1];
    while (read(mSocket, bufferHeader, 1) != 1) {}
    unsigned int headerValue = (unsigned int) bufferHeader[0];

    //Determine the type of the message
    msg->determineTypeMessage(headerValue,isFromApplication);

    unsigned char bufferData[size];
    result = 0;
    while (result < size - 1) {
        int m = read(mSocket, bufferData + result, size - result - 1);
        if (m >= 0) {
            result += m;
        }
    }
    sizeGlobal = sizeGlobal + size + octetNecessaireLength + 1;

    msg->getContent()->resize(sizeGlobal, 0);
    for (int i = 0; i < 3; ++i)msg->getContent()->data()[i] = bufferLength[i];
    msg->getContent()->data()[3] = bufferSeqId[0];
    msg->getContent()->data()[4] = bufferHeader[0];
    for (int i = 0; i < size - 1; ++i)msg->getContent()->data()[i + octetNecessaireLength + 1 + 1] = bufferData[i];

    while (1) {


        unsigned char bufferLength[octetNecessaireLength];
        if (read(mSocket, bufferLength, 1) == 1) {
            result = 1;
            size = 0;

            while (result < octetNecessaireLength) {
                int m = read(mSocket, bufferLength + result, octetNecessaireLength - result);
                if (m >= 0) {
                    result += m;
                }

            }
            for (int i = octetNecessaireLength; i > 0; i--) {
                size = size * 256 + (unsigned int) bufferLength[i - 1];
            }

            unsigned char bufferSeqId[1];
            while (read(mSocket, bufferSeqId, 1) != 1) {}
            int numberOfPacket = (unsigned int) bufferSeqId[0];

            unsigned char bufferData[size];
            result = 0;
            while (result < size) {
                int m = read(mSocket, bufferData + result, size - result);
                if (m >= 0) {
                    result += m;
                }
            }

            int previousSizeGlobal = sizeGlobal;
            sizeGlobal = sizeGlobal + size + octetNecessaireLength + 1;

            msg->getContent()->resize(sizeGlobal);
            for (int i = 0; i < 3; ++i)msg->getContent()->data()[i + previousSizeGlobal] = bufferLength[i];
            msg->getContent()->data()[3 + previousSizeGlobal] = bufferSeqId[0];
            for (int i = 0; i < size; ++i)
                msg->getContent()->data()[i + previousSizeGlobal + octetNecessaireLength + 1] = bufferData[i];
        } else {
            /*//Affichage message: Debug
            for (int i = 0; i < sizeGlobal + 1; i++) {
                cout << msg->getContent()->data()[i];
            }
            cout << endl;*/


            return ERRNO_DBF_OK;
        }

    }

}

