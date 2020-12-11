#include "cfastcfurious.hpp" 

CFastCFurious::CFastCFurious() {
}

CFastCFurious::~CFastCFurious() = default;

void CFastCFurious::run(const char* addr) {

    // Create a socket
    auto listening = socket(AF_INET, SOCK_STREAM, 0);

    if (listening == -1) {
        panic("Cannot create socket");
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(8000);

    // Make the family address to listen on any ip of host machine
    if (inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr) == -1) {
        panic("Invalid address family on IPv4"); 
    }

    // Make a bind with address to the socket
    if (bind(listening, (sockaddr *)&hint, sizeof(hint)) == -1) {
        panic("Cannot bind the socket with address");
    }

    if (listen(listening, CONNECTIONS) == -1) {
        panic("Cannot listen on the socket");
    }

    // receive a request from client
    sockaddr_in sockaddr_cli;
    socklen_t socklen_cli = sizeof(sockaddr_cli);

    auto sock_cli = accept(listening, (sockaddr *) &sockaddr_cli, &socklen_cli);

    char response[256 + NI_MAXHOST + NI_MAXSERV];

    client_info(&sockaddr_cli, response);

    close(listening);

    char buffer[BUF_SIZE];

    memset(buffer, 0, BUF_SIZE);

    auto bytes_recv = recv(sock_cli, buffer, sizeof(buffer), 0);

    if (bytes_recv == -1) {
        panic("Error on read bytes from client");
    }

    Request req(buffer);

//    char* page_content = get_content_page(&req);

    close(sock_cli);
}

void panic(const char* error_msg) {
    std::cerr << error_msg << std::endl;
    exit(-1);
}

void client_info(const sockaddr_in* sockaddr_cli, char* response) {

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    // fill array with 0 bytes
    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if(getnameinfo((sockaddr *) sockaddr_cli, sizeof(*sockaddr_cli), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        sprintf(response, "connected on %s:%s", host, service);
    } else {
        inet_ntop(AF_INET, &sockaddr_cli->sin_addr, host, NI_MAXHOST);
        sprintf(response, "connected on %s:%d", host, ntohs(sockaddr_cli->sin_port));
    }
}

char* get_content_page(const Request* request) {

    return NULL;
}
