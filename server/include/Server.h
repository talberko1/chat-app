//
// Created by tal on 22/07/2020.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "socketwrapper/Socket.h"
#include <list>

struct ServerData {
    Socket server;
    std::list<void*> targets;
};

struct ClientData {
    struct ServerData* data;
    void* client;
};

class Server {
protected:
    Socket m_socket;
public:
    Server(int domain, int type, int protocol);
    virtual ~Server()=default;
    virtual size_t send(void* target, char* buffer, size_t length, int flags)=0;
    virtual size_t receive(void* target, char* buffer, size_t length, int flags)=0;
    virtual void start()=0;
};

#endif //SERVER_SERVER_H
