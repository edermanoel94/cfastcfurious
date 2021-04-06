#ifndef CFASTCFURIOUS_HPP
#define CFASTCFURIOUS_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string>
#include <cstring>
#include <fstream>

#include "utils/errors.hpp"
#include "http/Request.hpp"
#include "http/Response.hpp"

#define CONNECTIONS 256
#define BUF_SIZE 4096 

struct HTTPServer {

    int port;
    std::string ipaddr;

    int sockfd;

    HTTPServer();
    HTTPServer(std::string ipaddr, int port);
    ~HTTPServer();

    void run();

    void handler_conn(int sockfd_c);

    std::string read_html_from_path(std::string path);

    static HTTPServer build(std::string ipaddr, int port);
};

#endif
