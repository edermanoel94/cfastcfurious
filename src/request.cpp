#include "request.hpp"

Request Request::parse(const char *buffer) {

  std::string buffer_tmp(buffer);

  // iterate over the request line (initial_line)

  std::vector<std::string> lines = split(buffer_tmp, "\r\n");

  assert(lines.empty());

  std::string request_line = lines[0];

  Request req;
  return req;
}

void Request::dump() {}
