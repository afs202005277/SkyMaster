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

const list<Passageiro *> & Voo::getPassageiros() const {
    return passageiros;
}

bool Voo::sellBilhete(bool checkInAuto, unsigned int nMalas, Passageiro *p) {
    if (this->lotacaoAtual < this->aviao->getCapacidade())
    {
        Bilhete *temp;
        temp = new Bilhete(this->nVoo, checkInAuto, nMalas, p);
        this->lotacaoAtual++;
        this->passageiros.push_back(p);
        p->addBilhete(temp);
        return true;
    }
    return false;
}

bool Voo::sellBilheteGroup(const vector<bool> &checkInAuto, const vector<unsigned int> &nMalas,
                           const vector<Passageiro *> &p) {
    unsigned int nPassageiros = checkInAuto.size();
    if (this->lotacaoAtual + nPassageiros > aviao->getCapacidade())
        return false;
    for (int i=0;i<nPassageiros;i++)
    {
        this->sellBilhete(checkInAuto[i], nMalas[i], p[i]);
        passageiros.push_back(p[i]);
    }
    return true;
}
