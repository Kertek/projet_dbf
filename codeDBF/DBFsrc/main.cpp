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
    cout << "running ok" << endl;
    SocketDbf * mSocketClient = SocketFactory::getInstance().clientConnect("127.0.0.1",3306);
    cout << "client ok" << endl;
    bool n = SocketFactory::getInstance().startServer(3305);
    if (n == false) {
        cout << "ERROR can't start the server" << endl;
        abort();
    } else {
        cout << "SERVER is running" << endl;
    }
    SocketDbf *newSocketMulti = (SocketDbf *) SocketFactory::getInstance().accept(3305);
    cout << "someone call the server" << endl;
    while(1){
        cout << "je rentre là" << endl;

        vector<char> msg;
        msg.resize(0, 0);
        msg.clear();
        int n = mSocketClient->receiveMessage(msg);
        cout << "message reçu" <<endl;
        newSocketMulti->sendMessage((char *) msg.data(), msg.size());
        msg.resize(0, 0);
        msg.clear();
        newSocketMulti->receiveMessage(msg);
        mSocketClient->sendMessage((char *) msg.data(), msg.size());
        cout << "message envoyé" <<endl;
        sleep(60);
    }

    /*bool n = SocketFactory::getInstance().startServer(1025);
    if (n == false) {
        cout << "ERROR can't start the server" << endl;
        abort();
    } else {
        cout << "SERVER is running" << endl;
    }


    while (1) {
        SocketDbf *newSocketMulti = (SocketDbf *) SocketFactory::getInstance().accept(1025);
        cout << "someone call the server" << endl;
        while(1){
            newSocketMulti->sendMessage();
            cout << newSocketMulti->receiveMessage() << endl;
            cout << endl;
            sleep(1);
        }


    } *//* end of while */

    return 0; /* we never get here */
}




