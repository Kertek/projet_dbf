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
    this->mMapRequest = new map<unsigned int, TypeMessage>();
    this->mMapResponse = new map<unsigned int, TypeMessage>();

    //Request
    this->mMapRequest->insert(pair<unsigned int, TypeMessage>(0x00, TypeMessage::COM_SLEEP));
    this->mMapRequest->insert(pair<unsigned int, TypeMessage>(0x01, TypeMessage::COM_QUIT));
    this->mMapRequest->insert(pair<unsigned int, TypeMessage>(0x03, TypeMessage::COM_QUERY));

    //Response
    this->mMapResponse->insert(pair<unsigned int, TypeMessage>(0x0a, TypeMessage::Handshake_Packet));
    this->mMapResponse->insert(pair<unsigned int, TypeMessage>(0x00, TypeMessage::OK_Packet));
    this->mMapResponse->insert(pair<unsigned int, TypeMessage>(0xff, TypeMessage::ERR_Packet));
    this->mMapResponse->insert(pair<unsigned int, TypeMessage>(0xfe, TypeMessage::EOF_Packet));

}

void Message::determineTypeMessage(unsigned int packetHeader, bool isRequest) {
    if (isRequest) {
        if (this->mMapRequest->find(packetHeader) != this->mMapRequest->end()) {
            this->mTypeMessage = this->mMapRequest->find(packetHeader)->second;
        } else {
            this->mTypeMessage = TypeMessage::OtherRequest;
        }
    } else {
        if (this->mMapResponse->find(packetHeader) != this->mMapResponse->end()) {
            this->mTypeMessage = this->mMapResponse->find(packetHeader)->second;
        } else {
            this->mTypeMessage = TypeMessage::OtherResponse;
        }
    }

}

string Message::extractContent(bool isRequest) {
    this->determineTypeMessage(this->mContent->data()[4], isRequest);
    if (this->mTypeMessage == TypeMessage::COM_QUERY) {
        return std::string(&this->mContent->data()[5], this->mContent->size() - 5);
    } else {
        return "";
    }
}

void Message::transformMessageDefaultError() {
    this->initMessage();
    string buffer = "An error happened. Please contact the administrator.";

    this->getContent()->push_back(buffer.size()+2);
    this->getContent()->push_back(0x00);
    this->getContent()->push_back(0x00);
    this->getContent()->push_back(0x01);
    this->getContent()->push_back(0xff);
    this->getContent()->push_back(0x00);
    this->getContent()->push_back(0x00);
    for (int i= 0; i < buffer.size(); i++){
        this->getContent()->push_back(buffer[i]);
    }




}
