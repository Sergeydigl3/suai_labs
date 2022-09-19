#include "winrar.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>


static void histogram(uint8_t* input, Symbol* sym, uint32_t size)
{
	Symbol temp;
	int i, swaps;

	for (i = 0; i < 256; ++i)
	{
		sym[i].Symbol = i;
		sym[i].Count = 0;
		sym[i].Code = 0;
		sym[i].Bits = 0;
	}

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
}


// split_2_groups function for Symbol struct
int split_2_groups(Symbol* sym, int from, int to)
{
    // initialize sum of whole array
    int sum = 0;
    for (int i = from; i < to; i++) {
        sum += sym[i].Count;
    }


    // initialize left and right sums and minimum difference
    int lsum = 0, rsum = sum, diff = INT8_MAX;
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

int make_tree(Symbol* sym, int from, int to, std::string code)
{
    if(from+1 == to) {
        // convert string of binary code to int
        sym[from].Code = 0;
        for (int i = 0; i < code.length(); i++) {
            sym[from].Code  = sym[from].Code  << 1;
            if (code[i] == '1') {
                sym[from].Code  = sym[from].Code  | 1;
            }
        }  
        sym[from].StrCode = code;
        sym[from].Bits = code.length();
        return 0;
    }

    int index = split_2_groups(sym, from, to)+1;

    make_tree(sym, from, index, code + "0");
    make_tree(sym, index, to, code + "1");
    return 0;
}

static void initBitStream(BitStream* stream, uint8_t* buffer)
{
	stream->BytePointer = buffer;
	stream->BitPosition = 0;
}

static int P_Compress(uint8_t* input, uint8_t* output, uint32_t inputSize)
{
	Symbol sym[256], temp;
	BitStream stream;
	uint32_t i, totalBytes, swaps, symbol, lastSymbol;

	if (inputSize < 1)
		return 0;

	initBitStream(&stream, output);

	// считаем байты
	histogram(input, sym, inputSize);

	// crate new vector and callculate frequency of each symbol and write result 
	

	for (lastSymbol = 255; sym[lastSymbol].Count == 0; --lastSymbol);

	if (lastSymbol == 0)
		++lastSymbol;

	make_tree(sym, 0, lastSymbol, "");

	
	// do
	// {
	// 	swaps = 0;

	// 	for (i = 0; i < 255; ++i)
	// 	{
	// 		if (sym[i].Symbol > sym[i + 1].Symbol)
	// 		{
	// 			temp = sym[i];
	// 			sym[i] = sym[i + 1];
	// 			sym[i + 1] = temp;
	// 			swaps = 1;
	// 		}
	// 	}
	// } while (swaps);

	// for (i = 0; i < inputSize; ++i)
	// {
	// 	symbol = input[i];
	// 	writeBits(&stream, sym[symbol].Code, sym[symbol].Bits);
	// }

	totalBytes = (int)(stream.BytePointer - output) + (stream.BitPosition > 0);

	return totalBytes;
}

int winrar::compress(std::string& filename)
{
    std::ifstream f(filename);
    std::string str((std::istreambuf_iterator<char>(f)),
                  std::istreambuf_iterator<char>());
    f.close();
    
    uint8_t* originalData = (uint8_t*)str.c_str();
    int originalDataSize = strlen(str.c_str());
    uint8_t* compressedData = new uint8_t[originalDataSize * (101 / 100) + 384];
    
    int compressedDataSize = P_Compress(originalData, compressedData, originalDataSize);
    return 0;
}

int winrar::decompress(std::string& filename)
{
    return 0;
}

void winrar::writeBits(BitStream* stream, uint32_t value, uint32_t bits)
{
    uint32_t bitMask = 1 << (bits - 1);

    while (bitMask)
    {
        if (value & bitMask)
            *stream->BytePointer |= (1 << stream->BitPosition);
        else
            *stream->BytePointer &= ~(1 << stream->BitPosition);

        if (++stream->BitPosition == 8)
        {
            stream->BitPosition = 0;
            ++stream->BytePointer;
        }

        bitMask >>= 1;
    }
}

uint32_t get(FILE* f, uint8_t bytes) {
    uint32_t temp = 0;
    for (int i = 0; i < bytes; i++)
        temp |= getc(f) << (8 * i); // little-endian
    return temp;
}

void winrar::read_file_header(std::string filename)
{
    FILE* input = fopen(filename.c_str(), "rb");

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