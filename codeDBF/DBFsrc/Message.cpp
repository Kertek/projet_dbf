//
// Created by baptiste on 21/03/17.
//

#include <iostream>
#include "Message.h"

Message::Message() {
    this->mContent = new std::vector<char>;
    this->mTypeMessage = TypeMessage::None;
    initMap();

}

std::vector<char> *Message::getContent() const {
    return mContent;
}


void Message::setContent(std::vector<char> *content) {
    Message::mContent = content;
}

TypeMessage Message::getTypeMessage() const {
    return mTypeMessage;
}

void Message::initMessage() {
    this->mContent->clear();
    this->mContent->resize(0);
    this->mTypeMessage = TypeMessage::None;
}

void Message::initMap() {
    this->mMap = new  map<unsigned int,TypeMessage >();
    this->mMap->insert(pair<unsigned int, TypeMessage>(0x00, TypeMessage::OK_Packet));
}

void Message::determineTypeMessage(unsigned int packetHeader) {
    if (this->mMap->find(packetHeader) != this->mMap->end()) {
        this->mTypeMessage = this->mMap->find(packetHeader)->second;
    } else {
        this->mTypeMessage = TypeMessage::Other;
    }
}

