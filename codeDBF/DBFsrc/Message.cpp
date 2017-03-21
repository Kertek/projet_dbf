//
// Created by baptiste on 21/03/17.
//

#include "Message.h"


Message::Message() {
    this->mContent = new std::vector<char>;
    this->mTypeMessage = TypeMessage ::None;
}

std::vector<char> * Message::getContent() const {
    return mContent;
}


void Message::setContent(std::vector<char> *content) {
    Message::mContent = content;
}

TypeMessage Message::getTypeMessage() const {
    return mTypeMessage;
}

void Message::setTypeMessage(TypeMessage typeMessage) {
    Message::mTypeMessage = typeMessage;
}

void Message::initMessage() {
    this->mContent->resize(0);
    this->mContent->clear();
    this->mTypeMessage = TypeMessage::None;
}
