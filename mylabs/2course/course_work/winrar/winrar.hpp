// class for compressing and decompressing files
#pragma once
#include <iostream>
#include <cstring>
#include <cstdint>

struct FileHeader {
    uint32_t filetype;
    uint32_t compress_type;
    uint32_t original_size;
    uint32_t compressed_size;
    uint32_t crc32;
    uint32_t codebook[256];
    uint32_t offset;

    friend std::ostream& operator<<(std::ostream& os, const FileHeader& file) {
        os << "filetype: " << file.filetype << std::endl;
        os << "compress_type: " << file.compress_type << std::endl;
        os << "original_size: " << file.original_size << std::endl;
        os << "compressed_size: " << file.compressed_size << std::endl;
        os << "crc32: " << file.crc32 << std::endl;
        os << "offset: " << file.offset << std::endl;
        os << "codebook: " << std::endl;
        for (int i = 0; i < 256; i++)
            os << file.codebook[i] << " ";
        os << std::endl;
        return os;
    }
};

typedef struct {
	uint8_t* BytePointer;
	uint32_t BitPosition;
} BitStream;

typedef struct {
	uint32_t Symbol;
	uint32_t Count;
	uint32_t Code;
    std::string StrCode;
	uint32_t Bits;
} Symbol;

class winrar
{
private:
    // int make_tree(Symbol* sym, int from, int to, std::string code);
    // int split_2_groups(Symbol* sym, int from, int to);
    void writeBits(BitStream* stream, uint32_t value, uint32_t bits);
public:

    int compress(std::string& filename);
    int decompress(std::string& filename);

    void read_file_header(std::string filename);
    void write_file_header(std::string filename);
};
