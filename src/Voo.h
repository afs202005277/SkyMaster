//
// Created by andre on 13/12/2021.
//

#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H


#include "Data.h"
#include "Aeroporto.h"
#include "Bilhete.h"
#include "Passageiro.h"

class Voo {
private:
    int nVoo, duracao, lotacaoAtual;
    Data dataPartida;
    Aeroporto * origem;
    Aeroporto * destino;
    vector<Passageiro> passageiros;
    vector<Bilhete> bilhetes_vendidos;
public:
    Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, int lotacaoAtual=0);

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

    const vector<Passageiro> &getPassageiros() const;

    void setPassageiros(const vector<Passageiro> &passageiros);

    const vector<Bilhete> &getBilhetesVendidos() const;

    void setBilhetesVendidos(const vector<Bilhete> &bilhetesVendidos);
};


#endif //PROJETO1_VOO_H
