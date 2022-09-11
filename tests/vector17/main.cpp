#include <iostream>
#include "vector_real.hpp"
#include <string>

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int> v2 = v;
    v2[0] = 100;
    v2[1] = 200;

    std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;

    vector<std::string> v3;
    v3.push_back("hello");
    v3.push_back("world");
    v3.push_back("!");

    std::cout << v3[0] << " " << v3[1] << " " << v3[2] << std::endl;




    return 0;
}
