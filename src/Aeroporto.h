//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_AEROPORTO_H
#define PROJETO1_AEROPORTO_H
#include "Transporte.h"
#include "Funcionario.h"
#include "CarrinhoTransporte.h"
#include "bst.h"
#include "Aviao.h"
#include <string>
#include <vector>
class Funcionario;
class CarrinhoTransporte;
class Aeroporto {
private:
    std::string name, city, country;
    std::vector<Funcionario*> funcionarios;
    BST<Transporte> transportes;
    std::vector<CarrinhoTransporte*> carrinhos;
    static bool sorterFuncionarios(const Funcionario * f1, const Funcionario * f2);
    list<Aviao*> avioes; //LISTA ORDENADA

public:
    const std::string &getName() const;

    vector<CarrinhoTransporte *> & getCarrinhos();

    void setCarrinhos(const vector<CarrinhoTransporte *> &carrinhos);

    void setName(const std::string &name);

    const std::string &getCity() const;

    void setCity(const std::string &city);

    const std::string &getCountry() const;

    void setCountry(const std::string &country);

    Aeroporto(std::string name, std::string city, std::string country);

    void setTransportes(BST<Transporte> &t);

    const vector<Funcionario *> &getFuncionarios() const;

    void setFuncionarios(vector<Funcionario *> &funcionariosNew);

    BST<Transporte> getTransportes();

    void addTransporte(Transporte &t);

    bool removeTransporte(Transporte &t);

    Transporte getNearestTransport();

    Transporte getNextTransport();

    vector<Transporte> getAvailableTransports(Tempo min, Tempo max);

    void addFuncionario(Funcionario *f);

    Funcionario* removeFuncionario(const Funcionario &f);

    void addAviao(Aviao * a);

};


#endif //PROJETO1_AEROPORTO_H
