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

void BigInt::setData(std::vector<uint32_t> data){
    _initialized = true;
    _data = data;
}

BigInt BigInt::operator+(int other) const {
    if(!_initialized) {
        throw std::logic_error("Operation on uninitialized object");
    }
    BigInt new_bigInt(_data);
    uint64_t buffor = other;
    size_t position = 0;

    while(buffor > 0){
        // If space is needed, make bigger container
        if(new_bigInt._data.size() <= position){
            new_bigInt._data.push_back(0);
        }
        // add data to buffor
        buffor += new_bigInt._data[position];
        // push later half to new data
        new_bigInt._data[position] = buffor;
        // bit push for half to the right, so it may become new data
        buffor >>= 32;
        position++;
    }

    return new_bigInt;
}

BigInt BigInt::operator+(BigInt const& other) const {
    // guard case
    if(!_initialized || !other._initialized) {
        throw std::logic_error("Operation on uninitialized object");
    }

    BigInt new_bigInt;
    uint64_t buffor = 0;
    size_t size;
    size_t position;

    if(_data.size() > other._data.size()){
        new_bigInt.setData(_data);
        size = other._data.size();
    }
    else {
        new_bigInt.setData(other._data);
        size = _data.size();
    }
        
    // bigint + bigint
    for(position = 0; position < size; position++){
        buffor = _data[position];
        buffor += other._data[position];
        new_bigInt._data[position] = buffor;
        buffor >>= 32;
    }

    // bigint + int
    while(buffor > 0){
        if(new_bigInt._data.size() <= position){
            new_bigInt._data.push_back(0);
        }
        buffor += new_bigInt._data[position];
        new_bigInt._data[position] = buffor;
        buffor >>= 32;
        position++;
    }
    
    return new_bigInt;
}

std::ostream& operator<<(std::ostream& os, const BigInt& big_int)
{
	for(auto &value : big_int._data){
        os<<value<<'|';
    }
    return os;
}
