#include "response.hpp"

std::string Response::result() {

    char buf[4096] = {0};

    snprintf(buf, 4096, "%s %s %s \r\n%s\r\n%s\r\n\r\n%s", this->http_scheme, this->status_code,
            this->status_text, "Server: CFastCfurious", "Content-Type: text/html", this->body.data());

    return std::string(buf);
}

Response::Response(std::string body) {
    this->body = body;
}

void Response::dump() {
    std::cout << "Status Code:\t" << this->status_code << std::endl << "Status Text:\t" 
        << this->status_text << std::endl;
}
