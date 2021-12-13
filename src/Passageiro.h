//
// Created by andre on 12/12/2021.
//

#ifndef PROJETO1_PASSAGEIRO_H
#define PROJETO1_PASSAGEIRO_H


#include <string>

class Passageiro {
private:
    std::string nome;
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

private:
    int idade, id;
    bool levaBgagem, checkInAutomatico;

};


#endif //PROJETO1_PASSAGEIRO_H
