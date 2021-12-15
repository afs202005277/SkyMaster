//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_TRANSPORTE_H
#define PROJETO1_TRANSPORTE_H

#include "Tempo.h"

enum TipoTransporte {autocarro, metro, comboio};

class Transporte {

private:
    int distancia;
    Tempo horaChegada;
    TipoTransporte tipo;
public:
    Transporte();

    Transporte(int distancia, const Tempo &horaChegada, TipoTransporte tipo);

    TipoTransporte getTipo() const;

    void setTipo(TipoTransporte tipo);

    int getDistancia() const;

    void setDistancia(int distancia);

    const Tempo &getHoraChegada() const;

    void setHoraChegada(const Tempo &horaChegada);

    const Tempo &getHoraSaida() const;

    void setHoraSaida(const Tempo &horaChegada);

    friend bool operator<(const Transporte &lhs, const Transporte &rhs);
};


#endif //PROJETO1_TRANSPORTE_H
