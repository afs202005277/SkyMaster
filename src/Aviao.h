//
// Created by andre on 28/11/2021.
//

#ifndef PROJETO1_AVIAO_H
#define PROJETO1_AVIAO_H
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include "Data.h"
#include "Servico.h"
#include "Aeroporto.h"


struct Voo{
    int nVoo, duracao, lotacaoAtual;
    Data dataPartida;
    Aeroporto * origem;
    Aeroporto * destino;
};

class Aviao {
private:
    int capacidade;
    std::list<Voo*> plano;
    std::string matricula;
    std::queue<Servico*> servicos;
    std::stack<Servico*> pastServices;

    void sortPlano();
    static bool sorter(const Voo *v1, const Voo *v2);
public:
    // CONSTRUTORES && GETTERS && SETTERS
    Aviao(int capacidade, const std::list<Voo *> &plano, const std::string &matricula,
          const std::queue<Servico *> &servicos);

    const std::queue<Servico *> getServicos() const;

    void setServicos(const std::queue<Servico *> &servicos);

    Aviao(int capacidade, const std::list<Voo *> &plano, const std::string &matricula);

    Aviao();

    const std::string &getMatricula() const;

    void setMatricula(const std::string &matricula);

    int getCapacidade() const;

    void setCapacidade(int capacidade);

    const std::list<Voo *> & getPlano() const;

    void setPlano(std::list<Voo *> plano);

    //EXTRAS

    void addServico(Servico *servico);

    void addVoo(Voo *voo);

};


#endif //PROJETO1_AVIAO_H
