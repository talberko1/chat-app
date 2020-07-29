//
// Created by tal on 22/07/2020.
//

#include "TCPServer.h"

void *clientHandler(void *arg);

TCPServer::TCPServer(const char *ip, int port) : Server(AF_INET, SOCK_STREAM, 0) {
    m_socket.bind(ip, port);
    m_socket.listen(10);
}

void TCPServer::start() {
    pthread_t clientThread;
    struct TCPServerData serverData = {.targets=std::list<Socket>(), .serverSocket=m_socket};
    while (true) {
        std::tuple<Socket, const char *> client = serverData.serverSocket.accept();
        auto clientSocket = std::get<0>(client);
        serverData.targets.push_back(clientSocket);
        struct TCPClientData clientData = {.serverData=&serverData, .clientSocket=clientSocket};
        if (pthread_create(&clientThread, nullptr, clientHandler, &clientData)) {
            clientSocket.close();
        }
    }
}

size_t TCPServer::send(void *target, char *buffer, size_t length, int flags) {
    Socket client = *(Socket *) target;
    return client.send(buffer, length, flags);
}

size_t TCPServer::receive(void *target, char *buffer, size_t length, int flags) {
    Socket client = *(Socket *) target;
    return client.recv(buffer, length, flags);
}

void *clientHandler(void *arg) {
    auto *clientData = (struct TCPClientData *) arg;
    auto serverData = clientData->serverData;
    auto clientSocket = clientData->clientSocket;
    while (true) {
        try {
            char buffer[BUFSIZ]{};
            size_t received = clientSocket.recv(buffer, BUFSIZ - 1, 0);
            if (!(strcmp(buffer, EXIT_MESSAGE)) || !received) {
                serverData->targets.remove(clientSocket);
                clientSocket.close();
                break;
            } else {
                std::cout << buffer << std::endl;
                for (auto conn : serverData->targets) {
                    if (conn != clientSocket) {
                        conn.send(buffer, received, 0);
                    }
                }
            }
        }
        catch (SocketException &e) {
            std::cout << e.getMessage() << std::endl;
            break;
        }
    }
    return nullptr;
}