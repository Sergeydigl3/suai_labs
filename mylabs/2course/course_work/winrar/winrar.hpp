// class for compressing and decompressing files
#pragma once
#include "../bitstreamfile/bitstream.hpp"
#include <iostream>
#include <cstring>
#include <cstdint>

struct FileHeader {
    uint32_t filetype = 228;
    uint8_t filename[100] = {0};
    uint32_t compress_type = 223;
    uint32_t original_size;
    uint32_t compressed_size;
    uint32_t crc32 = 0x000000FF;
    uint16_t codebook_elements;
    uint32_t offset = sizeof(FileHeader);

    friend std::ostream& operator<<(std::ostream& os, const FileHeader& file) {
        os << "filetype: " << file.filetype << std::endl;
        os << "compress_type: " << file.compress_type << std::endl;
        os << "original_size: " << file.original_size << std::endl;
        os << "compressed_size: " << file.compressed_size << std::endl;
        os << "crc32: " << file.crc32 << std::endl;
        os << "offset: " << file.offset << std::endl;
        os << "filename: " << file.filename << std::endl;
        // os << "codebook: " << std::endl;
        os << "codebook_elements: " << (int)file.codebook_elements << std::endl;
        os << std::endl;
        return os;
    }
};

typedef struct {
	uint8_t* BytePointer;
	uint32_t BitPosition;
} BitStream;

typedef struct {
	uint8_t Symbol;
	uint64_t Count;
	uint64_t Code;
    std::string StrCode;
	uint8_t Bits;
} Symbol;

class winrar
{
private:
    FileHeader file_head;
    Symbol sym[256];
    std::string filepath;
    uint64_t codes_count;
    uint64_t byteSize;
    uint32_t lastSymbol = 255;
    void histogram(uint8_t* input, uint32_t size);
    void restore_order();
    void sort_codebook_by_code();
    int split_2_groups(int from, int to);
    int make_tree(int from, int to, std::string code);
    void initSymbol();
    // void initBitStream(BitStream* stream);
    uint64_t compress_p(uint8_t* input, uint64_t inputSize, BitStreamFile& stream);
    // uint64_t decompress_p(uint8_t* input, uint64_t inputSize, std::ofstream& file);
public:
    winrar(std::string filename);
    void compress(std::string filenameout);
    void decompress(std::string filenameout);
    void read_file_header();
    void write_file_header(std::string filename);
};
