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
    bool n = SocketFactory::getInstance().startServer(1025);
    if (n == false) {
        cout << "ERROR can't start the server" << endl;
        abort();
    } else {
        cout << "SERVER is running" << endl;
    }


    while (1) {
        SocketDbf *newSocketMulti = (SocketDbf *) SocketFactory::getInstance().accept(1025);
        cout << "someone call the server" << endl;
        while (1) {
            cout << newSocketMulti->receiveMessage() << endl;
            cout << endl;
            cout << "message reçu" << endl;
        }
    } /* end of while */

    return 0; /* we never get here */
}



