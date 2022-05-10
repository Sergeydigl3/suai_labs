#include "lab13.h"

Date::Date(int days) { this->days = days; }

Date::Date() : days(0) { }

int Date::get_days() { return this->days; }

void Date::set_days(int days) { this->days = days; }

bool Date::operator == (Date& d2)
{
    return this->days == d2.days;
}
bool Date::operator != (Date& d2)
{
    return this->days != d2.days;
}
bool Date::operator > (Date& d2)
{
    return this->days > d2.days;
}
bool Date::operator < (Date& d2)
{
    return this->days < d2.days;
}
bool Date::operator >= (Date& d2)
{
    return this->days >= d2.days;
}
bool Date::operator <= (Date& d2)
{
    return this->days <= d2.days;
}

Date Date::operator+(int days) {
    return Date(this->days + days);
}

Date Date::operator+(Date d2) {
    return Date(this->days + d2.days);
}

Date& Date::operator+=(int days) {
    this->days += days;
    return *this;
}

Date& Date::operator+=(const Date& d) {
    this->days += d.days;
    return *this;
}

// префиксные операторы
Date& Date::operator++() {
    this->days += 1;
    return *this;
}
Date& Date::operator--() {
    this->days -= days;
    return *this;
}

// постфиксные операторы
Date Date::operator++(int)
{
    Date prev = *this;
    ++* this;
    return prev;
}
Date Date::operator--(int)
{
    Date prev = *this;
    --* this;
    return prev;
}

ostream& operator<< (ostream& os, const Date& d) {
    os << d.days;
    return os;
}
istream& operator >>(istream& is, Date& d) {
    is >> d.days;
    return is;
}

Birthday::Birthday(int days)
{
    this->days = days;
    this->recalculate();
}

void Birthday::recalculate(){
    time_t theTime = time(NULL) - this->days*DAY_IN_SEC;
    struct tm *aTime = localtime(&theTime);
    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900;

    this->day = day;
    this->month = month;
    this->year = year;
}

int Birthday::getDay() { return this->day; }
int Birthday::getMonth() { return this->month; }
int Birthday::getYear() { return this->year; }
void Birthday::setDay(int day) {this->day = day; }
void Birthday::setMonth(int day) {this->day = day; }
void Birthday::setYear(int day) {this->day = day; }

ostream& operator<< (ostream& os, const Birthday& d) {
    if (d.day>=10) os << d.day<< ".";
    else os << "0" <<d.day <<".";

    if (d.month>=10) os << d.month << ".";
    else os << "0" <<d.month << ".";
    os << d.year;
    return os;
}
istream& operator >>(istream& is, Birthday& d) {
    is >> d.days;
    d.recalculate();
    return is;
}