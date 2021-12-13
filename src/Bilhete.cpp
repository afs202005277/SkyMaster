//
// Created by Pedro Fonseca on 13/12/2021.
//

#include "Bilhete.h"

Bilhete::Bilhete(unsigned int nVoo, bool checkInAuto, unsigned int numMalas) : nVoo(nVoo), checkInAuto(checkInAuto), numMalas(numMalas) {}

unsigned int Bilhete::getNumMalas() const {
    return numMalas;
}

void Bilhete::setNumMalas(unsigned int numMalas) {
    Bilhete::numMalas = numMalas;
}

bool Bilhete::isCheckInAuto() const {
    return checkInAuto;
}

void Bilhete::setCheckInAuto(bool checkInAuto) {
    Bilhete::checkInAuto = checkInAuto;
}

unsigned int Bilhete::getNVoo() const {
    return nVoo;
}
