
#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;


int main(int argc, char const *argv[])
{
    int32_t a = 119;
    int32_t b = 12;
    int32_t result = 0;


    size_t cn = 0;

    int32_t temp = a;
    while (temp >= 0){
        temp <<= 1;
        cn++;
    }
    temp = b;
    temp <<= cn;
    cn = 0;
    while (temp >= 0){
        temp <<= 1;
        cn++;
    }
    cn++;
    b <<= cn;

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

    cout << a << endl;
    cout << result << endl;

    return 0;
}
