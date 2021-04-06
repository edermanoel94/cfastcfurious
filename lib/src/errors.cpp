#include "errors.hpp"

void panic(const char* msg) {
    std::cerr << msg << std::endl;
    exit(-1); 
} 

void error(const char* msg) {
    std::cerr << msg << std::endl;
}
