#include "server.hpp"

int main() {

    HTTPServer::build("0.0.0.0", 8080)
       .run();

    return 0;
}
