/* A simple server in the internet domain using TCP
   The port number is passed as an argument
   This version runs forever, forking off a separate
   process for each connection
*/
#include <iostream>
#include "SocketFactory.h"
#include "Config.h"

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
        SocketDbf *socketBdd = SocketFactory::getInstance().clientConnect("127.0.0.1", 3306);
        cout << "Connexion avec la base de données: OK" << endl;
        cout << "premier echange: Récupération bdd + renvoi application" << endl;
        vector<char> msg;
        msg.resize(0, 0);
        msg.clear();
        int result = socketBdd->receiveMessage(msg);

        socketApllication->sendMessage(&msg);

        cout << "deuxieme echange" << endl;
        msg.resize(0, 0);
        msg.clear();

        socketApllication->receiveMessage(msg);

        socketBdd->sendMessage(&msg);

        cout << "troisième échange" << endl;
        msg.resize(0, 0);
        msg.clear();

        result = socketBdd->receiveMessage(msg);

        socketApllication->sendMessage(&msg);
        cout << "quatrième echange" << endl;
        msg.resize(0, 0);
        msg.clear();

        socketApllication->receiveMessage(msg);

        socketBdd->sendMessage(&msg);

        cout << "cinquième échange" << endl;
        msg.resize(0, 0);
        msg.clear();

        result = socketBdd->receiveMessage(msg);
        socketApllication->sendMessage(&msg);
        cout << "sizième echange" << endl;
        msg.resize(0, 0);
        msg.clear();
        socketApllication->receiveMessage(msg);
        socketBdd->sendMessage(&msg);

        socketApllication->closeSocketMulti();
        socketBdd->closeSocketMulti();
    }
    return 0; /* we never get here */
}




