#include "lab_real.hpp"
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    sorted_array<int> arr(10, 1);
    arr.push(5);
    arr.push(3);
    arr.push(7);
    arr.push(1);
    arr.push(9);
    arr.push(2);
    arr.push(4);
    arr.push(6);
    // arr.push(8);
    // arr.push(10);
    // arr.push(10);
    // arr.push(10);
    for (size_t i = 0; i < arr.get_size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sorted_array<Point> arr2(6, 1);
    arr2.push(Point(1, 45, 3));
    arr2.push(Point(3, 2, 1));
    arr2.push(Point(15, 1, 96));
    arr2.push(Point(1, 3, 2));
    arr2.push(Point(77, 1, 2));
    arr2.push(Point(2, 3, 1));
    for (size_t i = 0; i < arr2.get_size(); i++)
    {
        cout << arr2[i] << " " << endl;
    }
}
