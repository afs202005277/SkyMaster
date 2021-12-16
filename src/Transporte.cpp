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

const Tempo &Transporte::getHoraPartida() const {
    return horaPartida;
}

void Transporte::setHoraPartida(const Tempo &horaSaida) {
    Transporte::horaPartida = horaSaida;
}

Transporte::Transporte(int distancia, const Tempo &horaChegada, const Tempo &horaPartida, TipoTransporte tipo) : distancia(distancia),
                                                                                       horaChegada(horaChegada),
                                                                                       horaPartida(horaPartida),
                                                                                       tipo(tipo) {}

bool operator<(const Transporte &lhs, const Transporte &rhs) {
    if (lhs.distancia < rhs.distancia)
        return true;
    if (lhs.distancia == rhs.distancia && lhs.horaChegada < rhs.horaChegada)
        return true;
    return false;
}

Transporte::Transporte() : horaChegada(-1, -1, -1), horaPartida (-1, -1, -1) {}
