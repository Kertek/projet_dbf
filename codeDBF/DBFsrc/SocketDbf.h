//
// Created by baptiste on 07/02/17.
//

#ifndef PROJET_DBF_SOCKETMULTI_H
#define PROJET_DBF_SOCKETMULTI_H


#include <unistd.h>
#include <mutex>
#include <vector>

using namespace std;
/**
 * This class represent our Socket.
 * A client use this class to deal with socket.
 *
 * The client must have created a socket with SocketFactory.
 */
class SocketDbf {
    friend class SocketFactory;

private:
    int mSocket;
    bool isClosed;

    /**
     * To get a socket such as a copy
     * @param origin
     */
    SocketDbf(const SocketDbf &origin) : mSocket(origin.mSocket) { abort(); }

    /**
     * Constructor, choose if you want to have a blocked or not socket.
     */
    SocketDbf();

    /**
     * Free the socket
     */
    ~SocketDbf() {}


public:
    /**
     * Close the socket and do everything link to that such as erase the SocketMulti in maps where it is
     */
    void closeSocketMulti();

    /**
     * Receive the message sent to the socket knowing that the end of the message will be on a special symbol
     */
    string receiveMessage();
    bool sendMessage();
};

#endif //PROJET_DBF_SOCKETMULTI_H
