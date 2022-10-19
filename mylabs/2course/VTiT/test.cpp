
#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char const *argv[])
{

    // Division of unsigned integers to obtain an integer with the restoration of the remainder with a fixed divisor and a shift operator of the divisible without div and mod
    uint32_t a = 60;
    uint32_t b = 13;
    // do not use uint32_t c = a / b;
    uint32_t c = a >> 2;
    cout << c << endl;
    

    return 0;
}
