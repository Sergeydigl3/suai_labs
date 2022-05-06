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