// TASK
// 11. Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
//      insert(const T& value)
//      bool find(const T& value)
//      size() возвращает количество элементов в множестве
//      set intersect(const set& s) --- пересечение (бросает исключение при пересечении с пустым множеством)
//      operator<< для вывода
#pragma once

#include "exception.h"
#include <iostream>
#include <ostream>
using namespace std;

template <typename T >
class cset
{
private:
    T* array;
    size_t size_p;
public:
    cset();
    cset(const cset& s);
    cset& operator=(const cset& s);
    void insert(const T& value);
    bool find(const T& value);
    size_t Size();
    T& operator[](size_t index);
    cset intersect(const cset& s);
    ~cset();

    template< typename T2 >
    friend ostream& operator<<(ostream& os, const cset<T2>& set);
};

template <class T>
T& cset<T>::operator[](size_t index) {
    return array[index];
}

template <class T>
cset<T>::cset()
{
    array = NULL;
    size_p = 0;
}

template <class T>
cset<T>::cset(const cset& s)
{
    size_p = s.size_p;
    array = new T [size_p];
    for (size_t i = 0; i < size_p; i++)
        array[i] = s.array[i];
}

template <class T>
cset<T>& cset<T>::operator=(const cset& s)
{
    if (&s == this) return *this;
    delete [] array;
    size_p = s.size_p;
    array = new T [size_p];
    for (size_t i = 0; i < size_p; i++)
        array[i] = s.array;
}

template <class T>
void cset<T>::insert(const T& value) {
    if (size_p == 0) {
        this->array = new T[1];
        array[0] = value;
    }
    else {
        for (size_t i = 0; i < this->size_p; i++)
            if(value == this->array[i])
                return; 

        

        T* new_array = new T[size_p + 1];
        size_t current = 0;
        while (value > array[current] && current < size_p) {
            new_array[current] = array[current];
            current++;
        }
        new_array[current++] = value;
        while (current<size_p+1){
            new_array[current] = array[current-1];
            current++;
        }
        array = new_array;
    }
    size_p++;
}

template <class T>
cset<T> cset<T>::intersect(const cset& s) {
    if (s.size_p == 0) throw CsetException("Given set is empty!");

    cset<T> new_cset;
    
    size_t currentThis, currentS = 0;
    while (currentThis<this->size_p && currentS<s.size_p){
        if (this->array[currentThis]<s.array[currentS]) currentThis++;
        else if (this->array[currentThis]<s.array[currentS]) currentS++;
        else {
            new_cset.insert(this->array[currentThis]);
            currentThis++;
            currentS++;
        }
    }
    
    return new_cset;
}

template <class T>
size_t cset<T>::Size()
{
    return this->size_p;
}

template <class T>
bool cset<T>::find(const T& value)
{
    for (size_t i = 0; i < this->size_p; i++)
        if (this->array[i] == value) return true;
    return false;

}

template <class T>
cset<T>::~cset()
{
    delete[] array;
    size_p = 0;
}

template <class T>
ostream& operator<<(ostream& os, const cset<T>& set)
{
    os << "{ ";
    for (size_t i = 0; i < set.size_p; i++)
        os << set.array[i] << ", ";
    os << "}";
    return os;
}

