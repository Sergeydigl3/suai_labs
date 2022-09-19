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
