#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "../utils/string.hpp"
#include <vector>
#include <map>

#define CRLF "\r\n"

struct Request {

    const char* http_method;
    const char* schema;
    const char* raw_path;

    Request(const char* raw_data);
};

#endif
