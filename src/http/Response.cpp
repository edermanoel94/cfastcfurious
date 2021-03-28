#include "Response.hpp"

Response::Response(std::string body) {
    this->body = body;
}

std::string Response::result() {

    char buf[4096] = {0};

    snprintf(buf, 100, "%s %s %s \r\n%s\r\n\r\n%s", this->http_scheme, this->status_code,
            this->status_text, "Server: CFastCfurious", this->body.c_str());


    return std::string(buf);
}
