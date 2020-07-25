//
// Created by tal on 22/07/2020.
//

//#include "socketwrapper/Socket.h"
#include "Server.h"
#include "TCPServer.h"
#include "UDPServer.h"

constexpr auto ARGUMENT_ERROR = "Enter 'tcp' for a TCP client, or 'udp' for a UDP client";
constexpr auto TCP_PROTOCOL = "tcp";
constexpr auto UDP_PROTOCOL = "udp";
constexpr auto SERVER_IP = "0.0.0.0";
constexpr auto SERVER_PORT = 3000;

int main(int argc, char *argv[]) {
    Server *server;
    const char *ip = SERVER_IP;
    int port = SERVER_PORT;
    if (argc < 2) {
        std::cout << ARGUMENT_ERROR << std::endl;
        exit(1);
    }
    std::string protocol(argv[1]);
    if (protocol != TCP_PROTOCOL && protocol != UDP_PROTOCOL) {
        std::cout << ARGUMENT_ERROR << std::endl;
        exit(1);
    }
    try {
        server = (protocol == TCP_PROTOCOL) ? reinterpret_cast<Server *>(new TCPServer(ip, port))
                                            : reinterpret_cast<Server *>(new UDPServer(ip, port));
        server->start();
        delete server;
    }
    catch (SocketException &e) {
        std::cout << e.getMessage() << std::endl;
    }
}