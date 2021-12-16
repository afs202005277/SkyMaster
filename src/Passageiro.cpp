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

Passageiro::Passageiro(std::string nome, int idade, int id) : nome(std::move(nome)), idade(idade), id(id) {}

const queue<Bilhete *> & Passageiro::getBilhetes() const {
    return this->bilhetes;
}

void Passageiro::addBilhete(Bilhete *bilhete) {
    this->bilhetes.push(bilhete);
}

Bilhete* Passageiro::getNextBilhete()
{
    return this->bilhetes.front();
}

void Passageiro::removeNextBilhete() {
    this->bilhetes.pop();
}

bool Passageiro::hasBilhete(int nVoo) const {
    std::queue<Bilhete *> temp = bilhetes;
    while (!temp.empty())
    {
        if (temp.front()->getNVoo() == nVoo)
        {
            return true;
        }
        temp.pop();
    }
    return false;
}


bool Passageiro::checkIn(bool checkInAutomatico, Voo &v, std::queue<Mala *> &malas) const {
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
    std::queue<Mala*> reference;
    if (!checkIn(0, v, reference))
        return false;
    v.addPassageiro(this);
    return true;
}

Passageiro::Passageiro(int idade, int id, string nome, const queue<Bilhete *> &bilhetes) : idade(idade), id(id),
                                                                                                  nome(std::move(nome)),
                                                                                                  bilhetes(bilhetes) {}


