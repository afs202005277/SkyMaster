//
// Created by andre on 12/12/2021.
//

#include "CarrinhoTransporte.h"

CarrinhoTransporte::CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas) {
    this->nCarruagens = nCarruagens;
    this->nPilhas = nPilhas;
    this->nMalas = nMalas;
    this->transporte = vector<vector<stack<Mala*>>>(this->nCarruagens);
    for (auto &temp : this->transporte)
    {
        temp = vector<stack<Mala*>>(this->nPilhas);
    }
}

int CarrinhoTransporte::getNCarruagens() const {
    return nCarruagens;
}

void CarrinhoTransporte::setNCarruagens(int nCarruagens) {
    CarrinhoTransporte::nCarruagens = nCarruagens;
}

int CarrinhoTransporte::getNPilhas() const {
    return nPilhas;
}

void CarrinhoTransporte::setNPilhas(int nPilhas) {
    CarrinhoTransporte::nPilhas = nPilhas;
}

int CarrinhoTransporte::getNMalas() const {
    return nMalas;
}

void CarrinhoTransporte::setNMalas(int nMalas) {
    CarrinhoTransporte::nMalas = nMalas;
}

bool CarrinhoTransporte::addMala(Mala *m) {
    for (vector<stack<Mala*>> &carruagem : this->transporte)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            if (carrinho.size() < nMalas)
            {
                carrinho.push(m);
                return true;
            }
        }
        if (carruagem.size() < this->nPilhas) {
            stack<Mala*> temp;
            temp.push(m);
            carruagem.push_back(temp);
            return true;
        }
    }
    return false;
}

vector<Mala *> CarrinhoTransporte::descarregarMalas()
{
    vector<Mala *> temp;
    for (vector<stack<Mala*>> &carruagem : this->transporte)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            while (!carrinho.empty())
            {
                temp.push_back(carrinho.top());
                carrinho.pop();
            }
        }
    }
    return temp;
}