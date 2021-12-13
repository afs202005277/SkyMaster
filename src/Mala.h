//
// Created by Pedro Fonseca on 13/12/2021.
//

#ifndef PROJETO1_MALA_H
#define PROJETO1_MALA_H


#include "Passageiro.h"
#include "Aviao.h"

class Mala {
private:
    Passageiro dono;
    Aviao *despachada;
    float peso;
public:
    const Passageiro &getDono() const;

    void setDono(const Passageiro &dono);

    float getPeso() const;

    void setPeso(float peso);
};


#endif //PROJETO1_MALA_H
