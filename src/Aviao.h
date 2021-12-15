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
#include "Voo.h"
class Servico;
class Funcionario;
using namespace std;
class Voo;
class Malas;
class Aviao {
private:
    int capacidade;
    std::list<Voo*> plano;
    std::string matricula;
    std::queue<Servico*> servicos;
    std::stack<Servico*> pastServices;
    std::vector<Malas*> carga;

    void sortPlano();
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

    bool processService();

    vector<Servico *> getPastServicesBy(const Funcionario &f) const;

    vector<Servico *> getFutureServicesBy(const Funcionario &f) const;

    vector<vector<Servico *>> getAllServicesBy(const Funcionario &f) const;

    void aterrar();
};


#endif //PROJETO1_AVIAO_H
