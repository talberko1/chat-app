//
// Created by tal on 23/07/2020.
//

#include "UDPServer.h"

UDPServer::UDPServer(const char *ip, int port) : Server(AF_INET, SOCK_DGRAM, 0){
    m_socket.bind(ip, port);
}

size_t UDPServer::send(void* target, char* buffer, size_t length, int flags) {
    struct Address client = *(struct Address*)target;
    return m_socket.sendto(buffer, length, flags, client.target, client.targetLength);
}

size_t UDPServer::receive(void* target, char* buffer, size_t length, int flags) {
    struct Address client = *(struct Address*)target;
    return m_socket.recvfrom(buffer, length, flags, client.target, &client.targetLength);
}

void UDPServer::start() {

}