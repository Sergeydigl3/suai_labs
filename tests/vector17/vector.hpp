#pragma once

// class vector on template
template <typename T>
class vector
{
private:
    T* data;
    int size;
    int capacity;
public:
    vector();
    vector(int size);
    vector(const vector<T>& other);
    ~vector();
    vector<T>& operator=(const vector<T>& other);
    T& operator[](int index);
    const T& operator[](int index) const;
    int get_size() const;
    int get_capacity() const;
    void push_back(const T& value);
    void pop_back();
    void resize(int new_size);
    void reserve(int new_capacity);
    void clear();
    void print() const;
};
