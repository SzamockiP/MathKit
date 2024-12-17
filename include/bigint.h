#pragma once
#include <vector>
#include <iostream>



class BigInt
{
public:
    BigInt();
    BigInt(int);
    BigInt(std::vector<uint32_t> data);

    BigInt operator+(int other) const;


    friend std::ostream& operator<<(std::ostream&, const BigInt&);
    

private:
    bool _initialized;
    std::vector<uint32_t> _data;

    // We'll need
    // - addition(this + int)
    // - addition(this + bigint)
};