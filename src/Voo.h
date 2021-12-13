//
// Created by andre on 13/12/2021.
//

#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H


#include "Data.h"
#include "Aeroporto.h"

class Voo {
private:
    int nVoo, duracao, lotacaoAtual;
    Data dataPartida;
    Aeroporto * origem;
    Aeroporto * destino;
public:
    Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, int lotacaoAtual=0);
};


#endif //PROJETO1_VOO_H
