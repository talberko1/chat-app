//
// Created by tal on 22/07/2020.
//

#include "Server.h"

Server::Server(int domain, int type, int protocol) : m_socket(domain, type, protocol) {}