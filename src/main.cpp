#include "cfastcfurious.hpp"

int main() {

    CFastCFurious::build("0.0.0.0", 8080)
       .run();

    return 0;
}
