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
    servicosProcessados.push(servicos.front());
    servicos.pop();
    return true;
}

vector<Servico *> Aviao::getPastServicesBy(const Funcionario &f) const {
    vector<Servico *> res;
    stack<Servico*> aux_past = servicosProcessados;
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
        Servico *current = aux_future.front();
        Funcionario current_f = *current->getFuncionario();
        if (current_f == f)
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

void Aviao::descarregarMalas() {

    for (auto &m:carga)
    {
        bool flag = carrinhoAssociado->addMala(m);
        if (!flag)
        {
            carrinhoAssociado->descarregarMalasAeroporto();
            carrinhoAssociado->addMala(m);
        }
    }
    carrinhoAssociado->descarregarMalasAeroporto();
    carga.clear();
}

void Aviao::addMala(Mala* m) {
    carga.push_back(m);
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
    if (!plano.empty())
    {
        carrinhoAssociado->descarregarMalasAviao();
        carrinhoAssociado->setAviao(nullptr);
        this->carrinhoAssociado = nullptr;
        this->plano.front()->getDestino()->addAviao(this);
        this->plano.front()->getOrigem()->removeAviao(this);
        this->plano.erase(plano.begin());
    }
}

const stack<Servico *> &Aviao::getServicosProcessados() const {
    return servicosProcessados;
}

void Aviao::setServicosProcessados(const stack<Servico *> &pastServices) {
    Aviao::servicosProcessados = pastServices;
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
    if (carrinhoAssociado->getAviao() == nullptr)
        Aviao::carrinhoAssociado = carrinhoAssociado;
    else
    {
        carrinhoAssociado->descarregarMalasAviao();
        Aviao::carrinhoAssociado = carrinhoAssociado;
    }
}

Aviao::Aviao(int capacidade, const list<Voo *> &plano, const string &matricula, const queue<Servico *> &servicos,
             const stack<Servico *> &pastServices, const vector<Mala *> &carga, CarrinhoTransporte *carrinhoAssociado,
             std::string tipo)
        : capacidade(capacidade), plano(plano), matricula(matricula), servicos(servicos), servicosProcessados(pastServices),
          carga(carga), carrinhoAssociado(carrinhoAssociado), tipo(tipo) {}

Voo& Aviao::getNextVoo() const {
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
    return "Aviao (" + to_string(capacidade) + ", " + matricula + ", " + tipo + ")";
}

std::string Aviao::getObjectID() {
    return matricula;
}

bool operator<(const Aviao &lhs, const Aviao &rhs) {
    return lhs.matricula < rhs.matricula;
}

std::stack<std::string> Aviao::funcs() {
    stack<string> temp;
    temp.push("getTipo()");
    temp.push("setTipo()");
    temp.push("setCarrinhoAssociado()");
    temp.push("getMatricula()");
    temp.push("setMatricula()");
    temp.push("getCapacidade()");
    temp.push("setCapacidade()");
    temp.push("addServico()");
    temp.push("addToPlanoVoo()");
    temp.push("removeFromPlanoVoo()");
    temp.push("processService()");
    temp.push("getPastServicesBy()");
    temp.push("getFutureServicesBy()");
    temp.push("getAllServicesBy()");
    temp.push("descarregarMalas()");
    temp.push("viajar()");
    return temp;
}

bool Aviao::operator==(Aviao &a) {
    return this->matricula == a.matricula;
}

bool Aviao::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "getTipo")
        cout << getTipo() << endl;
    else if (nomeFunc == "setTipo")
    {
        cout << "input tipo: ";
        string temp;
        getline(cin, temp);
        try
        {
            setTipo(temp);
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "setCarrinhoAssociado")
    {
        cout << "input carrinho (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < plano.front()->getOrigem()->getCarrinhos().size()) {
                auto temp3 = plano.front()->getOrigem()->getCarrinhos();
                setCarrinhoAssociado(temp3[stoi(temp1)]);
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getMatricula")
        cout << getMatricula() << endl;
    else if (nomeFunc == "setMatricula")
    {
        cout << "input matricula (6 digitos): ";
        string temp;
        getline(cin, temp);
        if (temp.size() == 6)
        {
            setMatricula(temp);
        }
        else
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getCapacidade")
        cout << getCapacidade() << endl;
    else if (nomeFunc == "setCapacidade")
    {
        cout << "input capacidade: ";
        string temp;
        getline(cin, temp);
        try
        {
            setCapacidade(stoi(temp));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "addServico")
    {
        cout << "input data (YYYY/MM/DD): ";
        string temp1;
        getline(cin, temp1);
        cout << "input funcionario (index): ";
        string temp2;
        getline(cin, temp2);
        cout << "input tipo (limpeza/manuntencao): ";
        string temp3;
        getline(cin, temp3);
        try
        {
            if (!plano.empty() && stoi(temp2) < plano.front()->getOrigem()->getFuncionarios().size())
            {
                addServico(new Servico(temp1, plano.front()->getOrigem()->getFuncionarios()[stoi(temp2)], temp3));
                Terminal::updateVec();
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "addToPlanoVoo")
    {
        cout << "input nVoo: ";
        string temp1;
        getline(cin, temp1);
        cout << "input duracao: ";
        string temp2;
        getline(cin, temp2);
        cout << "input data (YYYY/MM/DD): ";
        string temp3;
        getline(cin, temp3);
        cout << "input aeroporto destino (index): ";
        string temp5;
        getline(cin, temp5);
        cout << "input hora partida (HH:MM): ";
        string temp6;
        getline(cin, temp6);
        try
        {
            if (stoi(temp5) << Terminal::aeroportos.size())
            {
                new Voo(stoi(temp1), stoi(temp2), temp3, plano.front()->getOrigem(), Terminal::aeroportos[stoi(temp5)], this, temp6);
                Terminal::updateVec();
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "removeFromPlanoVoo")
    {
        cout << "input voo (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < plano.size())
            {
                auto temp2 = plano.begin();
                advance(temp2, stoi(temp1));
                plano.erase(temp2);
                Terminal::updateVec();
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "processService")
    {
        cout << (processService() ? "Done." : "Not done.") << endl;
        Terminal::updateVec();
    }
    else if (nomeFunc == "getPastServicesBy")
    {
        cout << "input funcionario (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < Terminal::funcionarios.size())
            {
                auto temp2 = getPastServicesBy(*Terminal::funcionarios[stoi(temp1)]);
                for (auto temp3 : temp2)
                {
                    cout << temp3->getObjectName() << endl;
                }
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getFutureServicesBy")
    {
        cout << "input funcionario (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < Terminal::funcionarios.size()) {
                auto temp2 = getFutureServicesBy(*Terminal::funcionarios[stoi(temp1)]);
                for (auto temp3: temp2) {
                    cout << temp3->getObjectName() << endl;
                }
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getAllServicesBy")
    {
        cout << "input funcionario (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < Terminal::funcionarios.size()) {
                auto temp2 = getAllServicesBy(*Terminal::funcionarios[stoi(temp1)]);
                for (auto temp3: temp2[0]) {
                    cout << temp3->getObjectName() << endl;
                }
                for (auto temp3: temp2[1]) {
                    cout << temp3->getObjectName() << endl;
                }
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "descarregarMalas")
    {
        if (carrinhoAssociado != nullptr)
        {
            descarregarMalas();
            Terminal::updateVec();
            cout << "Done." << endl;
        }
        else
        {
            cout << "No transport car." << endl;
        }
    }
    else if (nomeFunc == "viajar")
    {
        viajar();
        Terminal::updateVec();
    }
    else
    {
        return false;
    }
    return true;
}

std::vector<Terminal *> *Aviao::getV(std::string nameVector) {
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "plano")
    {
        for (auto p : plano)
        {
            temp->push_back(p);
        }
    }
    else if (nameVector == "servicos")
    {
        auto temp2 = getServicos();
        while (!temp2.empty())
        {
            temp->push_back(temp2.front());
            temp2.pop();
        }
    }
    else if (nameVector == "pastServices")
    {
        auto temp2 = getServicosProcessados();
        while (!temp2.empty())
        {
            temp->push_back(temp2.top());
            temp2.pop();
        }
    }
    else if (nameVector == "carga")
    {
        for (auto m : carga)
        {
            temp->push_back(m);
        }
    }
    else if (nameVector == "carrinhoAssociado")
    {
        temp->push_back(carrinhoAssociado);
    }
    return temp;
}

