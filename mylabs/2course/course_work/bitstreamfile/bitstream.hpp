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
    void writeByte(uint8_t value);
    void writeInt(uint32_t value);


    void write(void* ptr, size_t size, size_t count);
    // uint64_t readBits(uint32_t bits);

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
    size_t size;

public:
    uint64_t readBits(uint32_t bits);
    void seekBits(uint32_t bits);
    uint8_t readByte();
    uint32_t readInt();
    void read(void* ptr, size_t size, size_t count = 1);
    size_t getSize();
    bool eof();
    BitStreamFileR(std::string filename);
    ~BitStreamFileR();
};
