/* A simple server in the internet domain using TCP
   The port number is passed as an argument
   This version runs forever, forking off a separate
   process for each connection
*/
#include <iostream>
#include <thread>
#include "SocketFactory.h"
#include "Config.h"
#include "Connection.h"
#include "processConnection.h"

void error(const char *msg) {
    perror(msg);
    exit(1);
}


int main() {
    cout << "Programm launched" << endl;

    bool n = SocketFactory::getInstance().startServer(Config::portDBF);
    if (n == false) {
        cout << "ERROR can't start the server" << endl;
        abort();
    } else {
        cout << "SERVER is running" << endl;
    }

    while (1) {
        SocketDbf *socketApllication = (SocketDbf *) SocketFactory::getInstance().accept(Config::portDBF);
        cout << "Une application vient de se connecter" << endl;
        Connection* newConnection = new Connection(socketApllication);

        processConnection * prrocessConnection = new processConnection(newConnection);
        thread threadConnection(*prrocessConnection);
        threadConnection.detach();




        /* cout << "premier echange: Récupération bdd + renvoi application" << endl;
        vector<char> msg;
        msg.resize(0, 0);
        msg.clear();
        int result = newConnection->getMSocketBdd()->receiveMessage(msg);

       newConnection->getMSocketApplication()->sendMessage(&msg);

        cout << "deuxieme echange" << endl;
        msg.resize(0, 0);
        msg.clear();

        newConnection->getMSocketApplication()->receiveMessage(msg);

        newConnection->getMSocketBdd()->sendMessage(&msg);

        cout << "troisième échange" << endl;
        msg.resize(0, 0);
        msg.clear();

        result = newConnection->getMSocketBdd()->receiveMessage(msg);

        newConnection->getMSocketApplication()->sendMessage(&msg);
        cout << "quatrième echange" << endl;
        msg.resize(0, 0);
        msg.clear();

        newConnection->getMSocketApplication()->receiveMessage(msg);

        newConnection->getMSocketBdd()->sendMessage(&msg);

        cout << "cinquième échange" << endl;
        msg.resize(0, 0);
        msg.clear();

        result = newConnection->getMSocketBdd()->receiveMessage(msg);
        newConnection->getMSocketApplication()->sendMessage(&msg);
        cout << "sizième echange" << endl;
        msg.resize(0, 0);
        msg.clear();
        newConnection->getMSocketApplication()->receiveMessage(msg);
        newConnection->getMSocketBdd()->sendMessage(&msg);

        newConnection->getMSocketApplication()->closeSocketMulti();
        newConnection->getMSocketBdd()->closeSocketMulti();*/
    }
    return 0; /* we never get here */
}




