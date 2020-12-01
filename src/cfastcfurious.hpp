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
#include <string>

#include "request.hpp" 

#define SERVER_PORT 8000
#define CONNECTIONS 256
#define BUF_SIZE 4096 

void panic(const char* error_msg);

void client_info(const sockaddr_in* sockaddr_cli, char* response);

char* get_content_page(const Request* request);

#endif
