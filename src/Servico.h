#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

#include "Data.h"
#include "Funcionario.h"
#include <string>
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

    friend bool operator<(const Servico &lhs, const Servico &rhs);

    friend bool operator==(const Servico &lhs, const Servico &rhs);

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_SERVICO_H
