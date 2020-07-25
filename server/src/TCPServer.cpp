//
// Created by tal on 22/07/2020.
//

#include "TCPServer.h"

void *connectionHandler(void *arg);

void *clientHandler(void *arg);

TCPServer::TCPServer(const char *ip, int port) : Server(AF_INET, SOCK_STREAM, 0) {
    m_socket.bind(ip, port);
    m_socket.listen(10);
}

void TCPServer::start() {
    pthread_t connectionThread;
    struct ServerData data = {.server=m_socket, .targets=std::list<void *>()};
    pthread_create(&connectionThread, nullptr, connectionHandler, &data);
    pthread_join(connectionThread, nullptr);
}

size_t TCPServer::send(void *target, char *buffer, size_t length, int flags) {
    Socket client = *(Socket *) target;
    return client.send(buffer, length, flags);
}

size_t TCPServer::receive(void *target, char *buffer, size_t length, int flags) {
    Socket client = *(Socket *) target;
    return client.recv(buffer, length, flags);
}

void TCPServer::removeClient(struct ServerData *serverData, void *client) {
    Socket* clientSocket = (Socket*)client;
    for (auto *conn : serverData->targets) {
        if (conn == client) {
            serverData->targets.remove(conn);
            clientSocket->close();
        }
    }
}

void *connectionHandler(void *arg) {
    auto *serverData = (struct ServerData *) arg;
    while (true) {
        std::tuple<Socket, const char *> client = serverData->server.accept();
        Socket clientSocket = std::get<0>(client);
        serverData->targets.push_back(&clientSocket);
        const char *clientAddress = std::get<1>(client);
        std::cout << "Received connection from " << clientAddress << std::endl;

        struct ClientData clientData = {.data=serverData, .client=&clientSocket};
        pthread_t clientThread;
        pthread_create(&clientThread, nullptr, clientHandler, &clientData);
    }
    return nullptr;
}

void *clientHandler(void *arg) {
    auto *clientData = (struct ClientData *) arg;
    char buffer[BUFSIZ];
    while (true) {
        auto* clientSocket = (Socket*)clientData->client;
        size_t received = clientSocket->recv(buffer, BUFSIZ - 1, 0);
        buffer[received] = 0;
        if (!(strcmp(buffer, "@exit"))) {
            std::cout << "A client has disconnected" << std::endl;
            TCPServer::removeClient(clientData->data, clientData->client);
            break;
        }
        else {
            std::cout << buffer << std::endl;
            for (auto* conn : clientData->data->targets) {
                if (conn != clientData->client) {
                    clientSocket->send(buffer, received, 0);
                }
            }
        }
    }
    return nullptr;
}