//
// Created by baptiste on 20/03/17.
//

#include <iostream>
#include "processConnection.h"
#include "Monitoring/LogManager.h"
#include "Parser/calc_driver.h"

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

    Message *previousMessage;

    while (this->mConnection->getMessage()->getTypeMessage() != TypeMessage::COM_QUIT) {
        this->mConnection->getSocketBdd()->receiveMessage(this->mConnection->getMessage(), false);
        if (this->mConnection->getMessage()->getTypeMessage() == TypeMessage::ERR_Packet) {
            LogManager::getInstance().addLogMessage(TypeError::DANGER,
                                                    this->mConnection->getMessage()->extractContent(true));
            LogManager::getInstance().addLogMessage(TypeError::DANGER,
                                                    previousMessage->extractContent(true));
            this->mConnection->getMessage()->transformMessageDefaultError();
        }

        this->mConnection->getSocketApplication()->sendMessage(this->mConnection->getMessage());

        this->mConnection->getSocketApplication()->receiveMessage(this->mConnection->getMessage(), true);
        CALC::CALC_Driver driver;
        if (this->mConnection->getMessage()->getTypeMessage() == TypeMessage::COM_QUERY
            && driver.parse(this->mConnection->getMessage()->extractContent(true)) == false) {

            cout << "test" << this->mConnection->getMessage()->extractContent(true) << endl;
            LogManager::getInstance().addLogMessage(TypeError::DANGER,
                                                    this->mConnection->getMessage()->extractContent(true));
            this->mConnection->getMessage()->transformMessageDefaultError();
            this->mConnection->getSocketApplication()->sendMessage(this->mConnection->getMessage());
        } else {
            cout << "test" << this->mConnection->getMessage()->extractContent(true) << endl;
            this->mConnection->getSocketBdd()->sendMessage(this->mConnection->getMessage());
        }


        previousMessage = this->mConnection->getMessage();
    }

    delete previousMessage;
    this->mConnection->~Connection();

}
