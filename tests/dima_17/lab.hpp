#include <stdlib.h>
#include <ostream>

struct Point
{
    int x;
    int y;
    int z;

    Point(int x, int y, int z) : x(x), y(y), z(z) {}
    Point() : x(0), y(0), z(0) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& point)
    {
        os << "x: " << point.x << " y: " << point.y << " z: " << point.z;
        return os;
    }

    // compare by distance to zero
    bool operator>(const Point& other) const
    {
        return (x * x + y * y + z * z) > (other.x * other.x + other.y * other.y + other.z * other.z);
    }

    bool operator<(const Point& other) const
    {
        return (x * x + y * y + z * z) < (other.x * other.x + other.y * other.y + other.z * other.z);
    }

};

template <typename T>
class sorted_array
{
    size_t capacity;
    T* array;
    size_t size;
public:
    sorted_array(size_t capacity);
    ~sorted_array();
    size_t get_size();
    T& operator[](size_t i);
    void push(T value);
    T& at(size_t i);
    void erase(size_t i);
};

