//
// Created by baptiste on 21/03/17.
//

#include <iostream>
#include "Message.h"

Message::Message() {
    this->mContent = new std::vector<char>;
    this->mTypeMessage = TypeMessage::None;
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

void Message::determineTypeMessage(unsigned int packetLength, unsigned int sequenceid, unsigned int packetHeader) {
    //TODO
    if (packetHeader == 0x00 && packetLength > 7) {
        this->mTypeMessage = TypeMessage::OK_Packet;
        return;
    } else if (packetHeader == 0xfe && packetLength < 9) {
        this->mTypeMessage = TypeMessage::EOF_Packet;
        return;
    } else if (packetHeader == 0xff) {
        this->mTypeMessage = TypeMessage::ERR_Packet;
    } else {
        this->mTypeMessage = TypeMessage::Other;
    }

}

