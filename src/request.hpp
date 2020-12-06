#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "string_utils.hpp"
#include <map>

struct Request {

    const char* method;
    const char* schema;
    const char* path;

    std::map<std::string, std::vector<std::string>> headers;

    Request(const char* data_raw);
};

#endif
