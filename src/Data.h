//
// Created by andre on 28/11/2021.
//

#ifndef PROJETO1_DATA_H
#define PROJETO1_DATA_H


#include <ostream>
#include <iomanip>

class Data {
private:
    int day, month, year;
public:
    Data();

    bool operator<(const Data &rhs) const;

    bool operator>(const Data &rhs) const;

    bool operator<=(const Data &rhs) const;

    bool operator>=(const Data &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Data &data);

    bool operator==(const Data &rhs) const;

    bool operator!=(const Data &rhs) const;

    Data(int year, int month, int day);

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);
};


#endif //PROJETO1_DATA_H
