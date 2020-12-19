#include "./request.hpp"
#include <iostream>

Request::Request(const char *raw_data) {

  auto raw_data_str = std::string(raw_data);

  std::vector<std::string> lines = split_crlf(raw_data_str);

  auto first = lines.front();

  auto params = split(&first, " ");

  this->method = params[0].c_str();
  this->raw_path = params[1].c_str();
  this->schema = params[2].c_str();

  lines.erase(lines.begin());

  for (auto &line : lines) {


  }
}
