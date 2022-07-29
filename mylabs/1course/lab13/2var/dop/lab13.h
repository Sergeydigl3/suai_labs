#pragma once

#include <iostream>
using namespace std;
#include <time.h>

#define DAY_IN_SEC 86400
class Date
{
protected:
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
    int year;
    int month;
    int day;


private:
    void recalculate();

public:
    Birthday(int days=0);
    void setDay(int day);
    void setMonth(int day);
    void setYear(int day);
    int getDay();
    int getMonth();
    int getYear();

    friend ostream& operator <<(ostream& os, const Birthday& d);
    friend istream& operator >>(istream& is, Birthday& d);
};


