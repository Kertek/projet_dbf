//
// Created by baptiste on 20/03/17.
//

#include <iostream>
#include "processConnection.h"

processConnection::processConnection(Connection *connection) : mConnection(connection) {}

void processConnection::operator()() {
    cout << "premier echange: Récupération bdd + renvoi application" << endl;
    vector<char> msg;
    msg.resize(0, 0);
    msg.clear();
    int result = this->mConnection->getSocketBdd()->receiveMessage(msg);

    this->mConnection->getSocketApplication()->sendMessage(&msg);

    cout << "deuxieme echange" << endl;
    msg.resize(0, 0);
    msg.clear();

    this->mConnection->getSocketApplication()->receiveMessage(msg);

    this->mConnection->getSocketBdd()->sendMessage(&msg);

    cout << "troisième échange" << endl;
    msg.resize(0, 0);
    msg.clear();

    result = this->mConnection->getSocketBdd()->receiveMessage(msg);

    this->mConnection->getSocketApplication()->sendMessage(&msg);
    cout << "quatrième echange" << endl;
    msg.resize(0, 0);
    msg.clear();

    this->mConnection->getSocketApplication()->receiveMessage(msg);

    this->mConnection->getSocketBdd()->sendMessage(&msg);

    cout << "cinquième échange" << endl;
    msg.resize(0, 0);
    msg.clear();
    result = this->mConnection->getSocketBdd()->receiveMessage(msg);
    this->mConnection->getSocketApplication()->sendMessage(&msg);
    cout << "sizième echange" << endl;
    msg.resize(0, 0);
    msg.clear();
    this->mConnection->getSocketApplication()->receiveMessage(msg);
    this->mConnection->getSocketBdd()->sendMessage(&msg);

    this->mConnection->~Connection();

}
