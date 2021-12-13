//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_PASSAGEIRO_H
#define PROJETO1_PASSAGEIRO_H


#include <string>

class Passageiro {
private:
    std::string nome;
    int idade, id;
public:
    Passageiro(const std::string &nome, int idade, int id);

public:
    const std::string &getNome() const;

    void setNome(const std::string &nome);

    int getIdade() const;

    void setIdade(int idade);

    int getId() const;

    void setId(int id);

    bool isLevaBgagem() const;

    void setLevaBgagem(bool levaBgagem);

    bool isCheckInAutomatico() const;

    void setCheckInAutomatico(bool checkInAutomatico);

};


#endif //PROJETO1_PASSAGEIRO_H
