//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_PASSAGEIRO_H
#define PROJETO1_PASSAGEIRO_H


#include <string>
#include <queue>
#include "Bilhete.h"

class Passageiro {
private:
    int idade, id;
    bool levaBagagem, checkInAutomatico;
    std::string nome;
    std::queue<Bilhete> bilhetes;
public:
    Passageiro(const std::string &nome, int idade, int id);

    bool isLevaBagagem() const;

    void setLevaBagagem(bool levaBagagem);

    bool isCheckInAutomatico() const;

    void setCheckInAutomatico(bool checkInAutomatico);

    const std::queue<Bilhete> &getBilhetes() const;

    void addBilhete(const Bilhete &bilhete);

    Bilhete frontBilhete() const;

    void popBilhete();

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    int getIdade() const;

    void setIdade(int idade);

    int getId() const;

    void setId(int id);
};


#endif //PROJETO1_PASSAGEIRO_H
