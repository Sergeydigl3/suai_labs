#include <time.h>
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900;

    cout << day << endl;
    cout << month << endl;
    cout << year << endl;
    return 0;
}

