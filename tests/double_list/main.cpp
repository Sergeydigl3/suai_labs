#include "double_list_real.hpp"
#include <string>
int main(int argc, char const *argv[])
{
    DoubleList<int> list;
    DoubleList<std::string> list2;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list2.push_back("1");
    list2.push_back("2");

    std::cout << list.at(0) << std::endl;
    std::cout << list.at(1) << std::endl;

    std::cout << list.size() << std::endl;
    std::cout << list.at(0) << std::endl;
    std::cout << list.at(1) << std::endl;




    return 0;
}
