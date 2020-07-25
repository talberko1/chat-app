//
// Created by tal on 25/07/2020.
//

#include "Client.h"

Client::Client(int domain, int type, int protocol) : m_socket(domain, type, protocol) {}

void Client::close() {
    m_socket.close();
}