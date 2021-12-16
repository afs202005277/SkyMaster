#ifndef PROJETO1_TRANSPORTE_H
#define PROJETO1_TRANSPORTE_H

#include "Tempo.h"

enum TipoTransporte {autocarro, metro, comboio};

class Transporte {

private:
    int distancia;
    Tempo horaChegada, horaPartida;
    TipoTransporte tipo;
public:
    Transporte(int distancia, const Tempo &horaChegada, const Tempo &horaPartida, TipoTransporte tipo);

    TipoTransporte getTipo() const;

    void setTipo(TipoTransporte tipo);

    int getDistancia() const;

    void setDistancia(int distancia);

    const Tempo &getHoraChegada() const;

    Transporte();

    void setHoraChegada(const Tempo &horaChegada);

    const Tempo &getHoraPartida() const;

    void setHoraPartida(const Tempo &horaSaida);

    friend bool operator<(const Transporte &lhs, const Transporte &rhs);
};


#endif //PROJETO1_TRANSPORTE_H
