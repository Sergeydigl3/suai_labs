#include <iostream>
using namespace std;

bool operator<(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size<0;
    return s1.compare(s2)<0;
}

bool operator>(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size>0;
    return s1.compare(s2)>0;
}

bool operator<=(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size<0;
    return s1.compare(s2)<=0;
}

bool operator>=(const string& s1, const string& s2) {
    int size = s1.size() - s2.size();
    if (size != 0) return size>0;
    return s1.compare(s2)>=0;
}


int main(int argc, char const *argv[])
{
    const string s1 = "Yes";
    const string s2 = "Okay";
    cout << (s1<s2) << endl;
    return 0;
}

