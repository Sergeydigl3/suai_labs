
#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;


int main(int argc, char const *argv[])
{
    int32_t a = 41;
    int32_t b = 1;
    int32_t result = 0;


    size_t cn = 0;

    int32_t temp = a;

    cout << bitset<32>(a) << endl;
    cout << bitset<32>(b) << endl;

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

    cout << bitset<32>(a) << endl;
    cout << bitset<32>(b) << endl;

    b>>=1;
    for(int i = 0; i < cn; i++)
    {   
        

        a -= b;
        result <<= 1;
        if (a < 0) {
            cout << "a < 0" << endl;
            b>>=1;
            a += b;
        } else {
            b>>=1;
            result |= 1;
        }
        cout << "After: " << bitset<32>(a) << endl;
        cout << "After: " << bitset<32>(b) << endl << endl;
    }
    a >>= cn;

    cout << a << endl;
    cout << result << endl;

    return 0;
}
