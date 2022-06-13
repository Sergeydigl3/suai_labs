#include <stdlib.h>

// заголовочный файл
class vector_t
{
private:
    int* data;
    size_t size;
public:
    vector_t(size_t size); // конструктор
    vector_t(vector_t& a); // конструктор копий
    vector_t& operator=(vector_t& v); //оператор присваивания

    ~vector_t(); // деструктор
};
// конец заголовочного файла

vector_t::vector_t(size_t size) {// конструктор
    this->size = size;
    data = new int[size];
}

vector_t::vector_t(vector_t& a) { // конструктор копий
    size = a.size;
    data = new int[size];
    for (size_t i = 0; i < size; i++) data[i] = a.data[i];
}

vector_t& vector_t::operator=(vector_t& v) { // оператор присваивания
    if (&v == this) return *this;
    delete [] data;
    size = v.size;
    data = new int [size];
    for (size_t i=0; i<size; i++) data[i] = v.data[i];
    return *this;
}

vector_t::~vector_t() { // деструктор
    delete[] data;
}
