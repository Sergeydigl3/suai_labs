#include "bitstream.hpp"
#include <iostream>
#include <bitset>
using namespace std;

BitStreamFile::BitStreamFile(std::string filename) {
    file.open(filename, ios::binary);
    temp = 0;
    bitPosition = 0;
    size = 0;
}

BitStreamFile::~BitStreamFile() {
    if (bitPosition > 0) {
        file.write((char*)&temp, 1);
    }
    file.close();
}

void BitStreamFile::writeBits(uint64_t value, uint32_t bits) {
    uint64_t i;
    for (i = 0; i < bits; ++i) {
        temp |= ((value >> (bits - i - 1)) & 1) << (7 - bitPosition);
        ++bitPosition;
        if (bitPosition == 8) {
            file.write((char*)&temp, 1);
            temp = 0;
            bitPosition = 0;
            size++;
        }
    }
}

void BitStreamFile::write(void* ptr, size_t size, size_t count) {
    file.write((char*)ptr, size * count);
    this->size += size * count;
}

size_t BitStreamFile::getSize() {
    return size;
}

BitStreamFileR::BitStreamFileR(std::string filename, size_t chunk_size) {
    file.open(filename, ios::binary);
    if (!file.is_open()) {
        std::cout << "Error: input file not found" << std::endl;
        return;
    }
    if (!file.is_open()) {
        std::cout << "Error: output file not found" << std::endl;
        return;
    }
    temp = 0;
    bitPosition = 0;
    temp_read_value = 0;
    this->chunk_size = chunk_size;
    chunk = new char[chunk_size];
    // file.read(chunk, chunk_size);
    // for (int i = 0; i < chunk_size; ++i) {
    //     cout << bitset<8>(chunk[i]) << " ";
    // }
    // cout << endl;
    chunk_position = 0;
}

BitStreamFileR::~BitStreamFileR() {
    file.close();
    delete[] chunk;
}

uint64_t BitStreamFileR::readBit() {
    if (bitPosition == 0) {
        if (chunk_position == 0) {
            file.read(chunk, chunk_size);
        }
        temp = chunk[chunk_position];
        chunk_position++;

        if (chunk_position == chunk_size) {
            chunk_position = 0;
        }
    }
    // cout << bitset<8>(temp) << endl;
    uint64_t bit = (temp >> (7 - bitPosition)) & 1;
    temp_read_value = (temp_read_value << 1) | bit;

    bitPosition++;
    if (bitPosition == 8) {
        bitPosition = 0;
    }
    return temp_read_value;
}

void BitStreamFileR::read(void* ptr, size_t size, size_t count) {
    file.read((char*)ptr, size * count);
}

void BitStreamFileR::clearTemp() {
    temp_read_value = 0;
    temp_value_bits = 0;
}
