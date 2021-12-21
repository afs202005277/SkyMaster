#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

#include <string>
#include <stack>
#include <vector>

#include "Data.h"
#include "Funcionario.h"
#include "Terminal.h"

class Funcionario;
class Terminal;

enum Tipo {manutencao, limpeza};

class Servico : public Terminal {
private:
    Data data;
    Funcionario * funcionario;
    Tipo tipo;
public:
    Servico(const Data &data, Funcionario *funcionario, Tipo tipo);

    Servico(const std::string &data, Funcionario * funcionario, const std::string& tipo);

    Tipo getTipo() const;

    void setTipo(Tipo tipo);

    const Data &getData() const;

    void setData(const Data &data);

    const Funcionario * getFuncionario() const;

    void setFuncionario(Funcionario *funcionario);

    /**
     * Um serviço é menor que outro quando a data é menor, ou, em caso de empate, quando o nome do funcionário é menor (ordem alfabética)
     * ou, em caso de empate, quando um tipo é menor que o outro
     * @param lhs
     * @param rhs
     * @return true se o serviço lhs for menor que rhs
     */
    friend bool operator<(const Servico &lhs, const Servico &rhs);

    /**
     * Dois serviços são iguais se tiverem o mesmo valor em todos os atributos
     * @param lhs
     * @param rhs
     * @return true se forem iguais
     */
    friend bool operator==(const Servico &lhs, const Servico &rhs);

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_SERVICO_H
