#include "string.hpp"

std::vector<std::string> split(std::string *str, const char *sep) {

  std::vector<std::string> strs;

  size_t pos = str->find(sep);

  size_t initial_pos = 0;

  while (pos != std::string::npos) {

    strs.push_back(str->substr(initial_pos, pos - initial_pos));

    initial_pos = pos + 1;

    pos = str->find(sep, initial_pos);
  }

  strs.push_back(
      str->substr(initial_pos, std::min(pos, str->size()) - initial_pos + 1));

  return strs;
}

std::vector<std::string> split_crlf(std::string &str) {

  std::istringstream str_stream(str);

  std::vector<std::string> arr_temp;

  std::string str_temp;

  while (std::getline(str_stream, str_temp))
    arr_temp.push_back(str_temp);

  return arr_temp;
}
