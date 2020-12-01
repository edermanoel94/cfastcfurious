#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "string.h"
#include <iostream>

struct Request {

    char* method;
    char* schema;
    char* host;
    char* path;

    Request(char* raw_data);
};

#endif
