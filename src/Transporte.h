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

bool operator<(const Tempo &lhs, const Tempo &rhs) {
    if (lhs.hora < rhs.hora)
        return true;
    if (lhs.hora == rhs.hora && lhs.minuto < rhs.minuto)
        return true;
    if (lhs.hora == rhs.hora && lhs.minuto == rhs.minuto && lhs.segundo < rhs.segundo)
        return true;
    return false;
}

bool operator==(const Tempo &lhs, const Tempo &rhs){
    return lhs.hora==rhs.hora && lhs.minuto == rhs.minuto && lhs.segundo==rhs.segundo;
}

bool operator<=(const Tempo &lhs, const Tempo &rhs){
    return (lhs<rhs) || lhs==rhs;
}

bool operator>=(const Tempo &lhs, const Tempo &rhs){
    return (rhs<lhs) || lhs==rhs;
}

bool operator>(const Tempo &lhs, const Tempo &rhs){
    return (rhs<lhs);
}
class Transporte {

private:
    int distancia;
public:
    Transporte();

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
