#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H

#include <list>

#include "Data.h"
#include "Aeroporto.h"
#include "Bilhete.h"
#include "Passageiro.h"
#include "Aviao.h"

using namespace std;

class Aviao;
class Bilhete;
class Passageiro;
class Aeroporto;

class Voo {
private:
    int duracao, lotacaoAtual;
    unsigned int nVoo;
    Data dataPartida;
    Tempo horaPartida;
    Aeroporto * origem;
    Aeroporto * destino;
    std::list<Passageiro *> passageiros;
    Aviao *aviao;

public:
    const Tempo &getHoraPartida() const;

    void setHoraPartida(const Tempo &horaPartida);

    Aviao *getAviao() const;

    void setAviao(Aviao *aviao);

    Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
        Tempo &partida, int lotacaoAtual = 0);

    Voo(int nVoo, int duracao, string dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
        string partida);

    int getNVoo() const;

    void setNVoo(int nVoo);

    int getDuracao() const;

    void setNVoo(unsigned int nVoo);

    void setPassageiros(const list<Passageiro *> &passageiros);

    void setDuracao(int duracao);

    int getLotacaoAtual() const;

    void setLotacaoAtual(int lotacaoAtual);

    const Data &getDataPartida() const;

    void setDataPartida(const Data &dataPartida);

    Aeroporto *getOrigem() const;

    void setOrigem(Aeroporto *origem);

    friend bool operator<(const Voo &lhs, const Voo &rhs);

    friend bool operator>(const Voo &lhs, const Voo &rhs);

    friend bool operator<=(const Voo &lhs, const Voo &rhs);

    friend bool operator>=(const Voo &lhs, const Voo &rhs);

    friend bool operator==(const Voo &lhs, const Voo &rhs);

    Aeroporto *getDestino() const;

    void setDestino(Aeroporto *destino);

    const list<Passageiro *> & getPassageiros() const;

    bool sellBilhete(bool levaBagagem, Passageiro *p);

    bool sellBilheteGroup(const vector<bool> &checkInAuto, const vector<Passageiro *> &p);

    void addPassageiro(Passageiro *p);
};


#endif //PROJETO1_VOO_H
