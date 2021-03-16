#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>

#include "../utils/string.hpp"

#include "identifiers.hpp"

struct Request {

    const char* method;
    const char* raw_path;
    const char* http_scheme;

    Request(const char* buffer);

    void dump();
};

#endif
