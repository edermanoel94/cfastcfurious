#include "cfastcfurious.hpp"

CFastCFurious::CFastCFurious() {}

CFastCFurious::CFastCFurious(const char* ip_addr, int port) {
    this->ip_addr = ip_addr;
    this->port = port;
}

CFastCFurious::~CFastCFurious() {
    close(this->sockfd);
}

CFastCFurious CFastCFurious::build(const char* ip_addr, int port) {
    return CFastCFurious(ip_addr, port);
}

void CFastCFurious::run() {

    this->sockfd =  socket(AF_INET, SOCK_STREAM, 0);

    if (this->sockfd == -1) {
        panic("Cannot create socket");
    }

    sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(this->port);

    if (inet_pton(AF_INET, this->ip_addr, &sock_addr.sin_addr) == -1) {
        panic("Invalid address family on IPv4");
    }

    if (bind(this->sockfd, (sockaddr *)&sock_addr, sizeof(sock_addr)) == -1) {
        panic("Cannot bind the socket with address");
    }

    if (listen(this->sockfd, CONNECTIONS) == -1) {
        panic("Cannot listen on the socket");
    }

    while(true) {

        sockaddr_in sockaddr_c;
        socklen_t socklen_c = sizeof(sockaddr_c);

        int sockfd_c = accept(this->sockfd, (sockaddr *)&sockaddr_c, &socklen_c);

        this->handler_conn(sockfd_c);
    }
}

void CFastCFurious::handler_conn(int sockfd_c) {

    char buffer[BUF_SIZE] = {0};

    auto bytes_recv = read(sockfd_c, buffer, BUF_SIZE);

    if (bytes_recv == -1) {
        error("Error on read bytes from client");
        return;
    }

    char response[BUF_SIZE] = {0};

    this->handler_request(buffer, response);

    write(sockfd_c, buffer, BUF_SIZE);
    
    close(sockfd_c);
}

void CFastCFurious::handler_request(const char* buffer, const char* response) {
    const char* start_line = "HTTP/1.1 200 OK \r\n";
    const char* blank_line = "\r\n";
    const char* body = "Request received";
    strncat(response, start_line, BUF_SIZE);
}
