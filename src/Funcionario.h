//
// Created by andre on 28/11/2021.
//

#ifndef PROJETO1_FUNCIONARIO_H
#define PROJETO1_FUNCIONARIO_H

#include "Aeroporto.h"
#include <string>
class Aeroporto;

class Funcionario {
public:
    bool operator==(const Funcionario &rhs) const;

    bool operator!=(const Funcionario &rhs) const;

private:
    int telemovel;
    std::string nome, morada;
    Aeroporto *aeroporto;
public:
    Funcionario();

    Aeroporto *getAeroporto() const;

    void setAeroporto(Aeroporto *aeroporto);

    Funcionario(int telemovel, const std::string &nome, const std::string &morada, Aeroporto *aeroporto);

public:
    int getTelemovel() const;

    friend bool operator<(const Funcionario &lhs, const Funcionario &rhs);

    friend bool operator>(const Funcionario &lhs, const Funcionario &rhs);

    friend bool operator<=(const Funcionario &lhs, const Funcionario &rhs);

    friend bool operator>=(const Funcionario &lhs, const Funcionario &rhs);

    void setTelemovel(int telemovel);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    const std::string &getMorada() const;

    void setMorada(const std::string &morada);
};

#endif //PROJETO1_FUNCIONARIO_H
