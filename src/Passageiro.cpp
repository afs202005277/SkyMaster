//
// Created by andre on 12/12/2021.
//

#include <stack>
#include "Passageiro.h"
#include "Mala.h"

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

const std::queue<Bilhete *> &Passageiro::getBilhetes() const {
    return this->bilhetes;
}

void Passageiro::addBilhete(Bilhete *bilhete) {
    this->bilhetes.push(bilhete);
}

Bilhete* Passageiro::frontBilhete()
{
    return this->bilhetes.front();
}

void Passageiro::popBilhete()
{
    return this->bilhetes.pop();
}

bool Passageiro::hasBilhete(int nVoo) {
    std::queue<Bilhete *> temp;
    bool res = false;
    while (!this->bilhetes.empty())
    {
        if (this->bilhetes.front()->getNVoo() == nVoo)
        {
            res = true;
        }
        temp.push(this->bilhetes.front());
        this->bilhetes.pop();
    }
    this->bilhetes = temp;
    return res;
}

bool Passageiro::checkIn(bool checkInAutomatico, Voo &v, std::queue<Mala *> &malas) {
    if (!this->hasBilhete(v.getNVoo()))
       return false;
   if (!checkInAutomatico)
       return true;
    std::vector<CarrinhoTransporte *> carrinhos = v.getOrigem()->getCarrinhos();
    for (auto &c:carrinhos)
    {
        if (c->getAviao() == v.getAviao())
        {
            for (int i=0;i<malas.size();i++)
            {
                c->addMala(malas.front());
                malas.pop();
            }
        }
    }
    return true;
}

bool Passageiro::getIntoPlane(Voo &v) {
    if (!checkIn(0, v))
        return false;
    v.addPassageiro(this);
    return true;
}


