#include <iostream>

using namespace std;

// function to calculate capacity in bytes
uint8_t bits_to_byte(uint32_t bits) {
    return (bits + 7) / 8;
}

// int main() {

//     uint8_t temp = 63;
//     unsigned char test = 15;

//     return 0;
// }

int main(int argc, char const* argv[])
{
    uint8_t temp = 16;
    // uint8_t temp_byte = 0;   
    // while (temp > 1) {
    //     temp = temp >> 1;
    //     temp_byte++;
    // }
    cout << static_cast<unsigned>(bits_to_byte(temp)) << endl;
    return 0;
}
