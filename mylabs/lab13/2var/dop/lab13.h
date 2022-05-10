#pragma once

#include <iostream>
using namespace std;

class Date
{
private:
    int days;
public:
    Date();
    Date(int days);
    int get_days();
    void set_days(int days);
    bool operator == (Date& d2);
    bool operator != (Date& d2);
    bool operator > (Date& d2);
    bool operator < (Date& d2);
    bool operator >= (Date& d2);
    bool operator <= (Date& d2);

    Date operator+(int days);
    Date operator+(Date d2);

    Date& operator++();
    Date& operator--();
    Date operator++(int);
    Date operator--(int);

    Date& operator+=(int days);
    Date& operator+=(const Date& d);

    friend ostream& operator <<(ostream& os, const Date& d);
    friend istream& operator >>(istream& is, Date& d);
};

class Birthday: public Date
{
protected:
    size_t year;
    size_t month;
    size_t day;

public:
    // Birthday(/* args */);
    Birthday(size_t days);
};

Birthday::Birthday(size_t days)
{
    
}

