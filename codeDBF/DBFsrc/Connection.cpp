//
// Created by baptiste on 20/03/17.
//

#include <iostream>
#include "Connection.h"
#include "SocketFactory.h"
#include "Config.h"

Connection::Connection(SocketDbf *mSocketApplication) : mSocketApplication(mSocketApplication) {
    this->mSocketBdd = SocketFactory::getInstance().clientConnect(addressBdd, Config::portBdd);
    this->mMessage = new Message();
    cout << "Connexion avec la base de données: OK" << endl;
}

Connection::~Connection() {
    this->mSocketApplication->closeSocketMulti();
    this->mSocketBdd->closeSocketMulti();
    this->mMessage->~Message();
}

SocketDbf *Connection::getSocketApplication() const {
    return mSocketApplication;
}

SocketDbf *Connection::getSocketBdd() const {
    return mSocketBdd;
}

Message *Connection::getMessage() const {
    return mMessage;
}
