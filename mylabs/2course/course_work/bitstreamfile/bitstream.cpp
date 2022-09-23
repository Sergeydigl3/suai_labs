#include "bitstream.hpp"

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

void BitStreamFile::writeBits(uint32_t value, uint32_t bits) {
    uint32_t i;
    for (i = 0; i < bits; ++i) {
        temp |= ((value >> i) & 1) << bitPosition;
        ++bitPosition;
        if (bitPosition == 8) {
            file.write((char*)&temp, 1);
            temp = 0;
            bitPosition = 0;
            size++;
        }
    }
}

void BitStreamFile::writeByte(uint8_t value) {
    file.write((char*)&value, 1);
    size++;
}

void BitStreamFile::writeInt(uint32_t value) {
    file.write((char*)&value, 4);
    size += 4;
}

void BitStreamFile::write(void* ptr, size_t size, size_t count) {
    file.write((char*)ptr, size * count);
    this->size += size * count;
}

size_t BitStreamFile::getSize() {
    return size;
}

BitStreamFileR::BitStreamFileR(std::string filename) {
    file.open(filename, ios::binary);
    temp = 0;
    bitPosition = 0;
    size = 0;
}

BitStreamFileR::~BitStreamFileR() {
    file.close();
}

// readBits function for reading bits from file, with saving starting place
uint32_t BitStreamFileR::readBits(uint32_t bits) {
    uint32_t i;
    uint32_t value = 0;
    // save current position in file
    streampos pos = file.tellg();

    for (i = 0; i < bits; ++i) {
        if (bitPosition == 0) {
            file.read((char*)&temp, 1);
        }
        value |= ((temp >> bitPosition) & 1) << i;
        ++bitPosition;
        if (bitPosition == 8) {
            bitPosition = 0;
        }
    }
    // return to starting position
    file.seekg(pos); 
    return value;
}

// seekBits function for skipping bits in file
void BitStreamFileR::seekBits(uint32_t bits) {
    uint32_t i;
    for (i = 0; i < bits; ++i) {
        if (bitPosition == 0) {
            file.read((char*)&temp, 1);
        }
        ++bitPosition;
        if (bitPosition == 8) {
            bitPosition = 0;
        }
    }
}

uint8_t BitStreamFileR::readByte() {
    uint8_t value;
    file.read((char*)&value, 1);
    return value;
}

uint32_t BitStreamFileR::readInt() {
    uint32_t value;
    file.read((char*)&value, 4);
    return value;
}

void BitStreamFileR::read(void* ptr, size_t size, size_t count) {
    file.read((char*)ptr, size * count);
}

size_t BitStreamFileR::getSize() {
    return size;
}