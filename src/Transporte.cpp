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

bool operator<(const Tempo &lhs, const Tempo &rhs) {
    if (lhs.hora < rhs.hora)
        return true;
    else if (lhs.hora == rhs.hora && lhs.minuto < rhs.minuto)
        return true;
    else if (lhs.hora == rhs.hora && lhs.minuto == rhs.minuto && lhs.segundo < rhs.segundo)
        return true;
    return false;
}

bool operator<(const Transporte &lhs, const Transporte &rhs) {
    if (lhs.distancia < rhs.distancia)
        return true;
    else if (lhs.distancia == rhs.distancia && lhs.horaChegada < rhs.horaChegada)
        return true;
    return false;
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
