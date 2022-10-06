#include "../bitstreamfilev2/bitstream.hpp"
#include "winrar.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <bitset>

#include "../indicators/indicators.hpp"
using namespace indicators;

winrar::winrar(std::string filename, uint64_t chunk_size, bool debug) {
    filepath = filename;
    this->chunk_size = chunk_size;
    this->debug = debug;
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

void winrar::sort_codebook_by_code() {
    Symbol temp;
    int i, swaps;

    do
    {
        swaps = 0;

        for (i = 0; i < 255; ++i)
        {
            if (sym[i].Bits < sym[i + 1].Bits)
            {
                temp = sym[i];
                sym[i] = sym[i + 1];
                sym[i + 1] = temp;
                swaps = 1;
            }
        }
    } while (swaps);

    do
    {
        swaps = 0;

        for (i = 0; i < file_head.codebook_elements - 1; ++i)
        {
            if (sym[i].Code > sym[i + 1].Code)
            {
                temp = sym[i];
                sym[i] = sym[i + 1];
                sym[i + 1] = temp;
                swaps = 1;
            }
        }
    } while (swaps);
}

// codebook_optimize function push all Symbols to codebook_optimized array by bits
int winrar::codebook_optimize() {
    // find max bits
    int max_bits = 0;
    for (int i = 0; i < file_head.codebook_elements; i++) {
        if (sym[i].Bits > max_bits) {
            max_bits = sym[i].Bits;
        }
    }

    // push all Symbols to codebook_optimized array by bits

    for (int i = 0; i < max_bits + 1; i++) {
        vector<Symbol> temp;
        for (int j = 0; j < file_head.codebook_elements; j++) {
            if (sym[j].Bits == i) {
                temp.push_back(sym[j]);
            }
        }
        codebook_optimized.push_back(temp);
    }
    return max_bits;
}

uint64_t winrar::compress_p(uint8_t* input, uint64_t inputSize, BitStreamFile& stream)
{
    // Symbol temp;
    uint32_t i, symbol;

    if (inputSize < 1)
        return 0;



    // считаем байты
    histogram(input, inputSize);

    make_tree(0, lastSymbol + 1, "");

    file_head.original_size = inputSize;
    file_head.compressed_size = sizeof(file_head);
    file_head.codebook_elements = lastSymbol + 1;
    uint64_t temp_size = sizeof(file_head);


    file_head.compressed_size += temp_size / 8;

    stream.write((char*)&file_head, sizeof(file_head), 1);

    uint8_t byte_temp = 0;

    uint8_t max_bits = 0;
    for (i = 0; i < file_head.codebook_elements; i++) {
        // calculate bits to byte degree 2

        stream.write((char*)&sym[i].Symbol, sizeof(sym[i].Symbol), 1);
        stream.write((char*)&sym[i].Bits, sizeof(sym[i].Bits), 1);
        stream.write((char*)&sym[i].Code, (sym[i].Bits + 7) / 8, 1);
        if (debug)
            cout << "Symbol: " << sym[i].Symbol << " Bits: " << static_cast<unsigned>(sym[i].Bits) << " Bytes: " << static_cast<unsigned>((sym[i].Bits + 7) / 8) << " Code: " << sym[i].StrCode << endl;

        if (sym[i].Bits > max_bits)
            max_bits = sym[i].Bits;
        file_head.compressed_size += sizeof(sym[i].Symbol) + sizeof(sym[i].Count) + (sym[i].Bits + 7) / 8;
    }
    if (max_bits > sizeof(uint64_t) * 8) {
        cout << "Error: max_bits > sizeof(uint64_t)*8" << endl;
        return 0;
    }

    restore_order();

    // cout << "Binary content: ";
    for (i = 0; i < inputSize; ++i)
    {
        symbol = input[i];
        stream.writeBits(sym[symbol].Code, sym[symbol].Bits);
        // cout << sym[symbol].StrCode << " ";
    }
    cout << "\nCalculated compressed size: " << file_head.compressed_size << endl;
    cout << "Stream size: " << stream.getSize() << endl;
    cout << "Original size: " << file_head.original_size << endl;
    cout << "Compression ratio: " << (double)file_head.compressed_size / file_head.original_size << endl;
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
    uint64_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    uint8_t* data = new uint8_t[size];
    file.read((char*)data, size);
    file.close();

    initSymbol();

    uint64_t compressedDataSize = compress_p(data, size, out_file);
}

void winrar::decompress(std::string filename_out)
{
    cout << "CHUNK_SIZE: " << chunk_size << endl;
    BitStreamFileR file(filepath, chunk_size);
    std::ofstream out_file(filename_out, std::ios::binary);


    // read file header
    file.read((char*)&file_head, sizeof(file_head));

    initSymbol();
    // read codebook from file_head
    for (int i = 0; i < file_head.codebook_elements; i++) {
        uint8_t symbol, bits;
        file.read((char*)&symbol, sizeof(symbol));
        file.read((char*)&bits, sizeof(bits));

        sym[symbol].Symbol = symbol;
        sym[symbol].Bits = bits;


        file.read((char*)&sym[symbol].Code, (sym[symbol].Bits + 7) / 8);
        if (debug)
            cout << "Symbol: " << symbol << " Bits: " << static_cast<unsigned>(bits) << " Bytes: " << static_cast<unsigned>((sym[symbol].Bits + 7) / 8) << " Code: " << sym[symbol].Code << endl;
    }

    sort_codebook_by_code();

    int max_bits = codebook_optimize();

    show_console_cursor(false);


    indicators::BlockProgressBar bar{
        option::BarWidth{50},
        option::PrefixText{"Decompressing file "},
        option::ForegroundColor{Color::yellow},
        option::ShowElapsedTime{true},
        option::ShowRemainingTime{true},
        option::FontStyles{
        std::vector<FontStyle>{FontStyle::bold}},
        option::MaxProgress{file_head.original_size}
    };


    for (uint64_t i = 0; i < file_head.original_size; i++) {
        bar.set_option(option::PostfixText{
            std::to_string(i) + "/" + std::to_string(file_head.original_size)
            });

        uint64_t code = 0;
        uint64_t count_bits = 0;
        bool code_found = false;
        do
        {
            code = file.readBit();
            count_bits++;

            for (int j = 0; j < codebook_optimized[count_bits].size(); j++) {
                if (codebook_optimized[count_bits][j].Code == code) {
                    out_file.write((char*)&codebook_optimized[count_bits][j].Symbol, 1);
                    file.clearTemp();
                    code_found = true;
                    count_bits = 0;
                    break;
                }
            }
        } while (!code_found && count_bits < max_bits);
        if (!code_found && count_bits == max_bits) {
            cout << "Error: code not found" << endl;
            break;
        }

        bar.tick();
    }

    bar.mark_as_completed();
    show_console_cursor(true);

    out_file.close();
}

void winrar::read_file_header()
{
    std::ifstream file(filepath, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Error: file not found" << std::endl;
        return;
    }


    initSymbol();

    file.read((char*)&file_head, sizeof(file_head));


    for (int i = 0; i < file_head.codebook_elements; i++) {
        uint8_t symbol, bits;
        file.read((char*)&symbol, sizeof(symbol));
        file.read((char*)&bits, sizeof(bits));

        sym[symbol].Symbol = symbol;
        sym[symbol].Bits = bits;


        file.read((char*)&sym[symbol].Code, (sym[symbol].Bits + 7) / 8);
        cout << "Symbol: " << symbol << " Bits: " << static_cast<unsigned>(bits) << " Bytes: " << static_cast<unsigned>((sym[symbol].Bits + 7) / 8) << " Code: " << sym[symbol].Code << endl;
    }

    std::cout << file_head;

    // print codebook
    for (int i = 0; i < 256; i++) {
        if (sym[i].Bits != 0) {
            std::cout << "Symbol: " << sym[i].Symbol << " Bits: " << static_cast<unsigned>(sym[i].Bits) << " Code: " << sym[i].StrCode << std::endl;
        }
    }
}
