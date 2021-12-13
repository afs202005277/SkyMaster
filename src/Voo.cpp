//
// Created by andre on 13/12/2021.
//

#include "Voo.h"

Voo::Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, int lotacaoAtual)
        : nVoo(nVoo), duracao(duracao), lotacaoAtual(lotacaoAtual), dataPartida(dataPartida), origem(origem),
          destino(destino) {}

int Voo::getNVoo() const {
    return nVoo;
}

void Voo::setNVoo(int nVoo) {
    Voo::nVoo = nVoo;
}

int Voo::getDuracao() const {
    return duracao;
}

void Voo::setDuracao(int duracao) {
    Voo::duracao = duracao;
}

int Voo::getLotacaoAtual() const {
    return lotacaoAtual;
}

void Voo::setLotacaoAtual(int lotacaoAtual) {
    Voo::lotacaoAtual = lotacaoAtual;
}

const Data &Voo::getDataPartida() const {
    return dataPartida;
}

void Voo::setDataPartida(const Data &dataPartida) {
    Voo::dataPartida = dataPartida;
}

Aeroporto *Voo::getOrigem() const {
    return origem;
}

void Voo::setOrigem(Aeroporto *origem) {
    Voo::origem = origem;
}

Aeroporto *Voo::getDestino() const {
    return destino;
}

void Voo::setDestino(Aeroporto *destino) {
    Voo::destino = destino;
}

const vector<Passageiro> &Voo::getPassageiros() const {
    return passageiros;
}

void Voo::setPassageiros(const vector<Passageiro> &passageiros) {
    Voo::passageiros = passageiros;
}

const vector<Bilhete> &Voo::getBilhetesVendidos() const {
    return bilhetes_vendidos;
}

void Voo::setBilhetesVendidos(const vector<Bilhete> &bilhetesVendidos) {
    bilhetes_vendidos = bilhetesVendidos;
}
