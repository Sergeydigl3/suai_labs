#include <iostream>
#include <cstring>
// #include "test.hpp"
#include "winrar/winrar.hpp"
#include <fstream>

using namespace std;


// void test_write(){
//     winrar zip7("/book.txt");
//     zip7.compress("book.aboba");
//     // zip7.read_file_header("crypt.csd");
//     std::string filename = "test2.aboba";
//     // zip7.write_file_header(filename);
//     // zip7.read_file_header(filename);
// }

void war_write(){
    winrar zip7("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/war/war_and_peace.txt");
    zip7.compress("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/war/war_and_peace.aboba");
}

void war_read(){
    winrar zip7("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/war/war_and_peace.aboba");
    // zip7.read_file_header();
    zip7.decompress("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/war/war_and_peace2.txt");
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

void test_write6(){
    winrar zip7("mif.jpg");
    zip7.compress("mif.aboba");
}

void test_read6(){
    winrar zip7("mif.aboba");
    // zip7.read_file_header();
    zip7.decompress("mif2.jpg");
}

void test_write7(){
    winrar zip7("kruk.jpg");
    zip7.compress("kruk.aboba");
    return;
}

void test_read7(){
    winrar zip7("kruk.aboba");
    // zip7.read_file_header();
    zip7.decompress("kruk2.jpg");
}

void bmp_write(){
    winrar zip7("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/bmp/sample.bmp");
    zip7.compress("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/bmp/sample.aboba");
}

void bmp_read(){
    winrar zip7("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/bmp/sample.aboba");
    zip7.decompress("/config/workspace/suai_labs/mylabs/2course/course_work/test_data/bmp/sample2.bmp");
}

int main(int argc, char const *argv[])
{
    // war_write();
    // war_read();
    // test_write();
    // test_write2();
    // test_read2();

    // test_write5();
    // test_read5();

    // test_write6();
    // test_read6();

    // test_write7();
    // test_read7();

    bmp_write();
    bmp_read();
}
