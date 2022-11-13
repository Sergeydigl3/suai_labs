
#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;

int main(int argc, char const* argv[])
{

    // Division of unsigned integers to obtain an integer with the restoration of the remainder with a fixed divisor and a shift operator of the divisible without div and mod
    int32_t a = 119;
    int32_t b = 12;

    int32_t result = 0;
    

    size_t cn = 0;
    while (b <= a){ 
        b <<= 1;
        cn++;
    }
    
    cout << bitset<9>(a) << endl;
    cout << bitset<9>(b) << endl << endl;

    for(int i = 0; i < cn; i++)
    {   
        a<<=1;

        
        a -= b;
        result <<= 1;
        if (a < 0) {
            a += b;
        } else {
            result |= 1;
        }

    }
    a >>= cn;
    // cout << bitset<9>(a) << endl;
    cout << a << endl;
    // cout << bitset<9>(result) << endl;
    cout << result << endl;
    return 0;
}