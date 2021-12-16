//
// Created by andre on 12/12/2021.
//

#include <algorithm>
#include <utility>
#include "Aeroporto.h"


Aeroporto::Aeroporto(std::string name, std::string city, std::string country) : transportes(Transporte(-1, Tempo {-1, -1, -1},Tempo {-1, -1, -1}, metro)), name(std::move(name)), city(std::move(city)),
                                                                                country(std::move(country)) {}

const std::string &Aeroporto::getName() const {
    return name;
}

void Aeroporto::setName(const std::string &Name) {
    Aeroporto::name = Name;
}

const std::string &Aeroporto::getCity() const {
    return city;
}

void Aeroporto::setCity(const std::string &City) {
    Aeroporto::city = City;
}

const std::string &Aeroporto::getCountry() const {
    return country;
}

void Aeroporto::setCountry(const std::string &Country) {
    Aeroporto::country = Country;
}

void Aeroporto::setTransportes(BST<Transporte> &t) {
    transportes = t;
}

BST<Transporte> Aeroporto::getTransportes() {
    return transportes;
}

void Aeroporto::addTransporte(Transporte &t) {
    Transporte f = transportes.find(t);
    if (f.getDistancia() == -1) // Not found
    {
        transportes.insert(t);
    }
    else
    {
        transportes.remove(t);
        transportes.insert(t);
    }
}

Transporte Aeroporto::getNearestTransport() {
    return transportes.findMin();
}

vector<Transporte> Aeroporto::getAvailableTransports(Tempo min, Tempo max) {
    vector<Transporte> res;
    BSTItrIn<Transporte> it(transportes);
    while(!it.isAtEnd())
    {
        Transporte current = it.retrieve();
        if (current.getHoraChegada() >= min && current.getHoraChegada() <= max)
            res.push_back(current);
        it.advance();
    }
    return res;
}

bool Aeroporto::removeTransporte(Transporte &t) {
    return transportes.remove(t);
}

Transporte Aeroporto::getNextTransport() {
    Tempo t = {INT_MAX, INT_MAX, INT_MAX};
    Transporte res;
    BSTItrIn<Transporte> it(transportes);
    while(!it.isAtEnd())
    {
        Transporte current = it.retrieve();
        if (current.getHoraChegada() < t)
        {
            t = current.getHoraChegada();
            res = current;
        }
        it.advance();
    }
    return res;
}

void Aeroporto::addFuncionario(Funcionario *f) {
    int left = 0, right = funcionarios.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (*funcionarios[middle] < *f)
            left = middle + 1;
        else if (*f < *funcionarios[middle])
            right = middle - 1;
        else
            return;
    }
    funcionarios.insert(funcionarios.begin()+left, f);
}

Funcionario *Aeroporto::removeFuncionario(const Funcionario &f) {
    int left = 0, right = (int) funcionarios.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (*funcionarios[middle] < f)
            left = middle + 1;
        else if (f < *funcionarios[middle])
            right = middle - 1;
        else
        {
            Funcionario* tmp = funcionarios[middle];
            funcionarios.erase(funcionarios.begin() + middle);
            return tmp;
        }
    }
    return nullptr;
}

const vector<Funcionario *> &Aeroporto::getFuncionarios() const {
    return funcionarios;
}

void Aeroporto::setFuncionarios(vector<Funcionario *> &funcionariosNew) {
    sort(funcionariosNew.begin(), funcionariosNew.end(), sorterFuncionarios);
    Aeroporto::funcionarios = funcionariosNew;
}

vector<CarrinhoTransporte *> & Aeroporto::getCarrinhos() {
    return carrinhos;
}

void Aeroporto::setCarrinhos(const vector<CarrinhoTransporte *> &Carrinhos) {
    Aeroporto::carrinhos = Carrinhos;
}

bool Aeroporto::sorterFuncionarios(const Funcionario *f1, const Funcionario *f2) {
    return f1->getNome() < f2->getNome();
}

void Aeroporto::addAviao(Aviao *a) {
    for (auto it=avioes.begin();it!=avioes.end();it++)
    {
        if (a->getNextVoo() < (*next(it))->getNextVoo() && a->getNextVoo() > (*it)->getNextVoo())
            avioes.insert(it, a);
    }
    avioes.push_back(a);
    bool assigned=false;
    for (auto &c:carrinhos)
    {
        if (c->getAviao() == nullptr)
        {
            c->setAviao(a);
            a->setCarrinhoAssociado(c);
            assigned = true;
        }
    }
    if (!assigned)
    {
        CarrinhoTransporte ref = *carrinhos.front();
        auto* c = new CarrinhoTransporte(ref.getNCarruagens(), ref.getNPilhas(),ref.getNMalas(), a);
        carrinhos.push_back(c);
    }
}

bool Aeroporto::removeAviao(Aviao *a)
{
    auto t = find(avioes.begin(), avioes.end(), a);
    if (t != avioes.end())
    {
        (*t)->getCarrinhoAssociado()->setAviao(nullptr);
        avioes.erase(t);
        return true;
    }
    return false;
}

const list<Aviao *> &Aeroporto::getAvioes() const {
    return avioes;
}

void Aeroporto::setAvioes(const list<Aviao *> &Avioes) {
    Aeroporto::avioes = Avioes;
}

Aeroporto::Aeroporto(string name, string city, string country,
                     const vector<Funcionario *> &funcionarios, const BST<Transporte> &transportes,
                     const vector<CarrinhoTransporte *> &carrinhos, const list<Aviao *> &avioes) : name(std::move(name)),
                                                                                                   city(std::move(city)),
                                                                                                   country(std::move(country)),
                                                                                                   funcionarios(
                                                                                                           funcionarios),
                                                                                                   transportes(
                                                                                                           transportes),
                                                                                                   carrinhos(carrinhos),
                                                                                                   avioes(avioes) {
    this->avioes.sort(sorterAvioes);
}

bool Aeroporto::sorterAvioes(const Aviao* a1, const Aviao* a2) {
    return a1->getNextVoo() < a2->getNextVoo();
}

