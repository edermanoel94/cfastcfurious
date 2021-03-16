#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>

#include "identifiers.hpp"

struct Response {
    
    const char* http_scheme = HTTP_V1_1;
    const char* status_code = "200";
    const char* status_text = "OK";

    const char* body;

    std::string mount();
};

#endif
