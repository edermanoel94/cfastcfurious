#include "server.hpp"

HTTPServer::HTTPServer() {}

HTTPServer::HTTPServer(const char* ip_addr, int port) {
    this->ip_addr = ip_addr;
    this->port = port;
}

HTTPServer::~HTTPServer() {
    close(this->sockfd);
}

HTTPServer HTTPServer::build(const char* ip_addr, int port) {
    return HTTPServer(ip_addr, port);
}

void HTTPServer::run() {

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

        if (sockfd_c == -1) {
            error("Cannot accept connection");
            continue;
        }

        this->handler_conn(sockfd_c);
    }
}

void HTTPServer::handler_conn(int sockfd_c) {

    char buffer[BUF_SIZE] = {0};

    auto bytes_recv = read(sockfd_c, buffer, BUF_SIZE);

    if (bytes_recv == -1) {
        error("Error on read bytes from client");
        return;
    }

    Request req(buffer);
    Response resp;

    req.dump();

    if (strcmp(req.method, METHOD_GET)) {

        std::string html = read_html_from_path(req.raw_path);

        write(sockfd, html.c_str(), BUF_SIZE);
    }

    close(sockfd_c);
}

std::string HTTPServer::read_html_from_path(const char* path) {

    FILE* file = fopen(path, "r");

    if (file == NULL) {
        error("cannot read file");
        return NULL;
    }

    char buf[BUF_SIZE];

    fscanf(file, "%s", buf);

    return std::string(buf);
}
