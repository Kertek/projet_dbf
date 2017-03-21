//
// Created by baptiste on 21/03/17.
//

#include "Message.h"


Message::Message() {
    this->mContent = new std::vector;
    this->mTypeMessage = TypeMessage ::None;
}

std::vector *Message::getContent() const {
    return mContent;
}

void Message::setContent(std::vector *content) {
    Message::mContent = content;
}

TypeMessage Message::getTypeMessage() const {
    return mTypeMessage;
}

void Message::setMTypeMessage(TypeMessage typeMessage) {
    Message::mTypeMessage = typeMessage;
}