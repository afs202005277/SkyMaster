#ifndef PROJETO1_TRANSPORTE_H
#define PROJETO1_TRANSPORTE_H

#include "Tempo.h"
#include <string>
#include "Terminal.h"

enum TipoTransporte {autocarro, metro, comboio};

class Transporte : public Terminal {

private:
    int distancia;
    Tempo horaChegada, horaPartida;
    TipoTransporte tipo;
public:
    Transporte(int distancia, const Tempo &horaChegada, const Tempo &horaPartida, TipoTransporte tipo);

    Transporte(int distancia, const std::string &horaChegada, const std::string &horaPartida, const std::string &tipo);

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

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_TRANSPORTE_H
