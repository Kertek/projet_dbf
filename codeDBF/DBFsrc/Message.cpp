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
    this->mMapRequest = new  map<unsigned int,TypeMessage >();
    this->mMapResponse = new  map<unsigned int,TypeMessage >();

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

void Message::determineTypeMessage(unsigned int packetHeader,bool isRequest) {
    if (isRequest){
        if (this->mMapRequest->find(packetHeader) != this->mMapRequest->end()) {
            this->mTypeMessage = this->mMapRequest->find(packetHeader)->second;
            cout << "paquet determiné " << endl;
        } else {
            this->mTypeMessage = TypeMessage::OtherRequest;
            cout << "paquet indeterminé " << endl;
        }
    }else{
        if (this->mMapResponse->find(packetHeader) != this->mMapResponse->end()) {
            this->mTypeMessage = this->mMapResponse->find(packetHeader)->second;
            cout << "paquet determiné " << endl;
        } else {
            this->mTypeMessage = TypeMessage::OtherResponse;
            cout << "paquet indeterminé " << endl;
        }
    }

}

