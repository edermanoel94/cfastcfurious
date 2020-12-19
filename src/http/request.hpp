#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "../utils/string.hpp"
#include <vector>
#include <map>

#define CRLF "\r\n"

struct Request {

    const char* method;
    const char* schema;
    const char* raw_path;

    std::map<std::string, std::vector<std::string>> headers;

    Request(const char* raw_data);
};

#endif
