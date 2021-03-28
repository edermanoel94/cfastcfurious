#include "server.hpp"

HTTPServer::HTTPServer() {}

HTTPServer::HTTPServer(std::string ipaddr, int port) {
    this->ipaddr = ipaddr;
    this->port = port;
}

HTTPServer::~HTTPServer() = default;

HTTPServer HTTPServer::build(std::string ipaddr, int port) {
    return HTTPServer(ipaddr, port);
}

void HTTPServer::run() {

    this->sockfd =  socket(AF_INET, SOCK_STREAM, 0);

    if (this->sockfd == -1) {
        close(this->sockfd);
        panic("Cannot create socket");
    }

    sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(this->port);

    if (inet_pton(AF_INET, this->ipaddr.c_str(), &sock_addr.sin_addr) == -1) {
        close(this->sockfd);
        panic("Invalid address family on IPv4");
    }

    if (bind(this->sockfd, (sockaddr *)&sock_addr, sizeof(sock_addr)) == -1) {
        close(this->sockfd);
        panic("Cannot bind the socket with address");
    }

    if (listen(this->sockfd, CONNECTIONS) == -1) {
        close(this->sockfd);
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

    // TODO: implements a Buffer
    char buffer[BUF_SIZE] = {0};

    auto bytes_recv = read(sockfd_c, buffer, BUF_SIZE);

    if (bytes_recv == -1) {
        error("Error on read bytes from client");
        close(sockfd_c);
        return;
    }

    Request req = Request::parse(buffer);

    std::string html = read_html_from_path(req.raw_path);

    Response resp(html);

    std::string result = resp.result();

    send(sockfd_c, result.data(), strlen(result.data()), 0);

    close(sockfd_c);
}

std::string HTTPServer::read_html_from_path(std::string path) {

    std::ifstream file("public.html");

    std::string line, result;

    while(std::getline(file, line)) {

        result += line;
    }

    return result;
}
