//
// Created by tal on 22/07/2020.
//

#ifndef SERVER_UDPSERVER_H
#define SERVER_UDPSERVER_H

#include "Server.h"

#include <cstdlib>
#include <list>
#include <pthread.h>

struct Address {
    struct sockaddr_in target;
    socklen_t targetLength;
};

class UDPServer : public Server {
public:
    UDPServer(const char *ip, int port);

    size_t send(void *target, char *buffer, size_t length, int flags) override;

    size_t receive(void *target, char *buffer, size_t length, int flags) override;

    void start() override;
};

#endif //SERVER_UDPSERVER_H
