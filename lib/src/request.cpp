#include "Request.hpp"

Request Request::parse(const char* buffer) {

    Request req;

    std::string buffer_str = std::string(buffer);

    auto lines = split(buffer_str, "\r\n");

    auto request_line = lines[0];

    auto req_line_word = split(request_line, " ");
    
    if (!req_line_word[0].empty()) {
        req.method = req_line_word[0].c_str();
    }

    if (!req_line_word[1].empty()) {
        req.raw_path = req_line_word[1].c_str();
    }

    if (!req_line_word[2].empty()) {
        req.http_scheme = req_line_word[2].c_str();
    }

    return req;
}

void Request::dump() {
    std::cout << "Path:\t" << this->raw_path << std::endl << "Method:\t" 
        << this->method << std::endl;
}
