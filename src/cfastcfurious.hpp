#ifndef CFASTCFURIOUS_HPP
#define CFASTCFURIOUS_HPP

#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#include "http/request.hpp" 

#define CONNECTIONS 256
#define BUF_SIZE 4096 

struct CFastCFurious {

    CFastCFurious();

    ~CFastCFurious();

    static void run(const char* addr);
};

void panic(const char* error_msg);

void client_info(const sockaddr_in* sockaddr_cli, char* response);

char* get_content_page(const Request* request);

#endif
