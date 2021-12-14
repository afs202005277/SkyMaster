//
// Created by andre on 13/12/2021.
//

#include "Voo.h"

Voo::Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao, int lotacaoAtual)
        : nVoo(nVoo), duracao(duracao), lotacaoAtual(lotacaoAtual), dataPartida(dataPartida), origem(origem),
          destino(destino), aviao(aviao) {}

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

const vector<Passageiro *> &Voo::getPassageiros() const {
    return passageiros;
}

Bilhete* Voo::sellBilhete(bool checkInAuto, unsigned int nMalas) {
    Bilhete *temp = nullptr;
    if (this->lotacaoAtual < this->aviao->getCapacidade())
    {
        temp = new Bilhete(this->nVoo, checkInAuto, nMalas);
        this->lotacaoAtual++;
    }
    return temp;
}

bool Voo::addPassageiro(Passageiro *passageiro)
{
    if (passageiro->hasBilhete(nVoo))
    {
        passageiros.push_back(passageiro);
        return true;
    }
    return false;
}

vector<Bilhete*> Voo::sellBilheteGroup(const vector<bool> &checkInAuto, const vector<unsigned int> &nMalas) {
    unsigned int nPassageiros = checkInAuto.size();
    vector<Bilhete *> res(nPassageiros, nullptr);
    if (this->lotacaoAtual + nPassageiros > aviao->getCapacidade())
        return res;
    for (int i=0;i<nPassageiros;i++)
    {
        res[i] = this->sellBilhete(checkInAuto[i], nMalas[i]);
    }
    return res;
}
