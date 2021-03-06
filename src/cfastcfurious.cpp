#include "cfastcfurious.hpp"
#include "utils/errors.hpp"

CFastCFurious::CFastCFurious() {}

CFastCFurious::CFastCFurious(const char* ip_addr, int port) {
    this->ip_addr = ip_addr;
    this->port = port;
}

CFastCFurious::~CFastCFurious() = default;

CFastCFurious CFastCFurious::build(const char* ip_addr, int port) {
    return CFastCFurious(ip_addr, port);
}

void CFastCFurious::run() {

    auto listening = socket(AF_INET, SOCK_STREAM, 0);

    if (listening == -1) {
        panic("Cannot create socket");
    }

    sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(this->port);

    if (inet_pton(AF_INET, this->ip_addr, &sock_addr.sin_addr) == -1) {
        panic("Invalid address family on IPv4");
    }

    if (bind(listening, (sockaddr *)&sock_addr, sizeof(sock_addr)) == -1) {
        panic("Cannot bind the socket with address");
    }

    if (listen(listening, CONNECTIONS) == -1) {
        panic("Cannot listen on the socket");
    }

    while(true) {

        sockaddr_in sockadd_client;
        socklen_t socketlen_client = sizeof(sockadd_client);

        auto sock_client = accept(listening, (sockaddr *)&sockadd_client, &socketlen_client);

        char buffer[BUF_SIZE] = {0};

        auto bytes_recv = read(sock_client, buffer, BUF_SIZE);

        if (bytes_recv == -1) {
            error("Error on read bytes from client");
            continue;
        }

        Request req(buffer);

        close(sock_client);
    }
}

