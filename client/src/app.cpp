//
// Created by tal on 22/07/2020.
//

#include "socketwrapper/Socket.h"
#include "Client.h"
#include "TCPClient.h"
#include "UDPClient.h"

void *thread_func(void *arg);

//int main() {
//    char buffer[BUFSIZ];
////    struct sockaddr_in address;
////    address.sin_family = AF_INET;
////    address.sin_port = htons(3000);
////    address.sin_addr.s_addr = inet_addr("127.0.0.1");
////    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
////    connect(clientSocket, (struct sockaddr*)&address, sizeof address);
//    Socket clientSocket(AF_INET, SOCK_STREAM, 0);
//    clientSocket.connect("127.0.0.1", 3000);
//    while (true) {
//        memset(buffer, 0, BUFSIZ);
//        std::cin.getline(buffer, BUFSIZ - 1);
//        clientSocket.send(buffer, strlen(buffer), 0);
//        clientSocket.recv(buffer, BUFSIZ - 1, 0);
//        //recv(clientSocket, buffer, BUFSIZ - 1, 0);
//        std::cout << "Server sent: " << buffer << std::endl;
//    }
//    //clientSocket.close();
//}
constexpr auto ARGUMENT_ERROR = "Enter 'tcp' for a TCP client, or 'udp' for a UDP client";
constexpr auto TCP_PROTOCOL = "tcp";
constexpr auto UDP_PROTOCOL = "udp";

void *receive_handler(void *arg);

int main(int argc, char *argv[]) {
    Client *client;
    const char *ip = "127.0.0.1";
    int port = 3000;
    if (argc < 2) {
        std::cout << ARGUMENT_ERROR << std::endl;
        exit(1);
    }
    std::string protocol(argv[1]);
    if (protocol != TCP_PROTOCOL && protocol != UDP_PROTOCOL) {
        std::cout << ARGUMENT_ERROR << std::endl;
        exit(1);
    }
    client = (protocol == TCP_PROTOCOL) ? reinterpret_cast<Client *>(new TCPClient(ip, port))
                                        : reinterpret_cast<Client *>(new UDPClient(ip, port));
    pthread_t thread;
    pthread_create(&thread, nullptr, receive_handler, client);
    while (true) {
        char buffer[BUFSIZ]{};
        std::cin.getline(buffer, BUFSIZ - 1);
        if (!strcmp(buffer, "@exit")) {
            break;
        }
        if (!strcmp(buffer, "")) {
            continue;
        }
        client->send(buffer, BUFSIZ, 0);
    }
    client->close();
    delete client;
}

void *receive_handler(void *arg) {
    auto *client = (Client *) arg;
    while (true) {
        char buffer[BUFSIZ];
        size_t received = client->receive(buffer, BUFSIZ - 1, 0);
        if (!received) {
            client->close();
            break;
        }
        std::cout << buffer << std::endl;
    }
    return nullptr;
}
