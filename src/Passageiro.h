//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_PASSAGEIRO_H
#define PROJETO1_PASSAGEIRO_H

#include <string>
#include <queue>
#include <vector>

#include "Bilhete.h"
#include "Voo.h"

class Voo;
class Bilhete;
class Mala;

class Passageiro {
private:
    int idade, id;
    std::string nome;
    std::queue<Bilhete *> bilhetes;
public:
    Passageiro(std::string nome, int idade, int id);

    Passageiro(int idade, int id, std::string nome, const std::queue<Bilhete *> &bilhetes);

    const std::queue<Bilhete *> &getBilhetes() const;

    void addBilhete(Bilhete *bilhete);

    Bilhete* getNextBilhete();

    void removeNextBilhete();

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    int getIdade() const;

    void setIdade(int idade);

    int getId() const;

    void setId(int id);

    bool hasBilhete(int nVoo) const;

    bool checkIn(bool checkInAutomatico, Voo &v, std::queue<Mala *> &malas) const;

    bool getIntoPlane(Voo &v);
};


#endif //PROJETO1_PASSAGEIRO_H
