#include "bitstreamfile/bitstream.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    BitStreamFileR file("test.bin", 8192);
    file.readBit();
    file.readBit();
    cout << file.readBit() << endl;
    file.clearTemp();

    file.readBit();
    file.readBit();
    cout << file.readBit() << endl;
    file.clearTemp();

    file.readBit();
    cout << file.readBit() << endl;
    file.clearTemp();

    return 0;
}
