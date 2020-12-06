#include "request.hpp"

Request::Request(const char* data_raw) {

    auto data_string = std::string(data_raw);

    std::vector<std::string> lines = split(data_string, "\r\n");

    auto first = lines.front();

    auto params = split(first, " ");

    this->method = params.at(0).c_str();
    this->path = params.at(1).c_str();
    this->schema = params.at(2).c_str();

    lines.erase(lines.begin());

    for (auto& line: lines) {

        auto column = split(line, " ");
    }
}

