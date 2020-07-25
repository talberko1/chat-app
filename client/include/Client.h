//
// Created by tal on 25/07/2020.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include "socketwrapper/Socket.h"
#include <pthread.h>

class Client {
protected:
    Socket m_socket;
public:
    Client(int domain, int type, int protocol);
    virtual ~Client()=default;
    virtual size_t send(const char* message, int length, int flags)=0;
    virtual size_t receive(char* buffer, int length, int flags)=0;
    void close();
};

#endif //CLIENT_CLIENT_H
