#ifndef CFASTCFURIOUS_HPP
#define CFASTCFURIOUS_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

#include "utils/errors.hpp"

#define CONNECTIONS 256
#define BUF_SIZE 4096 

struct CFastCFurious {

    int port;
    const char* ip_addr;

    int sockfd;

    CFastCFurious();
    CFastCFurious(const char* ip_addr, int port);
    ~CFastCFurious();

    void run();

    void handler_conn(int sockfd_c);

    void handler_request(const char* buffer, const char* response);

    static CFastCFurious build(const char* ip_addr, int port);
};

#endif
