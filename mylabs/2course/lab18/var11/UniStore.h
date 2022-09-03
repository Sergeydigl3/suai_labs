#pragma once
#include <string>
#include <iostream>

#include "exception.h"

template <class T>
struct UniStore_st
{
    std::string key;
    T value;
};



template <class T>
class UniStore
{
private:
    UniStore_st<T>* data;
    size_t count;
public:
    UniStore();
    void add(const std::string& key, const T& value);
    T& find(const std::string& key);
    void erase(const std::string& key);
    std::string data_raw();


    // Override for the console output
    template<typename T2>
    friend std::ostream& operator<<(std::ostream& os, const UniStore<T2>& set);


    // Override for the file output
    template<typename T3>
    friend std::ofstream& operator<<(std::ofstream& file, const UniStore<T3>& set);

    ~UniStore();
};


template <class T>
UniStore<T>::UniStore()
{
    data = NULL;
    count = 0;
}



template <typename T>
std::string UniStore<T>::data_raw() {
    std::string out;
    for (size_t i = 0; i < count; i++) {
        out += data[i].key;
        out += "=";
        if (std::is_same<T, std::string>::value)
            out += data[i].value;
        else{
            T value = data[i].value;
            out += std::to_string(data[i].value);
        }
            
        out += "\n";
    }

    return out;
}


template<typename T2>
std::ostream& operator<<(std::ostream& os, const UniStore<T2>& store) {
    for (size_t i = 0; i < store.count; i++)
        os << store.data[i].key << " = " << store.data[i].value << "\n";
    return os;
}


template<typename T3>
std::ofstream& operator<<(std::ofstream& file, const UniStore<T3>& store) {
    for (size_t i = 0; i < store.count; i++)
        file << store.data[i].key << "=" << store.data[i].value << "\n";
    return file;
}

template <class T>
void UniStore<T>::add(const std::string& key, const T& value)
{
    if (count == 0) {
        data = new UniStore_st<T>[1];
        data[0].key = key;
        data[0].value = value;
    }
    else {
        for (size_t i = 0; i < count; i++)
            if (data[i].key == key)
                return;

        UniStore_st<T>* new_data = new UniStore_st<T>[count + 1];
        for (size_t i = 0; i < count; i++)
            new_data[i] = data[i];

        new_data[count].key = key;
        new_data[count].value = value;
        delete[] data;
        data = new_data;
    }
    count++;
}

template <class T>
void UniStore<T>::erase(const std::string& key) {
    bool exist = false;
    for (size_t i = 0; i < count; i++)
        if (data[i].key == key) {
            exist = true;
            break;
        }
    if (!exist) return;
    UniStore_st<T>* new_data = new UniStore_st<T>[count - 1];
    bool not_found = true;
    for (size_t i = 0; i < count; i++)
        if (data[i].key != key)
            new_data[not_found ? i : i - 1] = data[i];
        else
            not_found = false;
    delete[] data;
    data = new_data;

    count--;
}

template <class T>
T& UniStore<T>::find(const std::string& key) {
    for (size_t i = 0; i < count; i++)
        if (data[i].key == key) return data[i].value;

    throw StoreException("Find error. Key not found");
}

template <class T>
UniStore<T>::~UniStore()
{
    delete[] data;
    count = 0;
}

