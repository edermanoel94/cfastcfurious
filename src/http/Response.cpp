#include "Response.hpp"

Response::Response(const char* body) {
    this->body = body;
}

std::string Response::result() {

    std::string result; 

    result += this->http_scheme;
    result += " ";
    result += this->status_code;
    result += " ";
    result += this->status_text;
    result += "\r\n";
    result += "Server: CfastCFurious";
    result += "\r\n";
    result += "Content-Type: text/html";
    result += "\r\n\r\n";
    result += this->body;

    return result;
}
