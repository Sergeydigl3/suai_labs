#include <cstdint>
#include <iostream>
#include <bitset>

using namespace std;
uint8_t bitPosition = 0;
uint8_t temp = 222;
void write_tobitstream(uint32_t value, uint32_t bits) {
    // write bits to temp byte from left (big position) to right (small position)
    for (uint32_t i = 0; i < bits; ++i) {
        uint8_t mask = ((value >> (bits-i-1)) & 1) << (7-bitPosition);
        // cout << "mask: " << bitset<8>(mask) << endl;
        temp |= mask;
        ++bitPosition;
        if (bitPosition == 8) {
            cout << bitset<8>(temp) << endl;
            temp = 0;
            bitPosition = 0;
        }
    }
    
    

    // print temp in binary
    cout << bitset<8>(temp) << endl;
}


uint32_t readBits(uint32_t bits) {
    uint32_t i;
    uint32_t value = 0;
    // save current position in file
    for (i = 0; i < bits; ++i) {
        if (bitPosition == 0) {
            temp = 222;
            cout << bitset<8>(temp) << endl;
        }

        value |= ((temp >> (7-bitPosition)) & 1) << (bits-i-1);
        ++bitPosition;
        if (bitPosition == 8) {
            bitPosition = 0;
        }
    }
    // return to starting position
    return value;
}

int main(int argc, char const* argv[])
{
    // write_tobitstream(6, 3);
    // write_tobitstream(7, 3);
    // write_tobitstream(2, 2);
    // write_tobitstream(2, 2);
    // write_tobitstream(2, 2);
    cout << bitset<3>(readBits(3)) << endl;
    cout << bitset<3>(readBits(3)) << endl;
    cout << bitset<2>(readBits(2)) << endl;
    cout << bitset<3>(readBits(3)) << endl;
    return 0;
}
