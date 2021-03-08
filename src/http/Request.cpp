#include "Request.hpp"

Request::Request(const char* buffer) {

    std::string buffer_str = std::string(buffer);

    auto lines = split(buffer_str, "\r\n");

    auto request_line = lines[0];

    auto req_line_word = split(request_line, " ");
    
    this->method = req_line_word[0].c_str();
    
    if (!req_line_word[1].empty()) {
        this->raw_path = req_line_word[1].c_str();
    }

    if (!req_line_word[2].empty()) {
        this->http_scheme = req_line_word[2].c_str();
    }
}
