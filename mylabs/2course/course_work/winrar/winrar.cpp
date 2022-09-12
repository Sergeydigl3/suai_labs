#include "winrar.hpp"
#include <fstream>
#include <iostream>

int winrar::compress(std::string& filename)
{
    std::ifstream f(filename);
    std::string str((std::istreambuf_iterator<char>(f)),
                  std::istreambuf_iterator<char>());
    f.close();
    
    uint8_t* originalData = (uint8_t*)str.c_str();
    int originalDataSize = strlen(str.c_str());
    uint8_t* compressedData = new uint8_t[originalDataSize * (101 / 100) + 384];
    
    int compressedDataSize = Compress(originalData, compressedData, originalDataSize);
    return 0;
}

int winrar::decompress(std::string& filename)
{
    return 0;
}