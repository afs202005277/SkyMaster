#ifndef PROJETO1_TRANSPORTE_H
#define PROJETO1_TRANSPORTE_H

#include "Tempo.h"
#include <string>

enum TipoTransporte {autocarro, metro, comboio};

class Transporte {

private:
    int distancia;
    Tempo horaChegada, horaPartida;
    TipoTransporte tipo;
public:
    Transporte(int distancia, const Tempo &horaChegada, const Tempo &horaPartida, TipoTransporte tipo);

    Transporte(int distancia, const std::string &horaChegada, const std::string &horaPartida, const std::string &tipo);

    Transporte();

    TipoTransporte getTipo() const;

    void setTipo(TipoTransporte tipo);

    int getDistancia() const;

    void setDistancia(int distancia);

    const Tempo &getHoraChegada() const;

    void setHoraChegada(const Tempo &horaChegada);

    const Tempo &getHoraPartida() const;

    void setHoraPartida(const Tempo &horaSaida);

    /**
     * Verifica se um transporte é menor que outro
     * @param lhs
     * @param rhs
     * @return true se lhs estiver mais perto do que rhs, ou, em caso de empate, se lhs chegar primeiro que rhs
     */
    friend bool operator<(const Transporte &lhs, const Transporte &rhs);
};


#endif //PROJETO1_TRANSPORTE_H
