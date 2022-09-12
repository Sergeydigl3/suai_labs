// class for compressing and decompressing files
#pragma once
#include <iostream>
#include <cstring>
#include <cstdint>

class winrar
{
private:
    
public:
    winrar();
    int compress(std::string& filename);
    int decompress(std::string& filename);
    ~winrar();
};

winrar::winrar(/* args */)
{
}

winrar::~winrar()
{
}
