#include "lab.hpp"
#include <iostream>

using namespace std;

int main(){
    multiset_p multiset;
    multiset.insert(1);
    multiset.insert(2);
    multiset.insert(1);
    multiset.insert(3);

    cout << multiset << endl;

    multiset.erase(1);

    cout << multiset << endl;

    multiset.insert(3);

    cout << multiset << endl;
    cout << multiset.find(3) << endl;

    return 0;
}