#include "Mala.h"

Passageiro * Mala::getDono() const {
    return dono;
}

void Mala::setDono(Passageiro* dono) {
    Mala::dono = dono;
}

float Mala::getPeso() const {
    return peso;
}

void Mala::setPeso(float peso) {
    Mala::peso = peso;
}

Aviao *Mala::getDespachada() const {
    return despachada;
}

void Mala::setDespachada(Aviao *despachada) {
    Mala::despachada = despachada;
}

Mala::Mala(Passageiro *dono, float peso, Aviao *despachada) : dono(dono), despachada(despachada), peso(peso) {}

std::string Mala::getObjectName() {
    return "Mala (" + to_string(dono->getId()) + ", " + to_string(peso) + ", " + despachada->getMatricula() + ")";
}

std::string Mala::getObjectID() {
    return to_string(dono->getId());
}

std::stack<std::string> Mala::funcs() {
    stack<string> temp;
    temp.push("setDespachada()");
    temp.push("setDono()");
    temp.push("getPeso()");
    temp.push("setPeso()");
    return temp;
}

std::vector<Terminal *> *Mala::getV(std::string nameVector) {
    vector<Terminal*> *temp;
    if (nameVector == "dono")
    {
        temp->push_back(dono);
    }
    else if (nameVector == "despachada")
    {
        temp->push_back(despachada);
    }
    return temp;
}
