#include <iostream>
#include <cstring>
// #include "test.hpp"
#include "winrar/winrar.hpp"
#include <fstream>

using namespace std;



// int main(int argc, char const* argv[])
// {
//     ifstream f("book.txt");
//     std::string str((std::istreambuf_iterator<char>(f)),
//                   std::istreambuf_iterator<char>());
//     f.close();
    
//     uint8_t* originalData = (uint8_t*)str.c_str();
//     int originalDataSize = strlen(str.c_str());
//     uint8_t* compressedData = new uint8_t[originalDataSize * (101 / 100) + 384];
    
//     int compressedDataSize = Compress(originalData, compressedData, originalDataSize);
//     return 0;
// }

void test_write(){
    winrar zip7("book.txt");
    zip7.compress("book.aboba");
    // zip7.read_file_header("crypt.csd");
    std::string filename = "test2.aboba";
    // zip7.write_file_header(filename);
    // zip7.read_file_header(filename);
}

void test_write2(){
    winrar zip7("war_and_peace.txt");
    zip7.compress("war_and_peace.aboba");
}

void test_read(){
    winrar zip7("book.aboba");
    zip7.read_file_header();
    // zip7.decompress("book2.txt");
    return;
}

void test_read2(){
    winrar zip7("war_and_peace.aboba");
    zip7.read_file_header();
    // zip7.decompress("war_and_peace2.txt");
}

int main(int argc, char const *argv[])
{
    test_read();
    // test_write();
    // test_write2();
    // test_read2();
}
