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

Passageiro::Passageiro(const std::string &nome, int idade, int id) : nome(nome), idade(idade), id(id) {}

bool Passageiro::isLevaBagagem() const {
    return levaBagagem;
}

void Passageiro::setLevaBagagem(bool levaBagagem) {
    Passageiro::levaBagagem = levaBagagem;
}

bool Passageiro::isCheckInAutomatico() const {
    return checkInAutomatico;
}

void Passageiro::setCheckInAutomatico(bool checkInAutomatico) {
    Passageiro::checkInAutomatico = checkInAutomatico;
}

const std::queue<Bilhete> &Passageiro::getBilhetes() const {
    return this->bilhetes;
}

void Passageiro::addBilhete(const Bilhete &bilhete) {
    this->bilhetes.push(bilhete);
}

Bilhete Passageiro::frontBilhete() const
{
    return this->bilhetes.front();
}

void Passageiro::popBilhete()
{
    return this->bilhetes.pop();
}
