//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_CARRINHOTRANSPORTE_H
#define PROJETO1_CARRINHOTRANSPORTE_H


#include "Mala.h"

class CarrinhoTransporte {
private:
    int nCarruagens, nPilhas, nMalas;
    vector<vector<stack<Mala*>>> transporte;
public:
    CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas);
    int getNCarruagens() const;

    void setNCarruagens(int nCarruagens);

    int getNPilhas() const;

    void setNPilhas(int nPilhas);

    int getNMalas() const;

    void setNMalas(int nMalas);

    bool addMala(Mala *m);

    vector<Mala*> descarregarMalas();
};


#endif //PROJETO1_CARRINHOTRANSPORTE_H
