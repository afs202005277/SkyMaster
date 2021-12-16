#ifndef PROJETO1_AEROPORTO_H
#define PROJETO1_AEROPORTO_H

#include <string>
#include <vector>
#include <queue>
#include "Transporte.h"
#include "Funcionario.h"
#include "CarrinhoTransporte.h"
#include "bst.h"
#include "Aviao.h"

class Funcionario;
class CarrinhoTransporte;

class Aeroporto {
private:
    std::string name, city, country;
    std::vector<Funcionario*> funcionarios;
    BST<Transporte> transportes;
    std::vector<CarrinhoTransporte*> carrinhos;
    list<Aviao*> avioes;
    std::queue<Mala*> storage;

    static bool sorterFuncionarios(const Funcionario * f1, const Funcionario * f2);
    static bool sorterAvioes(const Aviao* a1, const Aviao* a2);

public:
    const std::string &getName() const;

    const queue<Mala *> &getStorage() const;

    void setStorage(const queue<Mala *> &storage);

    vector<CarrinhoTransporte *> & getCarrinhos();

    void setCarrinhos(const vector<CarrinhoTransporte *> &Carrinhos);

    void setName(const std::string &Name);

    const std::string &getCity() const;

    void setCity(const std::string &City);

    Aeroporto(string name, string city, string country, const vector<Funcionario *> &funcionarios,
              const BST<Transporte> &transportes, const vector<CarrinhoTransporte *> &carrinhos,
              const list<Aviao *> &avioes);

    Aeroporto(std::string name, std::string city, std::string country);

    const list<Aviao *> &getAvioes() const;

    void setAvioes(const list<Aviao *> &Avioes);

    const std::string &getCountry() const;

    void setCountry(const std::string &Country);

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

    bool removeAviao(Aviao * a);

};


#endif //PROJETO1_AEROPORTO_H
