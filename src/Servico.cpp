//
// Created by andre on 28/11/2021.
//

#include "Servico.h"

Tipo Servico::getTipo() const {
    return tipo;
}

void Servico::setTipo(Tipo tipo) {
    Servico::tipo = tipo;
}

const Data &Servico::getData() const {
    return data;
}

void Servico::setData(const Data &data) {
    Servico::data = data;
}

const Funcionario &Servico::getFuncionario() const {
    return funcionario;
}

void Servico::setFuncionario(const Funcionario &funcionario) {
    Servico::funcionario = funcionario;
}
