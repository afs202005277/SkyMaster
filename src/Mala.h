#ifndef PROJETO1_MALA_H
#define PROJETO1_MALA_H

#include "Passageiro.h"
#include "Aviao.h"

class Passageiro;

class Mala {
private:
    Passageiro* dono;

    /**
     * Aviao em que a mala se encontra
     */
    Aviao *despachada;
    float peso;
public:
    Mala(Passageiro *dono, float peso, Aviao *despachada = nullptr);

    Aviao *getDespachada() const;

    void setDespachada(Aviao *despachada);

    Passageiro * getDono() const;

    void setDono(Passageiro* dono);

    float getPeso() const;

    void setPeso(float peso);
};


#endif //PROJETO1_MALA_H
