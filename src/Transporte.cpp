//
// Created by andre on 12/12/2021.
//

#include "Transporte.h"

TipoTransporte Transporte::getTipo() const {
    return tipo;
}

void Transporte::setTipo(TipoTransporte tipo) {
    Transporte::tipo = tipo;
}

int Transporte::getDistancia() const {
    return distancia;
}

void Transporte::setDistancia(int distancia) {
    Transporte::distancia = distancia;
}

const Tempo &Transporte::getHoraChegada() const {
    return horaChegada;
}

void Transporte::setHoraChegada(const Tempo &horaChegada) {
    Transporte::horaChegada = horaChegada;
}

Transporte::Transporte(int distancia, const Tempo &horaChegada, TipoTransporte tipo) : distancia(distancia),
                                                                                       horaChegada(horaChegada),
                                                                                       tipo(tipo) {}
