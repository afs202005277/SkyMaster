//
// Created by andre on 12/12/2021.
//

#include "CarrinhoTransporte.h"

int CarrinhoTransporte::getNCarruagens() const {
    return nCarruagens;
}

void CarrinhoTransporte::setNCarruagens(int nCarruagens) {
    CarrinhoTransporte::nCarruagens = nCarruagens;
}

int CarrinhoTransporte::getNPilhas() const {
    return nPilhas;
}

void CarrinhoTransporte::setNPilhas(int nPilhas) {
    CarrinhoTransporte::nPilhas = nPilhas;
}

int CarrinhoTransporte::getNMalas() const {
    return nMalas;
}

void CarrinhoTransporte::setNMalas(int nMalas) {
    CarrinhoTransporte::nMalas = nMalas;
}

bool CarrinhoTransporte::addMala(Mala m) {

}
