//
// Created by tal on 25/07/2020.
//

#include "UDPClient.h"

UDPClient::UDPClient(const char *ip, int port) : Client(AF_INET, SOCK_DGRAM, 0) {
    struct sockaddr_in target = Socket::createAddress(AF_INET, ip, port);
    m_target = {target, sizeof(target)};
}

size_t UDPClient::send(const char *message, int length, int flags) {
    return m_socket.sendto(message, length, flags, m_target.target, m_target.targetLength);
}

size_t UDPClient::receive(char *buffer, int length, int flags) {
    return m_socket.recvfrom(buffer, length, flags, m_target.target, &m_target.targetLength);
}