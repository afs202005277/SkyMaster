//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_CARRINHOTRANSPORTE_H
#define PROJETO1_CARRINHOTRANSPORTE_H

#include <vector>
#include "Mala.h"
#include <stack>
using namespace std;
class Mala;
class Aviao;

class CarrinhoTransporte {
private:
    int nCarruagens, nPilhas, nMalas;
    std::vector<std::vector<std::stack<Mala*>>> carga;
    Aviao * aviao;
public:
    const vector<vector<stack<Mala *>>> &getCarga() const;

    void setCarga(const vector<vector<stack<Mala *>>> &carga);

    Aviao *getAviao() const;

    void setAviao(Aviao *aviao);

    CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas, Aviao *aviao=nullptr);

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
