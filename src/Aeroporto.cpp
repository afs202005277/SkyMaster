//
// Created by andre on 12/12/2021.
//

#include "Aeroporto.h"


Aeroporto::Aeroporto(std::string name, std::string city, std::string country) : transportes(Transporte(-1, Tempo {-1, -1, -1}, metro)), name(std::move(name)), city(std::move(city)),
                                                                                country(std::move(country)) {}

const std::string &Aeroporto::getName() const {
    return name;
}

void Aeroporto::setName(const std::string &name) {
    Aeroporto::name = name;
}

const std::string &Aeroporto::getCity() const {
    return city;
}

void Aeroporto::setCity(const std::string &city) {
    Aeroporto::city = city;
}

const std::string &Aeroporto::getCountry() const {
    return country;
}

void Aeroporto::setCountry(const std::string &country) {
    Aeroporto::country = country;
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

void Aeroporto::addFuncionario(Funcionario* &f) {
    funcionarios.push_back(f);
}

Funcionario *Aeroporto::removeFuncionario(const string &name) {
    for (auto it =funcionarios.begin();it!=funcionarios.end();it++)
    {
        if ((*it)->getNome() == name)
        {
            Funcionario* tmp = (*it);
            funcionarios.erase(it);
            return tmp;
        }
    }
    return nullptr;
}

