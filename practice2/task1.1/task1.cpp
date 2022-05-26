#include <iostream>
#include <string>

using namespace std;

static unsigned char code_table[] = {0x00, 0x0d, 0x16, 0x1b}; //1f

unsigned char coder(unsigned char m) {
  return code_table[m];
}

unsigned char channel(unsigned char a, unsigned char e) {
  return a ^ e;
}

unsigned char count_ones(unsigned char n) {
  unsigned char w = 0;
  while (n > 0) {
    w += n & 1;
    n = n >> 1;
  }
  return w;
}

unsigned char hamming(unsigned char a, unsigned char b) {
  return count_ones(a ^ b);
}

unsigned char decoder(unsigned char m) {
  unsigned char ind = 0, min = 5;
  for (unsigned char i = 0; i < 4; i++) {
    unsigned char d = hamming(m, code_table[i]);
    if (d < min) {
      min = d;
      ind = i;
    }
  }
  return ind;
}

void printf_bin(unsigned char n) {  
  for (unsigned char i = 0; i < 5; i++)
    printf("%d", (n >> (4 - i)) & 1);
}
string str_bin(unsigned char n) {
    string ret_str;
    for (unsigned char i = 0; i < 5; i++)
        ret_str += to_string((n >> (4 - i)) & 1);
    return ret_str;
}
int main() {
    unsigned long long m, e, w, c, d;
    cin >> m >> e;
    w = coder (m);
    c = channel(w, e);
    d = decoder(c);
    cout << "m: " << str_bin(m) << endl;
    cout << "w: " << str_bin(w) << endl;
    cout << "e: " << str_bin(e) << endl;
    cout << "c: " << str_bin(c) << endl;
    cout << "d: " << str_bin(d) << endl;
}