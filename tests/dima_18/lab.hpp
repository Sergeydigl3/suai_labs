#include <vector>
#include <iostream>
#include <ostream>


class multiset_p
{
private:
    std::vector<int> array;
public:
    void insert(int value);
    int find(int value);
    void erase(int value);
    friend std::ostream& operator<<(std::ostream& os, const multiset_p& multiset);
};
