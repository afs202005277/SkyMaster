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

Transporte::Transporte(int distancia, const std::string &horaChegada, const std::string &horaPartida,
                       const std::string &tipo) : distancia(distancia), horaChegada(Tempo(horaChegada)),
                                             horaPartida(Tempo(horaPartida)){
    if (tipo=="metro")
        this->tipo=metro;
    else if (tipo=="comboio")
        this->tipo=comboio;
    else
        this->tipo=autocarro;
}

std::string Transporte::getObjectName() {
    return "Transporte (" + horaChegada.getTempo() + ", " + horaPartida.getTempo() + ", " + std::to_string(distancia) + ")";
}

std::string Transporte::getObjectID() {
    return horaChegada.getTempo();
}
