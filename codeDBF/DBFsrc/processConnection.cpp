//
// Created by baptiste on 20/03/17.
//

#include <iostream>
#include "processConnection.h"
#include "Monitoring/LogManager.h"

processConnection::processConnection(Connection *connection) : mConnection(connection) {}

void processConnection::operator()() {
/* previous version
    cout << "premier echange: Récupération bdd + renvoi application" << endl;

    int result = this->mConnection->getSocketBdd()->receiveMessage(this->mConnection->getMessage(), false);

    this->mConnection->getSocketApplication()->sendMessage(this->mConnection->getMessage());

    cout << "deuxieme echange" << endl;


    this->mConnection->getSocketApplication()->receiveMessage(this->mConnection->getMessage(), true);

    this->mConnection->getSocketBdd()->sendMessage(this->mConnection->getMessage());

    cout << "troisième échange" << endl;

    result = this->mConnection->getSocketBdd()->receiveMessage(this->mConnection->getMessage(), false);

    this->mConnection->getSocketApplication()->sendMessage(this->mConnection->getMessage());
    cout << "quatrième echange" << endl;


    this->mConnection->getSocketApplication()->receiveMessage(this->mConnection->getMessage(), true);
    //LogManager::getInstance().addLogMessage(TypeError::INFO, this->mConnection->getMessage()->extractContent(true));

    this->mConnection->getSocketBdd()->sendMessage(this->mConnection->getMessage());

    cout << "cinquième échange" << endl;

    result = this->mConnection->getSocketBdd()->receiveMessage(this->mConnection->getMessage(), false);
    cout << "bien reçu"<< endl;

    this->mConnection->getSocketApplication()->sendMessage(this->mConnection->getMessage());
    cout << "sizième echange" << endl;

    this->mConnection->getSocketApplication()->receiveMessage(this->mConnection->getMessage(), true);
    this->mConnection->getSocketBdd()->sendMessage(this->mConnection->getMessage());
*/


    while (this->mConnection->getMessage()->getTypeMessage() != TypeMessage::COM_QUIT) {
        int result = this->mConnection->getSocketBdd()->receiveMessage(this->mConnection->getMessage(), false);

        this->mConnection->getSocketApplication()->sendMessage(this->mConnection->getMessage());

        this->mConnection->getSocketApplication()->receiveMessage(this->mConnection->getMessage(), true);

        this->mConnection->getSocketBdd()->sendMessage(this->mConnection->getMessage());
    }


    this->mConnection->~Connection();

}
