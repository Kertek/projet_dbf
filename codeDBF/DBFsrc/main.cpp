/* A simple server in the internet domain using TCP
   The port number is passed as an argument
   This version runs forever, forking off a separate
   process for each connection
*/
#include <iostream>
#include "SocketFactory.h"

void error(const char *msg) {
    perror(msg);
    exit(1);
}


int main() {
    cout << "Programm launched" << endl;

    bool n = SocketFactory::getInstance().startServer(3305);
    if (n == false) {
        cout << "ERROR can't start the server" << endl;
        abort();
    } else {
        cout << "SERVER is running" << endl;
    }
    SocketDbf *socketApllication = (SocketDbf *) SocketFactory::getInstance().accept(3305);
    cout << "Une application vient de se connecter" << endl;
    mutex *mSuperMutex = new mutex();
    SocketDbf *socketBdd = SocketFactory::getInstance().clientConnect("127.0.0.1", 3306);
    cout << "Connexion avec la base de données: OK" << endl;
    while (1) {

        cout << "premier echange: Récupération bdd + renvoi application" << endl;
        vector<char> msg;
        msg.resize(0, 0);
        msg.clear();
        int n = socketBdd->receiveMessage(msg);

        socketApllication->sendMessage((unsigned char *) msg.data());

        cout << "deuxieme echange" << endl;
        msg.resize(0, 0);
        msg.clear();

        socketApllication->receiveMessage(msg);

        socketBdd->sendMessage((unsigned char *) msg.data());

        cout << "troisième échange" << endl;
        msg.resize(0, 0);
        msg.clear();

        n = socketBdd->receiveMessage(msg);

        socketApllication->sendMessage((unsigned char *) msg.data());
        mSuperMutex->unlock();
        cout << "quatrième echange" << endl;
        msg.resize(0, 0);
        msg.clear();

        socketApllication->receiveMessage(msg);

        socketBdd->sendMessage((unsigned char *) msg.data());

        cout << "cinquième échange" << endl;
        msg.resize(0, 0);
        msg.clear();

        n = socketBdd->receiveMessage(msg);
        socketApllication->sendMessage((unsigned char *) msg.data());
        cout << "sizième echange" << endl;
        mSuperMutex->unlock();
        msg.resize(0, 0);
        msg.clear();
        socketApllication->receiveMessage(msg);
        socketBdd->sendMessage((unsigned char *) msg.data());


        abort();
    }

    /*bool n = SocketFactory::getInstance().startServer(1025);
    if (n == false) {
        cout << "ERROR can't start the server" << endl;
        abort();
    } else {
        cout << "SERVER is running" << endl;
    }


    while (1) {
        SocketDbf *socketApllication = (SocketDbf *) SocketFactory::getInstance().accept(1025);
        cout << "someone call the server" << endl;
        while(1){
            socketApllication->sendMessage();
            cout << socketApllication->receiveMessage() << endl;
            cout << endl;
            sleep(1);
        }


    } *//* end of while */

    return 0; /* we never get here */
}




