#include <iostream>
#include "lab13.h"
using namespace std;

int main() {

    cout << Date(5) + 4 << endl;
    cout << Date(5) + Date(4) << endl;
    Date d1 = Date(5) + Date(4);
    d1++;
    cout << d1 << endl;


    // cout << "Sum: " << d1 + d2 << endl;
    cout << endl;
}