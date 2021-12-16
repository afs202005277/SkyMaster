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
