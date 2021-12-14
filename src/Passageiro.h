//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_PASSAGEIRO_H
#define PROJETO1_PASSAGEIRO_H


#include <string>
#include <queue>
#include "Bilhete.h"
class Bilhete;

class Passageiro {
private:
    int idade, id;
    std::string nome;
    std::queue<Bilhete *> bilhetes;
public:
    Passageiro(const std::string &nome, int idade, int id);

    void checkIn(bool checkInAutomatico, vector<Mala *> &malas, Voo &v);

    const std::queue<Bilhete *> &getBilhetes() const;

    void addBilhete(Bilhete *bilhete);

    Bilhete* frontBilhete();

    void popBilhete();

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    int getIdade() const;

    void setIdade(int idade);

    int getId() const;

    void setId(int id);

    bool hasBilhete(int nVoo);
};


#endif //PROJETO1_PASSAGEIRO_H
