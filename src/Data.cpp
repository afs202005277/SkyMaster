#include "Data.h"

int Data::getYear() const {
    return year;
}

void Data::setYear(int year) {
    Data::year = year;
}

int Data::getMonth() const {
    return month;
}

void Data::setMonth(int month) {
    Data::month = month;
}

int Data::getDay() const {
    return day;
}

void Data::setDay(int day) {
    Data::day = day;
}

Data::Data(int year, int month, int day) : year(year), month(month), day(day) {}

bool Data::operator==(const Data &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day;
}

bool Data::operator!=(const Data &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    os << std::setw(2) << std::setfill('0') << data.day << '/' << std::setw(2) << std::setfill('0') << data.month << '/' << std::setw(4) << std::setfill('0') << data.year << std::endl;
    return os;
}

Data::Data() {
    year=0;
    month=0;
    day=0;
}

bool Data::operator<(const Data &rhs) const {
    if (year < rhs.year)
        return true;
    if (year == rhs.year && month < rhs.month)
        return true;
    if (year == rhs.year && month == rhs.month && day < rhs.day)
        return true;
    return false;
}

bool Data::operator>(const Data &rhs) const {
    return rhs < *this;
}

bool Data::operator<=(const Data &rhs) const {
    return !(rhs < *this);
}

bool Data::operator>=(const Data &rhs) const {
    return !(*this < rhs);
}

std::string Data::getDate()
{
    return std::to_string(year) + "/" + std::to_string(month) + "/" + std::to_string(day);
}

Data::Data(std::string data) {
    year = stoi(data.substr(0, data.find('/')));
    month = stoi(data.substr(data.find('/') + 1, data.find_last_of('/')));
    day = stoi(data.substr(data.find_last_of('/') + 1));
}

