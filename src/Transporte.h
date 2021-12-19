#ifndef PROJETO1_TRANSPORTE_H
#define PROJETO1_TRANSPORTE_H

#include "Tempo.h"
#include "Terminal.h"
#include <string>


enum TipoTransporte {autocarro, metro, comboio};
class Aeroporto;
class Terminal;
class Transporte : public Terminal{

private:
    int distancia;
    Tempo horaChegada, horaPartida;
    TipoTransporte tipo;
    std::string nomeAeroporto;
public:
    Transporte(int distancia, const Tempo &horaChegada, const Tempo &horaPartida, TipoTransporte tipo,
               std::string nomeAeroporto);

    Transporte(int distancia, const std::string &horaChegada, const std::string &horaPartida, const std::string &tipo,
               std::string nomeAeroporto);

    Transporte();

    const std::string &getNomeAeroporto() const;

    void setNomeAeroporto(const std::string &nomeAeroporto);

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

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_TRANSPORTE_H
