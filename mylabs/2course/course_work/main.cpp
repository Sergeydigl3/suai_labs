#include <iostream>
#include <cstring>
#include "test.hpp"
#include <fstream>

using namespace std;

int main(int argc, char const* argv[])
{
    ifstream f("book.txt");
    std::string str((std::istreambuf_iterator<char>(f)),
                  std::istreambuf_iterator<char>());
    f.close();
    
    uint8_t* originalData = (uint8_t*)str.c_str();
    int originalDataSize = strlen(str.c_str());
    uint8_t* compressedData = new uint8_t[originalDataSize * (101 / 100) + 384];
    
    int compressedDataSize = Compress(originalData, compressedData, originalDataSize);
    return 0;
}

