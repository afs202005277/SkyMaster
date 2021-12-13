//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_AEROPORTO_H
#define PROJETO1_AEROPORTO_H
#include "Transporte.h"
#include "Funcionario.h"
#include "bst.h"
#include <string>
#include <vector>
class Funcionario;

class Aeroporto {
private:
    std::string name, city, country;
    std::vector<Funcionario> funcionarios;
    BST<Transporte> transportes;
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getCity() const;

    void setCity(const std::string &city);

    const std::string &getCountry() const;

    void setCountry(const std::string &country);

    Aeroporto(std::string name, std::string city, std::string country);

    void setTransportes(BST<Transporte> &t);

    BST<Transporte> getTransportes();

    void insertTransporte(Transporte &t);

    Transporte getNearestTransport();
};


#endif //PROJETO1_AEROPORTO_H
