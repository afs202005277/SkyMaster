#ifndef PROJETO1_FUNCIONARIO_H
#define PROJETO1_FUNCIONARIO_H

#include "Aeroporto.h"
#include <string>

class Aeroporto;
class Servico;

class Funcionario {
private:
    int telemovel;
    std::string nome, morada;
    Aeroporto *aeroporto;

public:
    Funcionario(int telemovel, std::string nome, std::string morada, Aeroporto *aeroporto);

    Aeroporto *getAeroporto() const;

    void setAeroporto(Aeroporto *aeroporto);

    int getTelemovel() const;

    void setTelemovel(int telemovel);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    const std::string &getMorada() const;

    void setMorada(const std::string &morada);

    /**
     * Verifica se um funcionario é menor que outro
     * @param lhs
     * @param rhs
     * @return true se o nome de lhs for menor que o de rhs (ordem alfabetica)
     */
    friend bool operator<(const Funcionario &lhs, const Funcionario &rhs);

    /**
     * Verifica se um funcionario é maior que outro
     * @param lhs
     * @param rhs
     * @return rhs < lhs
     */
    friend bool operator>(const Funcionario &lhs, const Funcionario &rhs);

    /**
     * Verifica se um funcionario é menor ou igual que outro
     * @param lhs
     * @param rhs
     * @return !(rhs < lhs)
     */
    friend bool operator<=(const Funcionario &lhs, const Funcionario &rhs);

    /**
     * Verifica se um funcionario é maior ou igual que outro
     * @param lhs
     * @param rhs
     * @return !(lhs < rhs)
     */
    friend bool operator>=(const Funcionario &lhs, const Funcionario &rhs);

    /**
     * Verifica se 2 funcionarios sao iguais
     * @param rhs
     * @return true se tiverem o mesmo numero de telemovel
     */
    bool operator==(const Funcionario &rhs) const;

    bool operator!=(const Funcionario &rhs) const;
};

#endif //PROJETO1_FUNCIONARIO_H
