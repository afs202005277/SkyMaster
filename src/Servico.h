#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

#include "Data.h"
#include "Funcionario.h"
#include <string>

class Funcionario;

enum Tipo {manutencao, limpeza};

class Servico {
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
};


#endif //PROJETO1_SERVICO_H
