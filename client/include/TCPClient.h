//
// Created by tal on 25/07/2020.
//

#ifndef CLIENT_TCPCLIENT_H
#define CLIENT_TCPCLIENT_H
#include "Client.h"

class TCPClient : public Client {
public:
    TCPClient(const char* ip, int port);
    size_t send(const char* message, int length, int flags) override;
    size_t receive(char* buffer, int length, int flags) override;
};

#endif //CLIENT_TCPCLIENT_H
