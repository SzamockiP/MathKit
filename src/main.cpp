#include "bigint.h"
#include <iostream>

int main() {
    BigInt big_int(4294967295);

    std::cout<<(big_int + 123);
}