//
// Created by Pedro Fonseca on 13/12/2021.
//

#include "Bilhete.h"

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
