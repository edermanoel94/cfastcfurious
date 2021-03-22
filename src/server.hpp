#ifndef CFASTCFURIOUS_HPP
#define CFASTCFURIOUS_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>

#include "utils/errors.hpp"
#include "http/Request.hpp"
#include "http/Response.hpp"

#define CONNECTIONS 256
#define BUF_SIZE 4096 
#define SERVER_NAME "CfastCFurious"

struct HTTPServer {

    int port;
    const char* ip_addr;

    int sockfd;

    HTTPServer();
    HTTPServer(const char* ip_addr, int port);
    ~HTTPServer();

    void run();

    void handler_conn(int sockfd_c);

    std::string read_html_from_path(const char* path);

    static HTTPServer build(const char* ip_addr, int port);
};

#endif
