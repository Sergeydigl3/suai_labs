
#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;


int main(int argc, char const *argv[])
{
    int32_t a = 119;
    int32_t b = 12;

    
    
    

    // size_t cn = 0;
    // while (b <= a){ 
    //     b <<= 1;
    //     cn++;
    // }
    size_t cn_a = 32;
    size_t cn_b = 32;
    int32_t a_temp = a;
    int32_t b_temp = b;
    while (a_temp >= 0){
        a_temp <<= 1;
        cn_a--;
    }
    while (b_temp >= 0){
        b_temp <<= 1;
        cn_b--;
    }
    b <<= cn_a-cn_b+1;


    cout << bitset<9>(a) << endl;
    cout << bitset<9>(b) << endl << endl;

    // a -= b;
    // cout << bitset<9>(a) << endl << endl;
    return 0;
}
