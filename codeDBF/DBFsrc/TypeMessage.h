//
// Created by baptiste on 21/03/17.
//

#ifndef PROJET_DBF_TYPEMESSAGE_H
#define PROJET_DBF_TYPEMESSAGE_H


enum class TypeMessage {
    None,//initial type
    OK_Packet,
    EOF_Packet,
    ERR_Packet,
    Handshake_Packet,//equivalent to Server Greating for wireshark

    COM_SLEEP,
    COM_QUIT,
    COM_QUERY,
    Other
};


#endif //PROJET_DBF_TYPEMESSAGE_H
