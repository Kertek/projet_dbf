
//
// Created by baptiste on 21/03/17.
//

#ifndef PROJET_DBF_MESSAGE_H
#define PROJET_DBF_MESSAGE_H


#include <vector>
#include "TypeMessage.h"
#include <map>

using namespace std;
class Message {
private:
    std::vector<char> *mContent;
    TypeMessage mTypeMessage;
    map<unsigned int,TypeMessage > *  mMapResponse;
    map<unsigned int,TypeMessage > *  mMapRequest;

public:
    Message();

    ~Message() {};

    std::vector<char> * getContent() const;

    void setContent(std::vector<char> *content);

    TypeMessage getTypeMessage() const;

    void determineTypeMessage(unsigned int packetHeader, bool isRequest); //either it is response

    void initMessage();

    void initMap();


};


#endif //PROJET_DBF_MESSAGE_H
