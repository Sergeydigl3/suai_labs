#include <iostream>
#include <cstring>
// #include "test.hpp"
#include "winrar/winrar.hpp"
#include <fstream>

using namespace std;





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

void test_write5(){
    winrar zip7("kniga.txt");
    zip7.compress("kniga.aboba");
}

void test_read5(){
    winrar zip7("kniga.aboba");
    // zip7.read_file_header();
    zip7.decompress("kniga2.txt");
}

int main(int argc, char const *argv[])
{
    // test_write();
    // test_write2();
    // test_read2();
}
