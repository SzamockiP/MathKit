#include "bigint.h"

BigInt::BigInt(){
    _initialized = false;
}

BigInt::BigInt(int value){
    _initialized = true;
    _data.push_back(value);
}

BigInt::BigInt(std::vector<uint32_t> data){
    _initialized = true;
    _data = data;
}


BigInt BigInt::operator+(int other) const {
    BigInt new_bigInt(_data);
    uint64_t operation_buffor = other;
    size_t position = 0;

    while(operation_buffor > 0){
        // If space is needed, make bigger container
        if(new_bigInt._data.size() <= position){
            new_bigInt._data.push_back(0);
        }
        // add data to buffor
        operation_buffor += new_bigInt._data[position];
        // push later half to new data
        new_bigInt._data[position] = operation_buffor;
        // bit push for half to the right, so it may become new data
        operation_buffor >>= 32;
        position++;
    }

    return new_bigInt;
}


std::ostream& operator<<(std::ostream& os, const BigInt& big_int)
{
	for(auto &value : big_int._data){
        os<<value;
    }
    return os;
}
