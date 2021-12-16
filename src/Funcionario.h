#ifndef PROJETO1_FUNCIONARIO_H
#define PROJETO1_FUNCIONARIO_H

#include "Aeroporto.h"
#include <string>

class Aeroporto;
class Servico;

class Funcionario {
public:

private:
    int telemovel;
    std::string nome, morada;
    Aeroporto *aeroporto;

public:
    Aeroporto *getAeroporto() const;

    void setAeroporto(Aeroporto *aeroporto);

    Funcionario(int telemovel, std::string nome, std::string morada, Aeroporto *aeroporto);

    int getTelemovel() const;

    void setTelemovel(int telemovel);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    const std::string &getMorada() const;

    void setMorada(const std::string &morada);

    friend bool operator<(const Funcionario &lhs, const Funcionario &rhs);

    friend bool operator>(const Funcionario &lhs, const Funcionario &rhs);

    friend bool operator<=(const Funcionario &lhs, const Funcionario &rhs);

    friend bool operator>=(const Funcionario &lhs, const Funcionario &rhs);

    bool operator==(const Funcionario &rhs) const;

    bool operator!=(const Funcionario &rhs) const;
};

#endif //PROJETO1_FUNCIONARIO_H
