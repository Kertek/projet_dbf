//
// Created by baptiste on 20/03/17.
//

#include <iostream>
#include "Connection.h"
#include "SocketFactory.h"
#include "Config.h"

Connection::Connection(SocketDbf *mSocketApplication) : mSocketApplication(mSocketApplication) {
    mSocketBdd = SocketFactory::getInstance().clientConnect(addressBdd, Config::portBdd);
    cout << "Connexion avec la base de données: OK" << endl;
}

Connection::~Connection() {
    this->mSocketApplication->closeSocketMulti();
    this->mSocketBdd->closeSocketMulti();
}

SocketDbf *Connection::getMSocketApplication() const {
    return mSocketApplication;
}

SocketDbf *Connection::getMSocketBdd() const {
    return mSocketBdd;
}
