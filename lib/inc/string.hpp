#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <istream>
#include <iostream>

std::vector<std::string> split(std::string& str, const char* sep);

std::vector<std::string> split_crlf(std::string& str);

#endif
