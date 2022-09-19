#include "../bitstreamfile/bitstream.hpp"
#include "winrar.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

winrar::winrar(std::string filename) {
    filepath = filename;
}

void winrar::initSymbol() {
    for (int i = 0; i < 256; i++) {
        sym[i].Symbol = i;
        sym[i].Count = 0;
        sym[i].Code = 0;
        sym[i].Bits = 0;
    }
}

void winrar::histogram(uint8_t* input, uint32_t size)
{
    Symbol temp;
    int i, swaps;

    for (i = size; i; --i)
    {
        sym[*input++].Count++;
    }

    do
    {
        swaps = 0;

        for (i = 0; i < 255; ++i)
        {
            if (sym[i].Count < sym[i + 1].Count)
            {
                temp = sym[i];
                sym[i] = sym[i + 1];
                sym[i + 1] = temp;
                swaps = 1;
            }
        }
    } while (swaps);

    for (lastSymbol = 255; sym[lastSymbol].Count == 0; --lastSymbol);

    if (lastSymbol == 0)
        ++lastSymbol;
}

// split_2_groups function for Symbol struct
int winrar::split_2_groups(int from, int to)
{
    // initialize sum of whole array
    long sum = 0;
    for (int i = from; i < to; i++) {
        sum += sym[i].Count;
    }


    // initialize left and right sums and minimum difference
    long lsum = 0, rsum = sum, diff = INT32_MAX;
    int min_index = 0;
    // traverse array from left to right
    for (int i = from; i < to; i++)
    {
        // add current element to left sum
        lsum += sym[i].Count;

        // subtract current element to right sum
        rsum -= sym[i].Count;

        // update minimum difference
        if (abs(lsum - rsum) < diff) {
            diff = abs(lsum - rsum);
            min_index = i;
        }
    }
    // return minimum index
    return min_index;
}

int winrar::make_tree(int from, int to, std::string code)
{
    if (from + 1 == to) {
        // convert string of binary code to int
        sym[from].Code = 0;
        for (int i = 0; i < code.length(); i++) {
            sym[from].Code = sym[from].Code << 1;
            if (code[i] == '1') {
                sym[from].Code = sym[from].Code | 1;
            }
        }
        sym[from].StrCode = code;
        sym[from].Bits = code.length();
        return 0;
    }

    int index = split_2_groups(from, to) + 1;

    make_tree(from, index, code + "0");
    make_tree(index, to, code + "1");
    return 0;
}

void winrar::restore_order()
{
    Symbol temp;
    int i, swaps;

    do
    {
        swaps = 0;

        for (i = 0; i < 255; ++i)
        {
            if (sym[i].Symbol > sym[i + 1].Symbol)
            {
                temp = sym[i];
                sym[i] = sym[i + 1];
                sym[i + 1] = temp;
                swaps = 1;
            }
        }
    } while (swaps);
}

size_t winrar::compress_p(uint8_t* input, uint32_t inputSize, BitStreamFile& stream)
{
    // Symbol temp;
    uint32_t i, symbol;

    if (inputSize < 1)
        return 0;



    // считаем байты
    histogram(input, inputSize);

    make_tree(0, lastSymbol, "");

    restore_order();

    file_head.original_size = inputSize;
    file_head.compressed_size = sizeof(file_head);
    size_t temp_size = sizeof(file_head);

    for (int i = 0; i < 256; i++){
        file_head.codebook[i] = sym[i].Code;
        if (sym[i].Count != 0) {
            temp_size += sym[i].Bits*sym[i].Count;
            if (temp_size>8) {
                file_head.compressed_size += temp_size/8;
                temp_size = temp_size%8;
            }
        }
    }
    file_head.compressed_size += temp_size/8;

    stream.write((char*)&file_head, sizeof(file_head), 1);


    for (i = 0; i < inputSize; ++i)
    {
        symbol = input[i];
        stream.writeBits(sym[symbol].Code, sym[symbol].Bits);
    }
    cout << "Calculated compressed size: " << file_head.compressed_size << endl;
    cout << "Stream size: " << stream.getSize() << endl;
    cout << "Original size: " << file_head.original_size << endl;
    cout << "Compression ratio: " << (double)file_head.compressed_size/file_head.original_size << endl;
    return stream.getSize();
}

void winrar::compress(std::string filename_out) {
    std::ifstream file(filepath, std::ios::binary);
    BitStreamFile out_file(filename_out);

    if (!file.is_open()) {
        std::cout << "Error: file not found" << std::endl;
        return;
    }
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    uint8_t* data = new uint8_t[size];
    file.read((char*)data, size);
    file.close();

    initSymbol();

    size_t compressedDataSize = compress_p(data, size, out_file);
}

// int winrar::compress(std::string filename_out)
// {
//     std::ifstream f(filename_out);
//     std::string str((std::istreambuf_iterator<char>(f)),
//                   std::istreambuf_iterator<char>());
//     f.close();

//     uint8_t* originalData = (uint8_t*)str.c_str();
//     int originalDataSize = strlen(str.c_str());

//     size_t compressedDataSize = compress_p(originalData, originalDataSize);



//     FILE* output = fopen(filename_out.c_str(), "wb");

//     FileHeader file;
//     file.filetype = 228;
//     file.compress_type = 223;
//     file.original_size = 300;
//     file.compressed_size = 900;
//     file.crc32 = 0x000000FF;
//     file.offset = sizeof(file);
//     for (int i = 0; i < 256; i++)
//         file.codebook[i] = i;

//     // write file header to file
//     fwrite(&file, sizeof(file), 1, output);


//     fclose(output);


//     return 0;
// }

void winrar::decompress(std::string filename_out)
{

}

void winrar::read_file_header()
{
    FILE* input = fopen(filepath.c_str(), "rb");

    FileHeader file;

    fread(&file, sizeof(file), 1, input);

    std::cout << file;
}

void winrar::write_file_header(std::string filename)
{
    FILE* output = fopen(filename.c_str(), "wb");

    FileHeader file;
    file.filetype = 228;
    file.compress_type = 223;
    file.original_size = 300;
    file.compressed_size = 900;
    file.crc32 = 0x000000FF;
    file.offset = sizeof(file);
    for (int i = 0; i < 256; i++)
        file.codebook[i] = i;

    // write file header to file
    fwrite(&file, sizeof(file), 1, output);

    fclose(output);
}