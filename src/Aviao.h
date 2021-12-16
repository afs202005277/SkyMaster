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
#include "Mala.h"
#include "CarrinhoTransporte.h"
#include "Terminal.h"

using namespace std;

class CarrinhoTransporte;
class Mala;
class Servico;
class Funcionario;
class Voo;

class Aviao : public Terminal {
private:
    int capacidade;
    std::list<Voo*> plano;
    std::string matricula, tipo;
    std::queue<Servico*> servicos;
    std::stack<Servico*> pastServices;
    std::vector<Mala*> carga;
    CarrinhoTransporte *carrinhoAssociado;

    void sortPlano();
public:
    Voo getNextVoo() const;

    Aviao(int capacidade, const list<Voo *> &plano, const string &matricula, const queue<Servico *> &servicos,
          const stack<Servico *> &pastServices, const vector<Mala *> &carga, CarrinhoTransporte *carrinhoAssociado,
          std::string tipo);

    Aviao(int capacidade, std::list<Voo *> plano, std::string matricula, std::queue<Servico *> servicos,
          std::string tipo);

    Aviao(int capacidade, std::string matricula, std::string tipo);

    const stack<Servico *> &getPastServices() const;

    void setPastServices(const stack<Servico *> &pastServices);

    const vector<Mala *> &getCarga() const;

    friend bool operator==(const Aviao &lhs, const Aviao &rhs);

    void setCarga(const vector<Mala *> &carga);

    CarrinhoTransporte *getCarrinhoAssociado() const;

    const string &getTipo() const;

    void setTipo(const string &tipo);

    void setCarrinhoAssociado(CarrinhoTransporte *carrinhoAssociado);

    // CONSTRUTORES && GETTERS && SETTERS

    std::queue<Servico *> getServicos() const;

    void setServicos(const std::queue<Servico *> &servicos);

    Aviao(int capacidade, std::list<Voo *> plano, std::string matricula, std::string tipo);

    const std::string &getMatricula() const;

    void setMatricula(const std::string &matricula);

    int getCapacidade() const;

    void setCapacidade(int capacidade);

    const std::list<Voo *> & getPlano() const;

    void setPlano(std::list<Voo *> plano);

    //EXTRAS

    void addServico(Servico *servico);

    void addToPlanoVoo(Voo *voo);

    bool processService();

    vector<Servico *> getPastServicesBy(const Funcionario &f) const;

    vector<Servico *> getFutureServicesBy(const Funcionario &f) const;

    vector<vector<Servico *>> getAllServicesBy(const Funcionario &f) const;

    void descarregarMalas(CarrinhoTransporte *carrinho);

    void addMala(Mala *m);

    void addMalas(vector<Mala*> malas);

    bool removeFromPlanoVoo(Voo &voo);

    void viajar();

    bool operator==(Aviao &a);

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_AVIAO_H
