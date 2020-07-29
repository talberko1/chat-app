//
// Created by tal on 22/07/2020.
//

#ifndef SERVER_TCPSERVER_H
#define SERVER_TCPSERVER_H

#include "Server.h"
#include <cstdlib>
#include <list>
#include <pthread.h>

struct TCPServerData {
    std::list<Socket> targets;
    Socket serverSocket;
};

struct TCPClientData {
    TCPServerData* serverData;
    Socket clientSocket;
};

class TCPServer : public Server {
public:
    TCPServer(const char *ip, int port);

    void start() override;

    size_t send(void *target, char *buffer, size_t length, int flags) override;

    size_t receive(void *target, char *buffer, size_t length, int flags) override;
};

#endif //SERVER_TCPSERVER_H
