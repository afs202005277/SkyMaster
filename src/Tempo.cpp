#include "Tempo.h"

int Tempo::getHora() const {
    return hora;
}

void Tempo::setHora(int hora) {
    Tempo::hora = hora;
}

int Tempo::getMinuto() const {
    return minuto;
}

void Tempo::setMinuto(int minuto) {
    Tempo::minuto = minuto;
}

int Tempo::getSegundo() const {
    return segundo;
}

void Tempo::setSegundo(int segundo) {
    Tempo::segundo = segundo;
}

std::string Tempo::getTempo()
{
    return std::to_string(getHora()) + ":" + std::to_string(getMinuto()) + ":" + std::to_string(getSegundo());
}

bool operator<(const Tempo &lhs, const Tempo &rhs) {
    if (lhs.hora < rhs.hora)
        return true;
    if (lhs.hora == rhs.hora && lhs.minuto < rhs.minuto)
        return true;
    if (lhs.hora == rhs.hora && lhs.minuto == rhs.minuto && lhs.segundo < rhs.segundo)
        return true;
    return false;
}

bool operator>(const Tempo &lhs, const Tempo &rhs) {
    return rhs < lhs;
}

bool operator<=(const Tempo &lhs, const Tempo &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Tempo &lhs, const Tempo &rhs) {
    return !(lhs < rhs);
}

Tempo::Tempo(int hora, int minuto, int segundo) : hora(hora), minuto(minuto), segundo(segundo) {}

bool operator==(const Tempo &lhs, const Tempo &rhs) {
    return lhs.hora == rhs.hora &&
           lhs.minuto == rhs.minuto &&
           lhs.segundo == rhs.segundo;
}

bool operator!=(const Tempo &lhs, const Tempo &rhs) {
    return !(rhs == lhs);
}

Tempo::Tempo(const std::string &tempo) {
    hora = stoi(tempo.substr(0, tempo.find(':')));
    minuto = stoi(tempo.substr(tempo.find(':') + 1));
}

std::ostream &operator<<(std::ostream &os, const Tempo &tempo) {
    os << tempo.getHora() << ":" << tempo.getMinuto() << ":" << tempo.getSegundo() << std::endl;
    return os;
}

