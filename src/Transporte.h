//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_TRANSPORTE_H
#define PROJETO1_TRANSPORTE_H

enum TipoTransporte {autocarro, metro, comboio};

typedef struct
{
    int hora;
    int minuto;
    int segundo = 0;
} Tempo;

class Transporte {

private:
    int distancia;
public:
    Transporte(int distancia, const Tempo &horaChegada, TipoTransporte tipo);

private:
    Tempo horaChegada;
    TipoTransporte tipo;
public:
    TipoTransporte getTipo() const;

    void setTipo(TipoTransporte tipo);

    int getDistancia() const;

    void setDistancia(int distancia);

    const Tempo &getHoraChegada() const;

    void setHoraChegada(const Tempo &horaChegada);

    friend bool operator<(const Transporte &lhs, const Transporte &rhs);
};


#endif //PROJETO1_TRANSPORTE_H
