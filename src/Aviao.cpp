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
    this->plano = std::move(plano);
    sortPlano();
}

Aviao::Aviao(int capacidade, std::list<Voo *> plano, std::string matricula, std::string tipo) : capacidade(capacidade),
                                                                                                plano(std::move(plano)),
                                                                                                matricula(std::move(matricula)),
                                                                                                carrinhoAssociado(nullptr),
                                                                                                tipo(tipo)
                                                                                            {sortPlano();}

std::queue<Servico *> Aviao::getServicos() const {
    return servicos;
}

void Aviao::setServicos(const std::queue<Servico *> &servicos) {
    this->servicos = servicos;
}

Aviao::Aviao(int capacidade, std::list<Voo *> plano, std::string matricula, std::queue<Servico *> servicos,
             std::string tipo) : capacidade(capacidade), plano(std::move(plano)), matricula(std::move(matricula)),
                                                      servicos(std::move(servicos)), tipo(tipo) {sortPlano();}

void Aviao::addServico(Servico *servico) {
    servicos.push(servico);
}

void Aviao::addToPlanoVoo(Voo *voo) {
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
        if (*(aux_past.top()->getFuncionario()) == f)
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
        if (*(aux_future.front()->getFuncionario()) == f)
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

void Aviao::descarregarMalas(CarrinhoTransporte *carrinho) {
    for (auto &m:carga)
    {
        bool flag = carrinho->addMala(m);
        if (!flag)
        {
            carrinho->descarregarMalasAeroporto();
            carrinho->addMala(m);
        }
    }
    carga.clear();
}

void Aviao::addMala(Mala* m) {
    carga.push_back(m);
}

void Aviao::addMalas(vector<Mala *> malas) {
    for (auto mala : malas)
    {
        addMala(mala);
    }
}

bool Aviao::removeFromPlanoVoo(Voo &voo) {
    if (find(plano.begin(), plano.end(), &voo) != plano.end())
    {
        plano.remove(reinterpret_cast<Voo *const &>(voo));
        return true;
    }
    return false;
}

void Aviao::viajar()
{
    carrinhoAssociado->descarregarMalasAviao();
    carrinhoAssociado->setAviao(nullptr);
    this->plano.front()->getDestino()->addAviao(this);
    this->plano.front()->getOrigem()->removeAviao(this);
    this->plano.erase(plano.begin());
}

const stack<Servico *> &Aviao::getPastServices() const {
    return pastServices;
}

void Aviao::setPastServices(const stack<Servico *> &pastServices) {
    Aviao::pastServices = pastServices;
}

const vector<Mala *> &Aviao::getCarga() const {
    return carga;
}

void Aviao::setCarga(const vector<Mala *> &carga) {
    Aviao::carga = carga;
}

CarrinhoTransporte *Aviao::getCarrinhoAssociado() const {
    return carrinhoAssociado;
}

void Aviao::setCarrinhoAssociado(CarrinhoTransporte *carrinhoAssociado) {
    Aviao::carrinhoAssociado = carrinhoAssociado;
}

Aviao::Aviao(int capacidade, const list<Voo *> &plano, const string &matricula, const queue<Servico *> &servicos,
             const stack<Servico *> &pastServices, const vector<Mala *> &carga, CarrinhoTransporte *carrinhoAssociado,
             std::string tipo)
        : capacidade(capacidade), plano(plano), matricula(matricula), servicos(servicos), pastServices(pastServices),
          carga(carga), carrinhoAssociado(carrinhoAssociado), tipo(tipo) {}

Voo Aviao::getNextVoo() const {
    auto it=plano.begin();
    return *(*next(it));
}

Aviao::Aviao(int capacidade, std::string matricula, std::string tipo) : capacidade(capacidade), matricula(matricula), tipo(tipo){}

bool operator==(const Aviao &lhs, const Aviao &rhs) {
    return lhs.matricula == rhs.matricula;
}

const string &Aviao::getTipo() const {
    return tipo;
}

void Aviao::setTipo(const string &tipo) {
    Aviao::tipo = tipo;
}

std::string Aviao::getObjectName() {
    return "Aviao (" + matricula + ", " + to_string(capacidade) + ", " + tipo + ")";
}

std::string Aviao::getObjectID() {
    return matricula;
}

