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

const Funcionario * Servico::getFuncionario() const {
    return funcionario;
}

void Servico::setFuncionario(Funcionario *funcionario) {
    Servico::funcionario = funcionario;
}

Servico::Servico(const Data &data, Funcionario *funcionario, Tipo tipo) : data(data), funcionario(funcionario),
                                                                          tipo(tipo) {}

Servico::Servico(const string &data, Funcionario *funcionario, const string &tipo) {
    this->data=Data(data);
    if (tipo == "manutencao")
        this->tipo=manutencao;
    else
        this->tipo=limpeza;
}

std::string Servico::getObjectName() {
    return "Servico (" + funcionario->getNome() + ", " + data.getDate() + ", " + to_string(tipo) + ")";
}
