#include "bigint.h"
#include <iostream>

int main() {
    BigInt big_int(4294967295);

    BigInt value;
    value = big_int;
    std::cout<<(value) << std::endl;
 
    value = big_int + big_int;
    std::cout<<(value) << std::endl;
 
    value = big_int + big_int + big_int;
    std::cout<<(value) << std::endl;
 
    value = big_int + big_int + big_int + big_int;
    std::cout<<(value) << std::endl;
}