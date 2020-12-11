#include "./request.hpp"
#include <iostream>

Request::Request(const char *raw_data) {

    auto data_string = std::string(raw_data);

    std::vector<std::string> lines = split(&data_string, "\r\n");

    auto first = lines.front();

    auto params = split(&first, " ");

    this->method = params.at(0).c_str();
    this->raw_path = params.at(1).c_str();
    this->schema = params.at(2).c_str();

    lines.erase(lines.begin());

    for (auto &line : lines) {

        std::vector<std::string> kv_pair = split(&line, ":");

        for (int i = 0; i < kv_pair.size(); i++) {
            std::cout << i << std::endl;
        }
    }
}
