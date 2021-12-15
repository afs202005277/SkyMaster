//
// Created by andre on 12/12/2021.
//

#include "CarrinhoTransporte.h"

CarrinhoTransporte::CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas, Aviao *aviao) {
    this->nCarruagens = nCarruagens;
    this->nPilhas = nPilhas;
    this->nMalas = nMalas;
    this->carga = vector<vector<stack<Mala*>>>(this->nCarruagens);
    for (auto &temp : this->carga)
    {
        temp = vector<stack<Mala*>>(this->nPilhas);
    }
    this->aviao=aviao;
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

void CarrinhoTransporte::addMala(Mala *m) {
    for (vector<stack<Mala*>> &carruagem : this->carga)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            if (carrinho.size() < nMalas)
            {
                carrinho.push(m);
            }
        }
        if (carruagem.size() < this->nPilhas) {
            stack<Mala*> temp;
            temp.push(m);
            carruagem.push_back(temp);
        }
    }
    this->descarregarMalas();
    addMala(m);
}

void CarrinhoTransporte::descarregarMalas()
{
    for (vector<stack<Mala*>> &carruagem : this->carga)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            while (!carrinho.empty())
            {
                aviao->addMala(carrinho.top());
                carrinho.pop();
            }
        }
    }
}

const vector<vector<stack<Mala *>>> &CarrinhoTransporte::getCarga() const {
    return carga;
}

void CarrinhoTransporte::setCarga(const vector<vector<stack<Mala *>>> &carga) {
    CarrinhoTransporte::carga = carga;
}

Aviao *CarrinhoTransporte::getAviao() const {
    return aviao;
}

void CarrinhoTransporte::setAviao(Aviao *aviao) {
    CarrinhoTransporte::aviao = aviao;
}
