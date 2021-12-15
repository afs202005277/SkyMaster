//
// Created by Pedro Fonseca on 13/12/2021.
//

#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

#include "Passageiro.h"
class Passageiro;
class Bilhete
{
private:
    unsigned int nVoo;
    Passageiro* passageiro;
    bool levaBagagem;
public:
    Bilhete(unsigned int nVoo, bool levaBagagem, Passageiro *p);

    bool isLevaBagagem() const;

    void setNVoo(unsigned int nVoo);

    Passageiro *getPassageiro() const;

    void setPassageiro(Passageiro *passageiro);

    bool getLevaBagagem() const;

    void setLevaBagagem(bool leva);

    unsigned int getNVoo() const;
};


#endif //PROJETO1_BILHETE_H
