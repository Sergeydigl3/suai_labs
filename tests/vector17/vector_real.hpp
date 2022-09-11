#include "vector.hpp"
#include <iostream>

template <typename T>
vector<T>::vector()
{
    size = 0;
    capacity = 0;
    data = nullptr;
}

template <typename T>
vector<T>::vector(int size)
{
    this->size = size;
    capacity = size;
    data = new T[size];
}

template <typename T>
vector<T>::vector(const vector<T>& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
vector<T>::~vector()
{
    delete[] data;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& other)
{
    if (this != &other)
    {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& vector<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
const T& vector<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
int vector<T>::get_size() const
{
    return size;
}

template <typename T>
int vector<T>::get_capacity() const
{
    return capacity;
}

template <typename T>
void vector<T>::push_back(const T& value)
{
    if (size == capacity)
    {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void vector<T>::pop_back()
{
    size--;
}

template <typename T>
void vector<T>::resize(int new_size)
{
    if (new_size > capacity)
    {
        reserve(new_size);
    }
    size = new_size;
}

template <typename T>
void vector<T>::reserve(int new_capacity)
{
    if (new_capacity > capacity)
    {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

template <typename T>
void vector<T>::clear()
{
    size = 0;
}

template <typename T>
void vector<T>::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
