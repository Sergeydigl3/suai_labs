#include "lab.hpp"
#include <iostream>

template <typename T>
sorted_array<T>::sorted_array(size_t capacity)
{
    this->capacity = capacity;
    this->array = new T[capacity];
    this->size = 0;
}

template <typename T>
sorted_array<T>::~sorted_array()
{
    delete[] this->array;
}

template <typename T>
size_t sorted_array<T>::get_size()
{
    return this->size;
}

template <typename T>
T& sorted_array<T>::operator[](size_t i)
{
    return this->array[i];
}

template <typename T>
void sorted_array<T>::push(T value)
{
    if (this->size == this->capacity)
    {
        throw std::exception();
    }

    // push with order
    size_t i = 0;
    for (; i < this->size; i++)
    {
        if (this->array[i] > value)
        {
            break;
        }
    }
    for (size_t j = this->size; j > i; j--)
    {
        this->array[j] = this->array[j - 1];
    }
    this->array[i] = value;
    this->size++;
}

template <typename T>
T& sorted_array<T>::at(size_t i)
{
    if (i >= this->size)
    {
        throw std::exception();
    }
    return this->array[i];
}

template <typename T>
void sorted_array<T>::erase(size_t i)
{
    if (i >= this->size)
    {
        throw std::exception();
    }
    for (size_t j = i; j < this->size - 1; j++)
    {
        this->array[j] = this->array[j + 1];
    }
    this->size--;
}