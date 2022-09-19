// class for writing bytes to file with temp byte and function writeBits(int value, int bits)
#pragma once
#include <fstream>
#include <iostream>
#include <cstdint>

using namespace std;

class BitStreamFile
{
private:
    std::ofstream file;
    uint8_t temp;
    uint8_t bitPosition;
    size_t size;
    
public:
    void writeBits(uint32_t value, uint32_t bits);
    void writeByte(uint8_t value);
    void writeInt(uint32_t value);
    // write function as in fwrite
    void write(void* ptr, size_t size, size_t count);
    size_t getSize();

    BitStreamFile(std::string filename);
    ~BitStreamFile();
};
