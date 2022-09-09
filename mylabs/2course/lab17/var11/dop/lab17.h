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
#include <fstream>
using namespace std;
#include "includes/json.hpp"
using json = nlohmann::json;

struct point
{
    int x;
    int y;
    int z;

    friend ostream& operator<<(ostream& os, const point& p) {
        os << "( " << p.x << " " << p.y << " " << p.z << ")";
        return os;
    }

};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(point, x, y, z)

bool operator==(const point& lhs, const point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator>(const point& lhs, const point& rhs) {
    return (lhs.x*lhs.x+lhs.y*lhs.y+lhs.z*lhs.z) == (rhs.x*rhs.x+rhs.y*rhs.y+rhs.z*rhs.z);
}

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
    void save_json(const std::string& filename);
    void load_json(const std::string& filename);

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
    array = new T[size_p];
    for (size_t i = 0; i < size_p; i++)
        array[i] = s.array[i];
}

template <class T>
cset<T>& cset<T>::operator=(const cset& s)
{
    if (&s == this) return *this;
    delete[] array;
    size_p = s.size_p;
    array = new T[size_p];
    for (size_t i = 0; i < size_p; i++)
        array[i] = s.array;
}

bool operator<(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size < 0;
    return s1.compare(s2) < 0;
}

bool operator>(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size > 0;
    return s1.compare(s2) > 0;
}

bool operator<=(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size < 0;
    return s1.compare(s2) <= 0;
}

bool operator>=(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size > 0;
    return s1.compare(s2) >= 0;
}

template <class T>
void cset<T>::insert(const T& value) {
    if (size_p == 0) {
        this->array = new T[1];
        array[0] = value;
    }
    else {
        for (size_t i = 0; i < this->size_p; i++)
            if (value == this->array[i])
                return;



        T* new_array = new T[size_p + 1];
        size_t current = 0;
        while (value > array[current] && current < size_p) {
            new_array[current] = array[current];
            current++;
        }
        new_array[current++] = value;
        while (current < size_p + 1) {
            new_array[current] = array[current - 1];
            current++;
        }
        array = new_array;
    }
    size_p++;
}

template <class T>
void cset<T>::save_json(const std::string& filename) {
    std::ofstream file(filename);
    json o;
    o["count"] = size_p;
    for (size_t i = 0; i < size_p; i++)
        o["data"].push_back(array[i]);

    file << o;
}

template <class T>
void cset<T>::load_json(const std::string& filename) {
    std::ifstream file(filename);
    json j;
    file >> j;
    size_p = j["count"];
    array = new T[size_p];
    for (size_t i = 0; i < size_p; i++)
    {
        array[i] = j["data"][i];
    }

    file.close();
}

template <class T>
cset<T> cset<T>::intersect(const cset& s) {
    if (s.size_p == 0) throw CsetException("Given set is empty!");

    cset<T> new_cset;

    size_t currentThis = 0, currentS = 0;
    while (currentThis < this->size_p && currentS < s.size_p) {
        if (this->array[currentThis] < s.array[currentS]) currentThis++;
        else if (this->array[currentThis] < s.array[currentS]) currentS++;
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

