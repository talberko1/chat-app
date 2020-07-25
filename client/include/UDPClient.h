//
// Created by tal on 25/07/2020.
//

#ifndef CLIENT_UDPCLIENT_H
#define CLIENT_UDPCLIENT_H

#include "Client.h"

struct Address {
    struct sockaddr_in target;
    socklen_t targetLength;
};

class UDPClient : public Client {
private:
    struct Address m_target{};
public:
    UDPClient(const char* ip, int port);
    size_t send(const char *message, int length, int flags) override;
    size_t receive(char *buffer, int length, int flags) override;
};

#endif //CLIENT_UDPCLIENT_H
