#include "lab.hpp"
#include <iostream>

// insert value after order sorted
void multiset_p::insert(int value) 
{
    size_t i = 0;
    for (; i < this->array.size(); i++)
    {
        if (this->array[i] > value)
        {
            break;
        }
    }
    this->array.insert(this->array.begin() + i, value);
}

int multiset_p::find(int value) // return count of value
{
    int count = 0;
    for (size_t i = 0; i < this->array.size(); i++)
    {
        if (this->array[i] == value)
        {
            count++;
        }
    }
    return count;
}


void multiset_p::erase(int value)
{
    for (size_t i = 0; i < this->array.size(); i++)
    {
        if (this->array[i] == value)
        {
            this->array.erase(this->array.begin() + i);
            return;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const multiset_p& multiset)
{
    for (size_t i = 0; i < multiset.array.size(); i++)
    {
        os << multiset.array[i] << " ";
    }
    return os;
}