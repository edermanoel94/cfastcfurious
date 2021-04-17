#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "identifiers.hpp"
#include "string.hpp"
#include "assert.h"

struct Request {

  const char *method;
  const char *raw_path;
  const char *http_scheme;

  static Request parse(const char *buffer);

  void dump();
};

#endif
