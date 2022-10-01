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
    void writeBits(uint64_t value, uint32_t bits);

    void write(void* ptr, size_t size, size_t count);

    size_t getSize();

    BitStreamFile(std::string filename);
    ~BitStreamFile();
};

// class BitStreamFileR for reading
class BitStreamFileR
{
private:
    std::ifstream file;
    uint8_t temp;
    uint8_t bitPosition;

    uint64_t temp_read_value;
    uint32_t temp_value_bits;
    char* chunk;
    size_t chunk_size;
    size_t chunk_position;

public:
    uint64_t readBit();
    void read(void* ptr, size_t size, size_t count = 1);
    void clearTemp();

    BitStreamFileR(std::string filename, size_t chunk_size = 1024);
    ~BitStreamFileR();
};
