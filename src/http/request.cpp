#include "./request.hpp"
#include <iostream>

Request::Request(const char *request_data) {

  auto request_data_str = std::string(request_data);

  std::vector<std::string> lines = split_crlf(request_data_str);

  std::string request_line = lines.front();

  std::cout << request_line << std::endl;

  std::vector<std::string> request_line_args = split(&request_line, " ");

  std::cout << request_line_args[0] << std::endl;
  std::cout << request_line_args[1] << std::endl;
  std::cout << request_line_args[2] << std::endl;

  this->http_method = request_line_args[0].c_str();
  this->raw_path = request_line_args[1].c_str();
  this->schema = request_line_args[2].c_str();
}
