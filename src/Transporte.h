//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_TRANSPORTE_H
#define PROJETO1_TRANSPORTE_H

enum TipoTransporte {autocarro, metro, comboio};

struct Tempo
{
    int hora;
    int minuto;
    int segundo = 0;
};

class Transporte {

private:
    int distancia;
    Tempo horaChegada;
    TipoTransporte tipo;
public:
    TipoTransporte getTipo() const;

    void setTipo(TipoTransporte tipo);

    int getDistancia() const;

    void setDistancia(int distancia);

    const Tempo &getHoraChegada() const;

    void setHoraChegada(const Tempo &horaChegada);
};


#endif //PROJETO1_TRANSPORTE_H
