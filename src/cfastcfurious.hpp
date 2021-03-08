#ifndef CFASTCFURIOUS_HPP
#define CFASTCFURIOUS_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>

#include "utils/errors.hpp"
#include "http/Request.hpp"
#include "http/Response.hpp"

#define CONNECTIONS 256
#define BUF_SIZE 4096 
#define SERVER_NAME "CfastCFurious"

struct CFastCFurious {

    int port;
    const char* ip_addr;

    int sockfd;

    CFastCFurious();
    CFastCFurious(const char* ip_addr, int port);
    ~CFastCFurious();

    void run();

    void handler_conn(int sockfd_c);

    void serve(Response resp, Request* request);

    static CFastCFurious build(const char* ip_addr, int port);
};

#endif
