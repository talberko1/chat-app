//
// Created by tal on 25/07/2020.
//

#include "TCPClient.h"

TCPClient::TCPClient(const char *ip, int port) : Client(AF_INET, SOCK_STREAM, 0) {
    m_socket.connect(ip, port);
}

size_t TCPClient::send(const char *message, int length, int flags) {
    return m_socket.send(message, length, flags);
}

size_t TCPClient::receive(char *buffer, int length, int flags) {
    return m_socket.recv(buffer, length, flags);
}