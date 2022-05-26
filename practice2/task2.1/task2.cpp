typedef unsigned long long uint64;
typedef unsigned char uint8;

static uint64 code_table[] = { 0x00, 0x0d, 0x16, 0x1b /* 0x1f */ };

#include <iostream>
using namespace std;

uint64 count_ones(uint64 n) {
    uint64 w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}

uint64 hamming(uint64 a, uint64 b) { return count_ones(a ^ b); }

int min_hamming(uint64* arr, int size) {
    int minim = size;
    for (uint64 a = 0; a < size; a++) {
        for (uint64 b = a + 1; b < size; b++) {
            if (arr[a] != arr[b]) {
                int hamm = hamming(arr[a], arr[b]);
                minim = hamm < minim ? hamm : minim;
            }
        }
    }
    return minim;
}

int main() {
    uint64 min_h = min_hamming(code_table, sizeof(code_table)/sizeof(uint64));
    cout << "min hamming distance: " << min_h << endl;
}