#ifndef PROJETO1_DATA_H
#define PROJETO1_DATA_H


#include <ostream>
#include <iomanip>
#include "Terminal.h"
class Terminal;
class Data {
private:
    int day, month, year;
public:
    /**
     * Construtor por defeito: iguala a 0 os atributos privados
     */
    Data();

    /**
     * Converte uma string no formato yyyy/mm/dd na data correspondente
     * @param data
     */
    Data(std::string data);

    Data(int year, int month, int day);

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    /**
     * Converte a data numa string
     * @return string no formato dd/mm/yyyy
     */
    std::string getDate();

    /**
     * Verifica se uma data é menor que outra
     * @param rhs
     * @return true se a data da esquerda (*this) for anterior à da direita (rhs)
     */
    bool operator<(const Data &rhs) const;

    /**
     * Verifica se uma data é maior que outra
     * @param rhs
     * @return rhs < *this
     */
    bool operator>(const Data &rhs) const;

    /**
     * Verifica se uma data é menor ou igual que outra
     * @param rhs
     * @return !(rhs < *this)
     */
    bool operator<=(const Data &rhs) const;

    /**
     * Verifica se uma data é maior ou igual que outra
     * @param rhs
     * @return !(*this < rhs)
     */
    bool operator>=(const Data &rhs) const;

    bool operator==(const Data &rhs) const;

    bool operator!=(const Data &rhs) const;

    /**
     * Imprime a data no formato dd/mm/yyyy
     * @param os
     * @param data
     * @return referencia da stream para onde enviou a data
     */
    friend std::ostream &operator<<(std::ostream &os, const Data &data);

};


#endif //PROJETO1_DATA_H
