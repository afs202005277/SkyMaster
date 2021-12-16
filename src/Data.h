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

    Data(std::string data);

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    std::string getDate();

};


#endif //PROJETO1_DATA_H
