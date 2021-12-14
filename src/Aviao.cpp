//
// Created by andre on 28/11/2021.
//

#include "Aviao.h"

const std::string &Aviao::getMatricula() const {
    return matricula;
}

void Aviao::setMatricula(const std::string &matricula) {
    Aviao::matricula = matricula;
}

int Aviao::getCapacidade() const {
    return capacidade;
}

void Aviao::setCapacidade(int capacidade) {
    Aviao::capacidade = capacidade;
}

const std::list<Voo *> & Aviao::getPlano() const {
    return plano;
}

void Aviao::setPlano(std::list<Voo *> plano) {
    this->plano = plano;
    sortPlano();
}

Aviao::Aviao(int capacidade, const std::list<Voo *> &plano, const std::string &matricula) : capacidade(capacidade),
                                                                                            plano(plano),
                                                                                            matricula(matricula) {sortPlano();}

Aviao::Aviao() {capacidade=0;}

const std::queue<Servico *> Aviao::getServicos() const {
    return servicos;
}

void Aviao::setServicos(const std::queue<Servico *> &servicos) {
    this->servicos = servicos;
}

Aviao::Aviao(int capacidade, const std::list<Voo *> &plano, const std::string &matricula,
             const std::queue<Servico *> &servicos) : capacidade(capacidade), plano(plano), matricula(matricula),
                                                      servicos(servicos) {sortPlano();}

void Aviao::addServico(Servico *servico) {
    servicos.push(servico);
}

void Aviao::addVoo(Voo *voo) {
    plano.push_back(voo);
}

void Aviao::sortPlano() {
    plano.sort();
}

bool Aviao::processService() {
    if (servicos.empty())
        return false;
    pastServices.push(servicos.front());
    servicos.pop();
    return true;
}

vector<Servico *> Aviao::getPastServicesBy(const Funcionario &f) const {
    vector<Servico *> res;
    stack<Servico*> aux_past = pastServices;
    while(!aux_past.empty())
    {
        if (aux_past.top()->getFuncionario() == f)
        {
            res.push_back(aux_past.top());
        }
        aux_past.pop();
    }
    return res;
}

vector<Servico *> Aviao::getFutureServicesBy(const Funcionario &f) const {
    vector<Servico *> res;
    queue<Servico*> aux_future = servicos;
    while(!aux_future.empty())
    {
        if (aux_future.front()->getFuncionario() == f)
            res.push_back(aux_future.front());
        aux_future.pop();
    }
    return res;
}


vector<vector<Servico*>> Aviao::getAllServicesBy(const Funcionario &f) const{
    vector<vector<Servico*>> res(2);
    res[0] = getPastServicesBy(f);
    res[1] = getFutureServicesBy(f);
    return res;
}

