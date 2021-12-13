//
// Created by andre on 28/11/2021.
//

#include "Funcionario.h"

int Funcionario::getTelemovel() const {
    return telemovel;
}

void Funcionario::setTelemovel(int telemovel) {
    Funcionario::telemovel = telemovel;
}

const std::string &Funcionario::getNome() const {
    return nome;
}

void Funcionario::setNome(const std::string &nome) {
    Funcionario::nome = nome;
}

const std::string &Funcionario::getMorada() const {
    return morada;
}

void Funcionario::setMorada(const std::string &morada) {
    Funcionario::morada = morada;
}

Funcionario::Funcionario(int telemovel, const std::string &nome, const std::string &morada) : telemovel(telemovel),
                                                                                              nome(nome),
                                                                                              morada(morada) {}

Funcionario::Funcionario() {}
