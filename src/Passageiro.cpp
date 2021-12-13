//
// Created by andre on 12/12/2021.
//

#include "Passageiro.h"

const std::string &Passageiro::getNome() const {
    return nome;
}

void Passageiro::setNome(const std::string &nome) {
    Passageiro::nome = nome;
}

int Passageiro::getIdade() const {
    return idade;
}

void Passageiro::setIdade(int idade) {
    Passageiro::idade = idade;
}

int Passageiro::getId() const {
    return id;
}

void Passageiro::setId(int id) {
    Passageiro::id = id;
}

bool Passageiro::isLevaBgagem() const {
    return levaBgagem;
}

void Passageiro::setLevaBgagem(bool levaBgagem) {
    Passageiro::levaBgagem = levaBgagem;
}

bool Passageiro::isCheckInAutomatico() const {
    return checkInAutomatico;
}

void Passageiro::setCheckInAutomatico(bool checkInAutomatico) {
    Passageiro::checkInAutomatico = checkInAutomatico;
}
