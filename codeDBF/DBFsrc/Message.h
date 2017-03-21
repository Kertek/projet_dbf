
//
// Created by baptiste on 21/03/17.
//

#ifndef PROJET_DBF_MESSAGE_H
#define PROJET_DBF_MESSAGE_H


#include <vector>
#include "TypeMessage.h"

class Message {
private:
    std::vector *mContent;
    TypeMessage mTypeMessage;

public:
    Message();

    ~Message() {};

    std::vector *getContent() const;

    void setContent(std::vector *content);

    TypeMessage getTypeMessage() const;

    void setTypeMessage(TypeMessage mTypeMessage);
};


#endif //PROJET_DBF_MESSAGE_H
