//
// Created by andre on 13/12/2021.
//

#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H


#include "Data.h"
#include "Aeroporto.h"
#include "Bilhete.h"
#include "Passageiro.h"
#include "Aviao.h"
class Aviao;
class Bilhete;
class Passageiro;

class Voo {
private:
    int duracao, lotacaoAtual;
    unsigned int nVoo;
    Data dataPartida;
    Aeroporto * origem;
    Aeroporto * destino;
    vector<Passageiro *> passageiros;
    Aviao *aviao;
public:
    Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao, int lotacaoAtual=0);

    int getNVoo() const;

    void setNVoo(int nVoo);

    int getDuracao() const;

    void setDuracao(int duracao);

    int getLotacaoAtual() const;

    void setLotacaoAtual(int lotacaoAtual);

    const Data &getDataPartida() const;

    void setDataPartida(const Data &dataPartida);

    Aeroporto *getOrigem() const;

    void setOrigem(Aeroporto *origem);

    Aeroporto *getDestino() const;

    void setDestino(Aeroporto *destino);

    const vector<Passageiro *> &getPassageiros() const;

    Bilhete* sellBilhete(bool checkInAuto, unsigned int nMalas);

    vector<Bilhete*> sellBilheteGroup(const vector<bool> &checkInAuto, const vector<unsigned int> &nMalas);

    bool addPassageiro(Passageiro *passageiro);
};


#endif //PROJETO1_VOO_H
