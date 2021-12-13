//
// Created by Pedro Fonseca on 13/12/2021.
//

#include "Mala.h"

const Passageiro &Mala::getDono() const {
    return dono;
}

void Mala::setDono(const Passageiro &dono) {
    Mala::dono = dono;
}

float Mala::getPeso() const {
    return peso;
}

void Mala::setPeso(float peso) {
    Mala::peso = peso;
}
