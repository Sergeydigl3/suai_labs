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
    uint32_t codebook[256];
    uint32_t offset = sizeof(FileHeader);

    friend std::ostream& operator<<(std::ostream& os, const FileHeader& file) {
        os << "filetype: " << file.filetype << std::endl;
        os << "compress_type: " << file.compress_type << std::endl;
        os << "original_size: " << file.original_size << std::endl;
        os << "compressed_size: " << file.compressed_size << std::endl;
        os << "crc32: " << file.crc32 << std::endl;
        os << "offset: " << file.offset << std::endl;
        os << "filename: " << file.filename << std::endl;
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
	uint64_t Count;
	uint32_t Code;
    std::string StrCode;
	uint32_t Bits;
} Symbol;

class winrar
{
private:
    FileHeader file_head;
    Symbol sym[256];
    std::string filepath;
    size_t codes_count;
    size_t byteSize;
    uint32_t lastSymbol = 255;
    // int split_2_groups(int from, int to);
    // void writeBits(BitStream* stream, uint32_t value, uint32_t bits);
    void histogram(uint8_t* input, uint32_t size);
    void restore_order();
    void sort_codebook_by_code();
    int split_2_groups(int from, int to);
    int make_tree(int from, int to, std::string code);
    void initSymbol();
    // void initBitStream(BitStream* stream);
    size_t compress_p(uint8_t* input, uint32_t inputSize, BitStreamFile& stream);
    size_t decompress_p(uint8_t* input, uint32_t inputSize, std::ofstream& file);
public:
    winrar(std::string filename);
    void compress(std::string filenameout);
    void decompress(std::string filenameout);

    void read_file_header();
    void write_file_header(std::string filename);
};
